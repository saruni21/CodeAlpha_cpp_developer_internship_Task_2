#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Function to choose a random word from a list of words
string chooseRandomWord(const vector<string>& words) {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// Function to display the current state of the guessed word
void displayWordState(const string& word, const string& guessedLetters) {
    for (char letter : word) {
        if (guessedLetters.find(letter) != string::npos) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to check if the user has guessed the word
bool isWordGuessed(const string& word, const string& guessedLetters) {
    for (char letter : word) {
        if (guessedLetters.find(letter) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> words = {
        "programming", "computer", "science", "keyboard", "mouse",
        "monitor", "processor", "memory", "storage", "network",
        "software", "hardware", "database", "algorithm", "function",
        "variable", "constant", "syntax", "debugging", "compiler",
        "developer", "engineer", "technology", "application", "system",
        "interface", "design", "architecture", "encryption", "security",
        "internet", "protocol", "server", "client", "framework",
        "library", "module", "object", "class", "method",
        "attribute", "parameter", "argument", "loop", "condition",
        "array", "pointer", "reference", "exception", "inheritance"
    };

    string wordToGuess = chooseRandomWord(words);
    string guessedLetters = "";
    int maxAttempts = 15;
    int attemptsLeft = maxAttempts;

    cout << "Welcome to the Word Guessing Game!" << endl;
    cout << "You have " << maxAttempts << " attempts to guess the word." << endl;

    while (attemptsLeft > 0 && !isWordGuessed(wordToGuess, guessedLetters)) {
        cout << "\nWord: ";
        displayWordState(wordToGuess, guessedLetters);
        cout << "Attempts left: " << attemptsLeft << endl;
        cout << "Guessed letters: " << guessedLetters << endl;

        cout << "Enter a letter or the full word: ";
        string input;
        cin >> input;

        // Convert input to lowercase to handle case insensitivity
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input.length() == 1) {
            // Handle single letter guess
            char guess = input[0];

            if (guessedLetters.find(guess) != string::npos) {
                cout << "You already guessed that letter. Try again." << endl;
            } else if (wordToGuess.find(guess) != string::npos) {
                guessedLetters += guess;
                cout << "Good guess!" << endl;
            } else {
                guessedLetters += guess;
                cout << "Wrong guess!" << endl;
                attemptsLeft--;
            }
        } else {
            // Handle full word guess
            if (input == wordToGuess) {
                guessedLetters = wordToGuess; // This ensures that all letters will be displayed
                break;
            } else {
                cout << "Wrong guess!" << endl;
                attemptsLeft--;
            }
        }
    }

    if (isWordGuessed(wordToGuess, guessedLetters)) {
        cout << "\nCongratulations! You've guessed the word: " << wordToGuess << endl;
    } else {
        cout << "\nSorry, you've run out of attempts. The word was: " << wordToGuess << endl;
    }

    return 0;
}
