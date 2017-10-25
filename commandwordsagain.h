#ifndef COMMANDWORDSAGAIN_H
#define COMMANDWORDSAGAIN_H


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CommandWordsAgain {
private:
    //Define a static vector for our valid command words.
    //We'll populate this in the class constructor
    static vector<string> validCommands;

public:
    CommandWordsAgain();
    bool isCommand(string aString);
    void showAll();
};

#endif // COMMANDWORDSAGAIN_H
