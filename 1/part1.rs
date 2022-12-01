// Advent of code 2022 - day 1

use std::fs::*;

fn main() {
  let input = read_to_string("input.txt").unwrap();
  let lines = input.lines();

  let mut max_calories = 0;
  let mut current = 0;
  for line in lines {
    if line.is_empty() {
      max_calories = max_calories.max(current);
      current = 0;
      continue;
    }

    let calories = line.parse::<i32>().unwrap();
    current += calories;
  }
  
  // Print the maximum calories
  println!("Max calories: {}", max_calories);
}

