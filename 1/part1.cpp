#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream infile("input.txt");

string line;

int main() {
  int max_calories = 0;
  int current = 0;
  while (getline(infile, line))
  {
    line.erase(remove(line.begin(), line.end(), '\r'), line.cend());

    if (line.empty())
    {
      max_calories = max(max_calories, current);
      current = 0;
      continue;
    }
    current += stoi(line);
  }
  std::cout << "Max calories: " << max_calories << std::endl;
}
