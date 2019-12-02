#include <iostream> // cout, endl

int find(int one, int two) {

  int opcodes[113] = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,6,19,1,9,19,23,2,23,10,27,1,27,5,31,1,31,6,35,1,6,35,39,2,39,13,43,1,9,43,47,2,9,47,51,1,51,6,55,2,55,10,59,1,59,5,63,2,10,63,67,2,9,67,71,1,71,5,75,2,10,75,79,1,79,6,83,2,10,83,87,1,5,87,91,2,9,91,95,1,95,5,99,1,99,2,103,1,103,13,0,99,2,14,0,0};
  opcodes[1] = one;
  opcodes[2] = two;
  int length = 113;
  int opcode = 0;
  int instructionCount = 0;
  int operation[3] = {0,0,0};
  for(int i = 0; i < length; ++i) {
    int code = opcodes[i];
    if(opcode == 0) {
      if(code == 99) {
        break;
      }
      opcode = code;
    } else {
      operation[instructionCount]  = code;
      ++instructionCount;
      if(instructionCount == 3) {
        if(operation[2] > 112 ||operation[0] > 112 || operation[1] > 112 ) {
          return -1;
        }
        if(opcode == 1) {
          opcodes[operation[2]] = opcodes[operation[0]] + opcodes[operation[1]];
        } else if(opcode == 2) {
          opcodes[operation[2]] = opcodes[operation[0]] * opcodes[operation[1]];

        } else {
          std::cout << "Error: " <<  opcode << std::endl;
        }
        opcode = 0;
        instructionCount = 0;
      }
    }
  }
  return opcodes[0];

}

int main() {
  std::cout << "Day 2" << std::endl;
  std::cout << "Part 1" << std::endl;
  std:: cout << find(12,2) << std::endl;
  std::cout << "Part 2" << std::endl;
  for(int i = 0; i < 100; ++i) {
    for(int j = 0; j < 100; ++j) {
      int value = find(i, j);
      if(value == 19690720) {
        std::cout << i << std::endl;
        std::cout << j << std::endl;
      }
    }
  }

  // 99 means that the program is finished and should immediately halt
  // Opcode 1 adds together numbers read from two positions and stores the result in a third position
}