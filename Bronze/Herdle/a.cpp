#include <iostream>

using namespace std;

int main() {
    char guess[9];
    char answer[9];
    int lettersGuess[26] = {};
    int lettersAnswer[26] = {};
    for(int i = 0; i < 9; i++) {
        cin >> answer[i];
    }
    for(int i = 0; i < 9; i++) {
        cin >> guess[i];
    }
    int yellow = 0;
    int green = 0;
    for(int i = 0; i < 9; i++) {
        if(guess[i] == answer[i]) {
            green++;
        } else {
            lettersGuess[guess[i] - 'A']++;
            lettersAnswer[answer[i] - 'A']++;
        }
    }
    // for(int i = 0; i < 26; i++) {
    //     cout << "Guess: " << char('A' + i) << " : " << lettersGuess[i] << " | ";
    //     cout << "Answer: " << char('A' + i) << " : " << lettersAnswer[i] << endl;
    // }
    for(int i = 0; i < 26; i++) {
        if(lettersGuess[i] != 0 && lettersAnswer[i] != 0) {
            if(lettersGuess[i] > lettersAnswer[i]) {
                yellow += lettersAnswer[i];
            } else {
                yellow += lettersGuess[i];
            }
        } 
    }
    cout << green << endl << yellow;
}