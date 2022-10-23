#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char * stringToArrayChar(string word) {
    char charWord[word.length()];

    for (int i = 0; i < word.length() - 1; ++i) {
        charWord[i] = word[i];
    }

    return charWord;
}


string arrayCharToString(char * word) {
    const int size = sizeof(word) / sizeof(char);
    string stringWord;

    for (int i = 0; i < size; ++i) {
        stringWord += word[i];
    }

    return stringWord;
}

int generateADummyId() {
    srand((unsigned) time(NULL));
    int random = 10 + (rand() % 1000);

    return random;
}
