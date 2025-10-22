//  HW5-CS1337-Duc-Nguyen
//
//  Created by Duc Nguyen on 3/20/23.
//
// Changelog:
// 2/23/2023
// -created the struct animalStruct
// -created the introduction to the program prompting them to give y or n to start or not start the game
// 2/25/2023:
// -tested out the struct animalStruct and the function gameIntroduction to see if they work
// 2/27/2023:
// -made good progress in initializing first animal "Lizard" alongside creating a pointer
// -encountered a infinite loop bug in the gameIntroduction
// -working on debugging some bugs in my current functions
// 2/28/2023:
// -did some troubleshooting for some bugs on functions
// -testing out the pointers and the tree
// 2/29/2023:
// -worked on logging in new animals to the tree
// -keep experiencing problems in logInTheNewAnimal function to log in new animal for struct
// 2/30/2023:
// -made breakthrough in loging new animals into the struct
// -working on function askQuestionsAboutAnimal to go through tree in search of animal
// 2/30/2023:
// -found a possible problem with linking in the new animal into tree in LogInTheNewAnimal
// -was able to reticfy the mistake on logintheNewAnimal linking the curnode to the newly created node dependent on the response to their answer
// 4/1/2023:
// -was able to finish code to create tree
// - found a very annoying bug where it loops in displaying the first node
// -have to simiplufy try again t to make the program loop (doesn't even do anything if don't change it)
//


#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>
#include <cstdlib>
using namespace std;
int nextNode, previousNode, runOnlyOnce;
bool true_false, guessTheAnimal, tryAgainCondition = true;
char yes_no;
string isItAnimal, newAnimal, newQuestion, getAnswerForNew, tryAgainT;

struct animalStruct {
    string animalQuestion;
    string animalGuess;
    animalStruct* yesAnswer= nullptr, * noAnswer=nullptr;
};
animalStruct *firstNode, *guessNode, * curNode, *endNode, *newStructureAnimal, *animalYesPtr , *animalNoPtr ;

void checkAnimal();

void initializeFirstAnimal() {
        firstNode = new animalStruct;
       // firstNode = { "", "lizard", nullptr, nullptr };
       // guessNode = &firstNode;
        firstNode->animalQuestion = "";
        firstNode->animalGuess = "Lizard";
}

void gameIntroduction() {
    cout << "Welcome to the animal guessing game." << endl;
    cout << "enter only 'Y' to start the game or 'N' if you don't want to play." << endl;
    // cout << "entered" << endl;
    cin >> yes_no;
    yes_no = tolower(yes_no);
    if (yes_no != 'y') {
        if (yes_no != 'n') {
            cout << "Error, not a valid input." << endl;
            cin >> yes_no;
            yes_no = tolower(yes_no);
        }
    }
    //cout << "success" << endl;
}

void thinkOfAnimal() {
    char getEnter;
    cout << "Alright, please think of a animal" << endl;
    cout << "When you're ready please enter the ENTER/RETURN key to proceed" << endl;
    cin.ignore();
    cin.get(getEnter);
    //cout << "exited" << endl;
}

animalStruct *logInNewAnimal(string theQuestion, string newAnimal){
//    curNode = guessNode;
//    if(getAnswerForNew == "no"){
//curNode->noAnswer = new animalStruct(newQuestion, newAnimal, nullptr, nullptr);
//curNode->yesAnswer = new animalStruct()
//    }
    newStructureAnimal = new animalStruct;
    newStructureAnimal->animalQuestion = theQuestion;
    newStructureAnimal->animalGuess = newAnimal;
    return newStructureAnimal;
    }


