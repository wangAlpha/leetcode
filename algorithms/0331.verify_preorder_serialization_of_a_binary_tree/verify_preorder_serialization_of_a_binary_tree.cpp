#include <iostream>
#include <sstream>

class Solution {
public:
    bool isValidSerialization(const string& s) {
        int count = 1;
        stringstream ss(s);
        string item;
    
        while (getline(ss, item, ',')) {
            if (count == 0) {
                return false;
            }
            count += item == "#" ? -1 : 1;
        }

        return count == 0;
    }
};