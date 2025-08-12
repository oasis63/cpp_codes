#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

string getComputerChoice() {
  string choices[] = {"rock", "paper", "scissors"};
  return choices[rand() % 3];
}

string getResult(const string &user, const string &computer) {
  if (user == computer)
    return "It's a tie!";
  if ((user == "rock" && computer == "scissors") ||
      (user == "paper" && computer == "rock") ||
      (user == "scissors" && computer == "paper")) {
    return "You win!";
  }
  return "Computer wins!";
}

int main() {
  srand(time(0));  // seed random generator
  string userChoice, computerChoice;
  char playAgain;

  cout << "🎮 Welcome to Rock-Paper-Scissors Game!\n";

  do {
    cout << "\nEnter your choice (rock, paper, scissors): ";
    cin >> userChoice;

    // Make input lowercase for simplicity (optional)
    for (auto &ch : userChoice) ch = tolower(ch);

    if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
      cout << "Invalid choice! Try again.\n";
      continue;
    }

    computerChoice = getComputerChoice();
    cout << "Computer chose: " << computerChoice << endl;

    cout << getResult(userChoice, computerChoice) << endl;

    cout << "\nDo you want to play again? (y/n): ";
    cin >> playAgain;
  } while (playAgain == 'y' || playAgain == 'Y');

  cout << "Thanks for playing! 👋\n";
  return 0;
}
