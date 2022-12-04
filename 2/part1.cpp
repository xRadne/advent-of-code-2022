// Advent of code 2022 - day 2

// input.txt
// A X
// B Y
// C Z

// Opponent values
// A: Rock = 0
// B: Paper = 1
// C: Scissors = 2
// 
// Player values
// X: Rock = 0
// Y: Paper = 1
// Z: Scissors = 2
// 
// Player winns if opponent is 1 less than player
// Player looses if opponent is 1 more than player
// Score = (player - opponent) % 3 => (0 = draw => 3pts, 1 = win => 6pts, 2 = loose => 0pts)

#include <iostream>
#include <fstream>


int main() {
  std::ifstream input("input.txt");

  int totalScore = 0;
  int player, opponent;
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
      player = 0;
    } else if (line[2] == 'Y') {
      player = 1;
    } else if (line[2] == 'Z') {
      player = 2;
    }

    // Calculate score
    int result = (player - opponent + 3) % 3;

    if (result == 0) {
      totalScore += 3;
    } else if (result == 1) {
      totalScore += 6;
    }
  
    // Add points for choice of player
    totalScore += player + 1;
  }

  std::cout << "Total score: " << totalScore << std::endl;
}
