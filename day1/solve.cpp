#include <iostream>  // cout, endl
#include <fstream>  // fstream
#include <string>   // string
#include <vector>   // vector

/**
 *
 * @param mass The mass of the module.
 * @return The amount of fuel it takes to get the module up to the destination.
 */
long getFuelNeeded(int mass) {
  if(mass <= 0) {
    return 0;
  }
  return mass / 3 - 2;
}

/**
 *
 * @param mass The mass of the module.
 * @return The amount of fuel it takes to get the module up to the destination.
 */
long getFuelNeededRecursive(int mass) {
  long fuel = getFuelNeeded(mass);
  if(fuel <= 0) {
    return 0;
  }
  return fuel + getFuelNeededRecursive(fuel);
}

/**
 *
 * @param file The input file of the mass of the modules.
 * @param func The fuel calculation logic.
 * @return The sum of all fuel is takes to get the mass up to destination, -1 if input file was not found.
 */
long getFuel(std::string file, long func(int)) {
  std::ifstream massDataFile(file);
  long sum = 0;
  if(massDataFile.is_open()) {
    std::string line;
    while(getline(massDataFile, line)) {
      sum += func(atoi(&line[0]));
    }
    massDataFile.close();
  } else {
    return -1;
  }
  return sum;
}

/**
 *
 * @return
 */
int main()
{
  std::cout << "Part 1" << std::endl;
  std::cout << getFuel("input.txt", getFuelNeeded) << std::endl;
  std::cout << "Part 2" << std::endl;
  std::cout << getFuel("input.txt", getFuelNeededRecursive) << std::endl;
  return 0;
}