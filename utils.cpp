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

string replaceAll(string& s, string const& toReplace, string const& replaceWith) {
    string buf;
    size_t pos = 0;
    size_t prevPos;

    buf.reserve(s.size());

    while (true) {
        prevPos = pos;
        pos = s.find(toReplace, pos);
        if (pos == string::npos)
            break;
        buf.append(s, prevPos, pos - prevPos);
        buf += replaceWith;
        pos += toReplace.size();
    }

    buf.append(s, prevPos, s.size() - prevPos);
    s.swap(buf);

    return s;
}

string* removeDynamicStringDuplicated(string n[]) {
    string prevValue, currentValue;
    int idx = 0;
    string* newArray = new string[n->length()];

    for (int i = 0; i < n->length(); ++i) {
        currentValue = n[i];

        if (prevValue != n[i]) {
            prevValue = n[i];
            newArray[idx] = prevValue;
            idx++;
        }
    }

    return newArray;
}