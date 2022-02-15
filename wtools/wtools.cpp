#include <fstream>
#include <iostream>
#include <vector>
#include "word.h"
#include "wordList.h"
using namespace std;

int main() {
    enum Option {
        search = 1,
        quit = 9
    };
    fstream fiveLfile;
    wordList listOfWords;
    fiveLfile.open("5lwords.txt", ios::in);
    if (!fiveLfile) {
        cout << "File not found";
    } else {
        cout << "File imported!" << endl;
        string cur;
        while (true) {
            fiveLfile >> cur;
            if (fiveLfile.eof()) {
                cout << "Word list populated." << endl;
                break;
            }
            word out = word(cur);
            listOfWords.add(out);
            
        }
    }

    cout << "\033[2J\033[1;1H";
    bool notDoneYet = true;
    do {
        cout << "ENTER ONE OF THE NUMBERS BELOW" << endl;
        cout << "------------------------------" << endl;
        cout << "1. Search" << endl;
        cout << "9. Quit" << endl;
        cout << "Enter choice: ";
        int menuChoice = 0;
        cin >> menuChoice;
        cout << endl;


        string in;
        vector<char> chars;
        vector<char> excl;
        vector<int> indices;
        char cadd;
        char csub;
        int ind;
        switch (menuChoice) {
            case search:
                cout << "Enter string with characters you know to be in the correct space." << endl;
                cout << "In spaces where you do not know for sure what the character is, enter _" << endl;
                cin >> in;
                do {
                    cout << "Enter a character that exists somewhere within the word (% to proceed): ";
                    cin >> cadd;
                    if (cadd == '%') break;
                    chars.push_back(cadd);
                    cout << "Enter the index at which it was found: ";
                    cin >> ind;
                    indices.push_back(ind);
                } while (cadd != '%');
                do {
                    cout << "Enter a character that exists nowhere within the word (% to proceed): ";
                    cin >> csub;
                    if (csub == '%') break;
                    excl.push_back(csub);
                } while (csub != '%');
                cout << endl << "Words found matching those criteria: " << endl;
                listOfWords.printSearch(word(in), chars, excl, indices);
                cout << endl;
                break;
            case quit:
                return 0;
            default:
                cout << "Invalid. Try Again\n\n";
                continue;
                break;
        }
    } while (notDoneYet);
    fiveLfile.close();
    return 0;
}