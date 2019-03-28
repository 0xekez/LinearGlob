#include <iostream>
#include "linearglob.h"

int main() {
  LinearGlob <int> myGlob;
  myGlob.add("dog", 1);
  myGlob.add("fog", 2);
  myGlob.add("cat", 0);
  std::vector<int> v = myGlob.getPattern("*og");

  for (int a : v) {
    std::cout << a << std::endl;
  }
}
