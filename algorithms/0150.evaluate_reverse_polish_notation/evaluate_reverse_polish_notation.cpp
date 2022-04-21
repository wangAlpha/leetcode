class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string&t: tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                const int n = s.top(); s.pop();
                const int n1 = s.top(); s.pop();
                if (t == "+") s.push(n + n1);
                else if (t == "-") s.push(n1 - n);
                else if (t == "*") s.push(n * n1);
                else s.push(n1 / n);
            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};
// ["4","13","5","/","+"]