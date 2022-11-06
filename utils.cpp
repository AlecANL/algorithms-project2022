#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
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

string* removeDynamicStringDuplicated(string n[], int size) {
    string prevValue, currentValue;
    int idx = 0;
    string* newArray = new string[size];

    for (int i = 0; i < size; ++i) {
        currentValue = n[i];

        if (prevValue != n[i]) {
            prevValue = n[i];
            newArray[idx] = prevValue;
            idx++;
        }
    }

    return newArray;
}

string removeSpecialCharacter(string s, int size) {
    string tmp[size];
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z')) {
            s[j] = s[i];
            tmp[j] = s[i];
            j++;
        }
    }

    return s.substr(0, j);
}

string sanitizeText(string str) {
    istringstream ss(str);
    string word;
    string a;

    int i = 0;
    while (ss >> word) {
        if (!removeSpecialCharacter(word, str.length()).empty()) {
            a += removeSpecialCharacter(word, str.length()) + " ";
            i++;
        }
    }

    return a;
}

string* split(string str) {
    string line = str;
    string* arr = new string[str.length()];


    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < str.length()){
        ssin >> arr[i];
        ++i;
    }

    return arr;
}