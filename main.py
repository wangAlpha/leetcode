# -*- coding: utf-8 -*-
# /usr/bin/env python3


import json
import os
import time

import requests

# from ProblemList import GetProblemId
from problem_list import PROBLEM_ID


_, algorithm_files, _ = next(os.walk('./algorithms'))
EXISTED = set()
for name in algorithm_files:
    no = name[:4]
    if no[0].isdigit():
        EXISTED.add(str(int(no)))
# visited = set([(name[:4]) for name in algorithm_files])
# print('visited: {}'.format(visited))
# ~~~~~~~~~~~~以下是无需修改的参数~~~~~~~~~~~~~~~~·
# 为了避免弹出一万个warning，which is caused by 非验证的get请求
requests.packages.urllib3.disable_warnings()


ALL_PROBLEM_API = "https://leetcode-cn.com/api/problems/all"
SIGN_IN_URL = 'https://leetcode-cn.com/accounts/login/'
SUMBISSION_API = "https://leetcode-cn.com/api/submissions/?offset={}&limit=20&lastkey={}"

CONFIG_PATH = "./config.json"

HEADERS = {
    'Connection': 'keep-alive',
    'Content-Type': 'application/json',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.152 Safari/537.36'
}


with open(CONFIG_PATH, "r") as f:  # 读取用户名，密码，本地存储目录
    config = json.loads(f.read())
    USERNAME = config['username']
    PASSWORD = config['password']
    OUTPUT_DIR = config['outputDir']
    TIME_CONTROL = 3600 * 24 * config['time']

FILE_FORMAT = {"C++": ".cpp", "Python3": ".py", "Python": ".py", "MySQL": ".sql", "Go": ".go", "Java": ".java",
               "C": ".c", "JavaScript": ".js", "PHP": ".php", "C#": ".cs", "Ruby": ".rb", "Swift": ".swift",
               "Scala": ".scl", "Kotlin": ".kt", "Rust": ".rs", 'MS SQL Server': '.sql'}

START_PAGE = 0  # 从哪一页submission开始爬起，0是最新的一页
SLEEP_TIME = 5  # in second，登录失败时的休眠时间


