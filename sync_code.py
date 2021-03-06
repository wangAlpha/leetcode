# -*- coding: utf-8 -*-
# /usr/bin/env python3


import json
import os
import time

import requests

_, algorithm_files, _ = next(os.walk('./algorithms'))
EXISTED = set()
for name in algorithm_files:
    title = name.split('.')[-1]
    EXISTED.add(title)

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
    DB_DIR = config['dbDir']
    SHELL_DIR = config['shellDir']
    TIME_CONTROL = config['time']

FILE_FORMAT = {"C++": ".cpp", "Python3": ".py", "Python": ".py", "MySQL": ".sql", "Go": ".go", "Java": ".java",
               "C": ".c", "Cpp": ".cpp", "JavaScript": ".js", "PHP": ".php", "C#": ".cs", "Ruby": ".rb",
               "Swift": ".swift", "Scala": ".scl", "Kotlin": ".kt", "Rust": ".rs", 'MS SQL Server': '.sql', 'Bash': '.sh'}
[FILE_FORMAT.update({t.lower(): s}) for t, s in list(FILE_FORMAT.items())]

START_PAGE = 0  # 从哪一页submission开始爬起，0是最新的一页
SLEEP_TIME = 5  # in second，登录失败时的休眠时间


class LeetCode:
    def __init__(self):
        self.session = requests.session()
        self.session.encoding = "utf-8"
        self.problem_ids = {}
        self.submission = {}

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

    def get_problem_by_slug(self, slug):
        url = "https://leetcode.com/graphql"
        params = {'operationName': "getQuestionDetail",
                  'variables': {'titleSlug': slug},
                  'query': '''query getQuestionDetail($titleSlug: String!) {
                question(titleSlug: $titleSlug) {
                    questionId
                    questionFrontendId
                    questionTitle
                    questionTitleSlug
                    questionTitleCN
                    difficulty
                    stats
                    similarQuestions
                    categoryTitle
                    topicTags {
                            name
                            slug
                    }
                }
            }'''
                  }

        json_data = json.dumps(params).encode('utf8')

        resp = self.session.post(
            url, data=json_data, headers=HEADERS, timeout=10)
        content = resp.json()

        # 题目详细信息
        print(content)
        question = content['data']['question']
        # print(question)
        return question

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
        # visited = set(
        has_next = True
        last_key = ''

        while has_next and page_num < 3000:
            api = SUMBISSION_API.format(page_num, last_key)

            html = self.session.get(api, verify=False)
            html = json.loads(html.text)
            has_next = html.get('has_next', True)
            last_key = html.get('last_key', '')
            print("Now for page: {} hasNext: {},".format(page_num, has_next))

            for submission in html.get("submissions_dump", []):
                submission_status = submission['status_display']
                def time_delta(t): return int(time.time() - t)/(3600 * 24)
                cur_time = submission['timestamp']
                if time_delta(cur_time) > TIME_CONTROL:
                    return
                if submission_status == "Accepted":
                    title = submission['title'].replace(" ", "")
                    # print("title: {} {}".format(title, day))
                    memory = submission['memory']
                    if memory and len(memory) > 0 and memory[0].isdigit():
                        memory = submission['memory'][:-3]
                    else:
                        memory = 0xffff
                    item = {
                        'sid': submission['id'],
                        'runtime': float(submission['runtime'][:-3]),
                        'lang': submission['lang'],
                        'time': submission['timestamp'],
                        'memory': memory,
                    }
                    self.submission\
                        .setdefault(title + '_' + submission['lang'], []).append(item)
            time.sleep(0.3)
            page_num += 20

    def filter_question(self):
        # 保障每道题只记录每种语言最优的AC解
        def time_delta(t): return int(time.time() - t)/(3600 * 24)
        for title_lang, items in self.submission.items():
            items = list(filter(lambda x: time_delta(x['time']) < TIME_CONTROL,
                                items))
        submission = {}
        for title_lang, items in self.submission.items():
            items.sort(key=lambda x: (x['time'], x['memory']))
            items.reverse()
            if len(items) >= 1:
                # print(items)
                item = items[0]
                submission[title_lang] = item
                print('best result {} {} {} {}'.format(title_lang,
                                                       item['lang'],
                                                       item['time'],
                                                       item['memory']))
                # exit(-1)
        # exit(-1)
        self.submission = submission

    def download(self):
        self.filter_question()
        for title, item in self.submission.items():
            try:
                sid = item['sid']
                self.download_code(sid)
                time.sleep(0.3)
            except Exception as e:
                print('Download execption: {}'.format(e))

    def download_code(self, qid):
        param = {'operationName': "mySubmissionDetail", "variables": {"id": qid},
                 'query': "query mySubmissionDetail($id: ID\u0021) {  submissionDetail(submissionId: $id) {    id    code    runtime    memory    statusDisplay    timestamp    lang    passedTestCaseCnt    totalTestCaseCnt    sourceUrl    question {      titleSlug      title      translatedTitle      questionId      __typename    }    ... on GeneralSubmissionNode {      outputDetail {        codeOutput        expectedOutput        input        compileError        runtimeError        lastTestcase        __typename      }      __typename    }    __typename  }}"
                 }
        param_json = json.dumps(param).encode("utf-8")
        response = self.session.post("https://leetcode-cn.com/graphql/",
                                     data=param_json, headers=HEADERS)
        if not response.ok\
                and not response.json()['data']\
                and not response.json()['data']['submissionDetail']:
            print('response: {}'.format(response))
            return
        data = response.json()['data']["submissionDetail"]
        lang = data['lang']
        title_slug = data['question']['titleSlug'].replace('-', '_')
        question_id = data['question']['questionId']
        full_path = self.generate_path(question_id, title_slug, lang)

        if data and not os.path.exists(full_path):
            print('download {} {} {}'.format(question_id, title_slug, lang))
            code = data.get('code', '')
            with open(full_path, "w") as f:
                f.write(code)

    def generate_path(self, pid, title, lang):

        title = title.replace('-', '_')
        title = title.replace(' ', '_')
        if pid[0].isdigit():
            pid = int(pid)
            newpath = OUTPUT_DIR + '/{:0=4}.{}'.format(pid, title)
            filename = '{}{}'.format(title, FILE_FORMAT[lang])
        elif FILE_FORMAT[lang] == '.sql':
            # 如果题目是新的面试题
            newpath = DB_DIR + "/{}.{}".format(pid, title)
            filename = '{}{}'.format(title, FILE_FORMAT[lang])
        else:
            newpath = OUTPUT_DIR + "/{}.{}".format(pid, title)
            filename = '{}{}'.format(title, FILE_FORMAT[lang])

        if not os.path.exists(newpath):
            os.mkdir(newpath)

        return os.path.join(newpath, filename)

    def push_to_github():
        today = time.strftime('%Y-%m-%d', time.localtime(time.time()))
        os.chdir(OUTPUT_DIR)
        instructions = ["git add .", "git status",
                        "git commit -m \"{}\"".format(today),
                        "git push -u origin master"]
        for ins in instructions:
            os.system(ins)
            print("~~~~~~~~~~~~~" + ins + " finished! ~~~~~~~~")


if __name__ == '__main__':
    leetcode = LeetCode()
    leetcode.login(USERNAME, PASSWORD)
    # leetcode.user_info()
    print('Start scrapping')
    # leetcode.get_problem_by_slug('')
    leetcode.scraping()
    leetcode.download()
    # leetcode.get_problem_by_slug('pairs-with-sum-lcci')
    print('End scrapping')