void ifFalse(animalStruct *curNode){
    bool ifInputWasYesOrNo = false;
    cout << "Bummer! What animal were you thinking of?" << endl;
    //cin >> guessNode->animalGuess;
    cin >> newAnimal;
    int run = 0;
    cout << "What is a yes/no question that I can use to tell a " << curNode->animalGuess << " from a " << newAnimal << "?" << endl;
    //cin >> guessNode->animalQuestion;
    //newStructureAnimal+1;
    cin.ignore();
    getline(cin, newQuestion);
        cout << "For a " << newAnimal << " is it yes or no?" << endl;
        cin >> getAnswerForNew;
        while ( run < getAnswerForNew.length()) {
            getAnswerForNew[run] = tolower(getAnswerForNew[run]);
            run++;
        }
        if (getAnswerForNew == "yes") {
            ifInputWasYesOrNo = true;
        }
        else if (getAnswerForNew == "no") {
            ifInputWasYesOrNo = true;
        }
    while (ifInputWasYesOrNo == false){
        cin >> getAnswerForNew;
        if (getAnswerForNew == "yes") {
            ifInputWasYesOrNo = true;
        }
        else if (getAnswerForNew == "no") {
            ifInputWasYesOrNo = true;
        }
    }
    string holdTheGuess = curNode->animalGuess;
    animalNoPtr = logInNewAnimal("", holdTheGuess);
    animalYesPtr = logInNewAnimal("",newAnimal );
    if(getAnswerForNew == "yes"){
        curNode->noAnswer = animalNoPtr;
        curNode->yesAnswer = animalYesPtr;
        curNode->animalQuestion = newQuestion;
        curNode->animalGuess = "";
    }
    else if(getAnswerForNew == "no"){
        curNode->yesAnswer = animalNoPtr;
        curNode->noAnswer = animalYesPtr;
        curNode->animalQuestion = newQuestion;
        curNode->animalGuess = "";
    }
    do {
        cout << "Try again? (press t to try again or any other letter to stop)" << endl;
        cin >> tryAgainT;
    } while (tryAgainT.length() !=1);
    for (int i = 0; i <= tryAgainT.length(); i++) {
        tryAgainT[i] = tolower(tryAgainT[i]);
    }
}

void ifTrue(animalStruct *curNode) {
    cout << "Good! I guessed your animal." << endl;
    do {
        cout << "Try again? (press t to try again or any other letter to stop)" << endl;
        cin >> tryAgainT;
    } while (tryAgainT.length() !=1);
    for (int i = 0; i <= tryAgainT.length(); i++) {
        tryAgainT[i] = tolower(tryAgainT[i]);
    }
}


void checkAnimal(animalStruct *curNode) {
    bool onlyYes_No = false;
    if(curNode->animalQuestion != ""){
        cout << curNode->animalQuestion << endl;
    }
    else if (curNode->animalQuestion == ""){
        cout << "Is the animal a "<< curNode->animalGuess << "? (yes or no?)" << endl;
    }
    cin >> isItAnimal;
    for (int runlength = 0; runlength < isItAnimal.length(); runlength++) {
        isItAnimal[runlength] = tolower(isItAnimal[runlength]);
    }
    if (isItAnimal == "yes") {
        true_false = true;
        onlyYes_No = true;
    }
    else if (isItAnimal == "no") {
        true_false = false;
        onlyYes_No = true;
    }
    while (onlyYes_No == false) {
        cin >> isItAnimal;
        for (int runlength = 0; runlength < isItAnimal.length(); runlength++) {
            isItAnimal[runlength] = tolower(isItAnimal[runlength]);
        }
    }
    if(isItAnimal == "yes"){
        if(curNode->yesAnswer == nullptr){
            ifTrue(curNode);
        }
        if(curNode->yesAnswer != nullptr){
            checkAnimal(curNode->yesAnswer);
        }
    }
    else if(isItAnimal == "no"){
        if(curNode->noAnswer == nullptr){
            ifFalse(curNode);
        }
        else if(curNode->noAnswer!=nullptr){
            checkAnimal(curNode->noAnswer);
        }
    }
}

void processFunctions() {
        while (tryAgainCondition == true) {
            checkAnimal(firstNode);
            //cout << "got out" << endl;
            if(tryAgainT !="t"){
                tryAgainCondition = false;
            }
            //cout << "Working" << endl;
        }
    }


int main(int argc, const char* argv[]) {
    initializeFirstAnimal();
    gameIntroduction();
    if(yes_no == 'y'){
        thinkOfAnimal();
        processFunctions();
    }
    return 0;
}
