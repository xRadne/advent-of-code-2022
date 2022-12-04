// Advent of code 2022 - day 2 part 2

// input.txt
// A X
// B Y
// C Z

// Opponent values
// A: Rock = 0
// B: Paper = 1
// C: Scissors = 2
// 
// Player should...
// X: Loose = 0
// Y: Draw = 1
// Z: Win = 2

#include <iostream>
#include <fstream>


int main() {
  std::ifstream input("input.txt");

  int totalScore = 0;
  int result, opponent;
  std::string line;

  // Read line by line
  while (std::getline(input, line)) {
    if (line[0] == 'A') {
      opponent = 0;
    } else if (line[0] == 'B') {
      opponent = 1;
    } else if (line[0] == 'C') {
      opponent = 2;
    }

    if (line[2] == 'X') {
      result = 0;
    } else if (line[2] == 'Y') {
      result = 1;
    } else if (line[2] == 'Z') {
      result = 2;
    }

    // Calculate score
    int player;
    if (result == 0) { // Loose
      player = (opponent + 2) % 3;
    } else if (result == 1) { // Draw
      player = opponent;
    } else if (result == 2) { // Win
      player = (opponent + 1) % 3;
    }

    if (result == 1) {
      totalScore += 3;
    } else if (result == 2) {
      totalScore += 6;
    }
  
    // Add points for choice of player
    totalScore += player + 1;
  }

  std::cout << "Total score: " << totalScore << std::endl;
}
