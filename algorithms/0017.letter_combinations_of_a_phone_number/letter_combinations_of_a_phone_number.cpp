class Solution {
public:
    void backtrack(vector<string> &combinations, const string& digits, int index, string combination) {
        if (index == digits.size()) {
            combinations.emplace_back(combination);
        } else {
            const char digit = digits[index];
            const string letters = phone_map_[digit];
            const int letter_count = letters.size();
            for (int i = 0; i < letter_count; ++i) {
                combination.push_back(letters[i]);
                backtrack(combinations, digits, index+1, combination);
                combination.pop_back();
            }
        }
    }
    vector<string> letterCombinations(const string& digits) {
       vector<string> combinations;  
        if (digits.empty()) {
            return combinations;
        }
        backtrack(combinations, digits, 0, "");
        return combinations; 
    }
private:
    unordered_map<char, string> phone_map_ = {
        {'0', ""},
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
};