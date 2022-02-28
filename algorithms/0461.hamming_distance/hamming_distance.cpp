class Solution {
public:
  int hammingDistance(int x, int y) {
    int number = x ^ y;
    int distance = 0;
    while (number > 0) {
      number &= (number - 1);
      distance += 1;
    }
    return distance;
  }
};