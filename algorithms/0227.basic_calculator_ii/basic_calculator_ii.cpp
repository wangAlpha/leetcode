class Solution {
public:
    int calculate(string s) {
        s.push_back('#');
        deque<int> numbers;
        deque<char> operators;
        string curr;
        for (const char &c: s) {
            if (isdigit(c)) {
                curr.push_back(c);
            }
            if (!isdigit(c) && !curr.empty()) {
                numbers.push_back(stoi(curr));
                curr.clear();
                if (!operators.empty() && (operators.back() == '*' || operators.back() == '/')) {
                    const int b = numbers.back(); numbers.pop_back(); 
                    const int a = numbers.back(); numbers.pop_back();
                    char op = operators.back(); operators.pop_back();
                    const int n = op == '*' ? (a*b) : (a/b);
                    numbers.push_back(n);
                }
            }
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                operators.push_back(c);
            }
        }
        while (!operators.empty()) {
            const char op = operators.front(); operators.pop_front();
            const int a = numbers.front(); numbers.pop_front();
            const int b = numbers.front(); numbers.pop_front();
            const int n = op == '+' ? (a + b) : (a - b);
            numbers.push_front(n);
        }
        return numbers.back();
    }
};