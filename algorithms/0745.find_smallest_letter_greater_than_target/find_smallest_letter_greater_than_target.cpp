class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0;
        int hi = letters.size() - 1;
        while (lo <= hi) {
            int mi = (hi - lo) / 2 + lo;
            const char &c = letters[mi];
            if (c <= target) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        return lo < letters.size() ? letters[lo] : letters[0];
    }
};