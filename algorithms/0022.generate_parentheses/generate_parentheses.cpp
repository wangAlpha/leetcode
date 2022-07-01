class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return {};
        }
        string parenthesis;
        generateParenthesis(parenthesis, n, n);
        return ans_;
    }
    void generateParenthesis(string& parenthesis, int left, int right) {
        if (left == 0 && right == 0) {
            ans_.push_back(parenthesis);
            return;
        }
        if (left == right) {
            parenthesis.push_back('(');
            generateParenthesis(parenthesis, left - 1, right);
            parenthesis.pop_back();
        } else  {
            if (left > 0) {
                parenthesis.push_back('(');
                generateParenthesis(parenthesis, left - 1, right);
                parenthesis.pop_back();
            }
            parenthesis.push_back(')');
            generateParenthesis(parenthesis, left, right - 1);
            parenthesis.pop_back();
        }
    }
private:
    vector<string> ans_;
};