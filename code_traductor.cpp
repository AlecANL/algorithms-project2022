#include <iostream>
#include "translations.cpp"
#include <cstring>
#include <sstream>
using namespace std;

const char *fileName = "words.dat";

struct TranslatedWord {
    int id;
    char word[50];
    char translation[50];
    char functionality[200];
};

string* removeDupWord(string str);
string removeSpecialCharacter(string s);
void getWords(string str);
string arrayCharToString(char * word);
string* removeDynamicStringDuplicated(string n[]);
string replaceAll(string& s, string const& toReplace, string const& replaceWith);

void codeTranslator() {
    string s;
    getline(cin,s,'x');

    getWords(s);



    system("pause");
}

string* removeDupWord(string str) {
    istringstream ss(str);
    string word;
    string* words = new string[100];
    int i = 0;
    while (ss >> word) {
        words[i] = removeSpecialCharacter(word);
        i++;
    }

    return words;
    cout<<"Should be include: "<<words[0]<<endl;
}

string removeSpecialCharacter(string s) {
    string tmp[100];
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



void getWords(string str) {
    system("cls");
    FILE* file = fopen(fileName, "rb");
    TranslatedWord translatedWord;
    int idx = 0;
    int size = 1;
    string* cleaningWords = removeDupWord(str);
    string* removedDuplicated = removeDynamicStringDuplicated(cleaningWords);
    string finalString = str;
    string* words = new string[100];
    string* translations = new string[100];


    if (!file) {
        file = fopen(fileName, "w+b");
    }

    fread(&translatedWord, sizeof(translatedWord), 1, file);

    do {

        words[idx] = (translatedWord.word);
        translations[idx] = (translatedWord.translation);
        fread(&translatedWord, sizeof(translatedWord), 1, file);

        idx += 1;
        size++;
    } while (feof(file) == 0);

    fclose(file);


    int position = 0;

    cout<<"=========================="<<endl;
    for (int i = 0; i < words->length(); ++i) {

        for (int j = 0; j < removedDuplicated->length(); ++j) {
            if (words[i] == removedDuplicated[j]) {
                finalString = replaceAll(finalString, words[i], translations[i]);
                position = i;
            }
        }
    }


    cout<<finalString<<endl;
}


////        cout<<removedDuplicated[idx]<<endl;
//cout<<"Word: "<<removedDuplicated[idx]<<"|"<<arrayCharToString(translatedWord.word)<<" IDX: "<<idx<<endl;
//if (arrayCharToString(translatedWord.word) == removedDuplicated[idx] && !removedDuplicated->empty()) {
//cout<<"Hello world"<<endl;
////            finalString = replaceAll(finalString, removedDuplicated[idx], arrayCharToString(translatedWord.translation));
//}

/*
 *
 *        for (int i = 0; i < removedDuplicated->length(); ++i) {
            cout<<"Duplicated: "<<removedDuplicated[i]<<" P: "<<i<<" | "<<" Translated: "<<translatedWord.word<<" P: "<<i<<endl;
            if (arrayCharToString(translatedWord.word) == removedDuplicated[i]) {
                cout<<"Hello world"<<endl;
            }

        }
        cout<<endl;
 *
 * */