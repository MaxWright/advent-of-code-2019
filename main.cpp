#include <iostream>  // cout, endl
#include <fstream>  // fstream
#include <string>   // string
#include <vector>   // vector
int main()
{
  std::ifstream mass_data_file("input.txt");
  std::vector<int> mass;
  if(mass_data_file.is_open()) {
    std::string line;
    while(getline(mass_data_file, line)) {
      mass.push_back(atoi(&line[0]));
    }
  }

  for(std::vector<int>::iterator it = mass.begin(); it != mass.end(); ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << "Hello, World!" << std::endl;
  return 0;
}