class LeetCode:
    def __init__(self):
        self.session = requests.session()
        self.session.encoding = "utf-8"
        self.problem_ids = {}

    def login(self, username, password):
        login_data = {'login': username, 'password': password}
        ok = False
        while not ok:
            try:
                self.session.get(SIGN_IN_URL, verify=False)
                result = self.session.post(SIGN_IN_URL, data=login_data,
                                           headers=dict(Referer=SIGN_IN_URL))
                ok = result.ok
            except Exception as e:
                print("Login failed! Wait till next round!{}".format(e))
                time.sleep(SLEEP_TIME)

    def crawl_ac_problem(self):
        response = self.session.get(ALL_PROBLEM_API, verify=False)
        if response.ok:
            result = json.loads(response.text)
        submissions = {}
        # print(result['stat_status_pairs'][0])
        for record in result['stat_status_pairs']:
            if record['status']:
                stat = record['stat']
                qid = stat['question_id']
                # if qid < 2000:
                submissions[qid] = {
                    'slug': stat['question__title_slug'],
                    'title': stat['question__title']
                }
        # print(submissions)
        return submissions

    def get_question_details(self, question_slug: str) -> dict:
        body = {"operationName": "submissions",
                'variables': {
                    "offset": 0,
                    "limit": 40,
                    "questionSlug": question_slug,
                },
                "query": "query submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!, $markedOnly: Boolean, $lang: String) {\n  submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug, markedOnly: $markedOnly, lang: $lang) {\n    lastKey\n    hasNext\n    submissions {\n      id\n      statusDisplay\n      lang\n      runtime\n      timestamp\n      url\n      isPending\n      memory\n      submissionComment {\n        comment\n        flagType\n        __typename\n      }\n      __typename\n    }\n    __typename\n  }\n}\n"}
        return body

    def user_info(self):
        url = "https://leetcode-cn.com/graphql"
        submissions = self.crawl_ac_problem()
        title = list(submissions.values())[100]['slug']
        print('title: {}'.format(title))
        body = self.get_question_details(title)
        print('body :{}'.format(body))
        # HEADERS['cookie'] = self.session.cookies.add_cookie_header(request)
        r_json = requests.post(url=url, headers=HEADERS, json=body).json()
        print('respone: {}'.format(r_json))

    def scraping(self,):
        page_num = START_PAGE
        visited = set()
        submissions = self.crawl_ac_problem()
        has_next = True
        last_key = ''
        while has_next:
            print("Now for page:", str(page_num))
            api = SUMBISSION_API.format(page_num, last_key)

            html = self.session.get(api, verify=False)
            html = json.loads(html.text)
            print(html)
            has_next = html.get('has_next', False)
            last_key = html.get('last_key', '')

            for submission in html.get("submissions_dump", []):
                submission_status = submission['status_display']
                title = submission['title'].replace(" ", "")
                lang = submission['lang']

                if submission_status != "Accepted":
                    continue

                # pid = GetProblemId(title)
                pid = PROBLEM_ID.get(title, False)
                if pid and pid + lang not in visited:
                    # 保障每道题只记录每种语言最新的AC解
                    print('problem id :{}'.format(pid))
                    if submissions.get(pid, False):
                        title = submissions[pid][0]
                    if pid in EXISTED:
                        continue

                    # visited.add(pid + lang)
                    full_path = self.generate_path(pid, title, lang)
                    qid = submission['id']
                    self.download_code(qid, full_path)

            time.sleep(0.2)
            page_num += 20

    def push_to_github():
        today = time.strftime('%Y-%m-%d', time.localtime(time.time()))
        os.chdir(OUTPUT_DIR)
        instructions = ["git add .", "git status",
                        "git commit -m \"{}\"".format(today),
                        "git push -u origin master"]
        for ins in instructions:
            os.system(ins)
            print("~~~~~~~~~~~~~" + ins + " finished! ~~~~~~~~")

    #  def query_by_id(self, title):
    #      pass
    def download_code(self, qid, full_path):

        param = {'operationName': "mySubmissionDetail", "variables": {"id": qid},
                 'query': "query mySubmissionDetail($id: ID\u0021) {  submissionDetail(submissionId: $id) {    id    code    runtime    memory    statusDisplay    timestamp    lang    passedTestCaseCnt    totalTestCaseCnt    sourceUrl    question {      titleSlug      title      translatedTitle      questionId      __typename    }    ... on GeneralSubmissionNode {      outputDetail {        codeOutput        expectedOutput        input        compileError        runtimeError        lastTestcase        __typename      }      __typename    }    __typename  }}"
                 }
        print('qid: {}'.format(qid))
        param_json = json.dumps(param).encode("utf-8")
        response = self.session.post("https://leetcode-cn.com/graphql/",
                                     data=param_json, headers=HEADERS)
        data = response.json()['data']["submissionDetail"]
        if data:
            code = data.get('code', '')
            with open(full_path, "w") as f:  # 开始写到本地
                f.write(code)

    def generate_path(self, pid, title, lang):

        title = title.replace('-', '_')
        title = title.replace(' ', '_')
        if pid[0].isdigit():
            pid = int(pid)
            newpath = OUTPUT_DIR + '/{:0=4}.{}'.format(pid, title)
            filename = '{}{}'.format(title, FILE_FORMAT[lang])
        else:
            # 如果题目是新的面试题
            newpath = OUTPUT_DIR + "/{}.{}".format(pid, title)
            filename = '{}{}'.format(title, FILE_FORMAT[lang])

        if not os.path.exists(newpath):
            os.mkdir(newpath)

        return os.path.join(newpath, filename)


if __name__ == '__main__':
    leetcode = LeetCode()
    leetcode.login(USERNAME, PASSWORD)
    # leetcode.user_info()
    print('Start scrapping')
    leetcode.scraping()
    print('End scrapping')
