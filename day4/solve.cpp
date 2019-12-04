#include <iostream> // cout, endl

bool leftToRightDecrease(int num) {
  bool dub = false;
  while(num > 0) {
    int next = num % 10;
    num /= 10;
    int prev = num % 10;
    if(next < prev) {
      return false;
    }
    if(next == prev) {
      dub = true;
    }
  }
  return dub;
}

bool leftToRightDecrease2(int num) {
  int array[10] = {0};
  while(num > 0) {
    int next = num % 10;
    num /= 10;
    int prev = num % 10;
    if(next < prev) {
      return false;

    }
    if(next == prev) {
      array[next] += 1;
    }
  }
  for(int i = 0; i < 10; ++i) {
    if(array[i] == 1) {
      return true;
    }
  }
  return false;
}


int find_me(bool func(int))
{
  int count = 0;
  for(int i = 256310; i < 732736 + 1; ++i) {
    if(func(i)) {
      ++count;
    }
  }
  return count;
}

int main()
{
  std::cout << "Day 4" << std::endl;
  std::cout << "Part 1" << std::endl;
  std::cout <<  find_me(leftToRightDecrease) << std::endl;
  std::cout << "Part 2" << std::endl;
  std::cout <<  find_me(leftToRightDecrease2) << std::endl;
}