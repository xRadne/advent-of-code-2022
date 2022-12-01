#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream infile("input.txt");

string line;

int main() {
  vector<int> max_calories { 0, 0, 0 }; // increasing
  int current = 0;
  while (getline(infile, line))
  {
    line.erase(remove(line.begin(), line.end(), '\r'), line.cend());

    if (line.empty())
    {
      for (int i = 2; i >= 0; i--) {
        if (current > max_calories[i]) {
          int temp = max_calories[i];
          max_calories[i] = current;
          current = temp;
        }
      }
      current = 0;
      continue;
    }
    current += stoi(line);
  }

  int total = 0;
  for (int i = 0; i < max_calories.size(); i++) {
    total += max_calories[i];
  }

  std::cout << "Max calories: " << total << std::endl;
}
