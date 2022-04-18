#include <gtest/gtest.h>

class A {
  virtual void func1();
  virtual void func2();
};

int main() {
  A a();
  return 0;
}
