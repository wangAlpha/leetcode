class Solution {
public:
    bool oneEditAway(string& first, string& second) {
        if (first.size() < second.size()) {
            first.swap(second);
        }
        if (first.size() - second.size() > 1) {
            return false;
        }
        bool flag = false;
        if (first.size() == second.size()) {
            for (size_t i = 0; i < first.size(); ++i) {
                if (first[i] != second[i]) {
                    if (!flag) {
                        flag = true;
                    } else {
                        return false;
                    }
                }
            }
        } else {
            size_t j = 0, i = 0;
            while (i < second.size()) {
                if (first[j] != second[i]) {
                    if (!flag) {
                        ++j;
                        flag = true;
                    } else {
                        return false;
                    }
                } else {
                    ++i;
                    ++j;
                }
            }
        }
        return true;
    }

};