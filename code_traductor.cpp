#include <iostream>
#include <sstream>
using namespace std;

const char *fileName = "words.dat";

struct TranslatedWord {
    int id;
    char word[50];
    char translation[50];
    char functionality[200];
};


string removeSpecialCharacter(string s, int size);
void getWords(string str, string tmp);
string* removeDynamicStringDuplicated(string n[], int size);
string sanitizeText(string str);
string* split(string str);
string replaceAll(string& s, string const& toReplace, string const& replaceWith);

void codeTranslator() {
    string s;
    getline(cin,s,'x');
    string tmp;
    string original = s;

    tmp = replaceAll(s, "(", " ");
    tmp = replaceAll(tmp, ")", " ");
    tmp = replaceAll(tmp, "<<", " ");
    tmp = replaceAll(tmp, ">>", " ");
    tmp = replaceAll(tmp, "{", " ");
    tmp = replaceAll(tmp, "}", " ");

    getWords(original, tmp);

    system("pause");
}


void getWords(string str, string tmp) {
    system("cls");
    FILE* file = fopen(fileName, "rb");
    TranslatedWord translatedWord;
    int idx = 0;

    const string textSanitizer = sanitizeText(tmp);
    string* txt = split(textSanitizer);

    string* removedDuplicated = removeDynamicStringDuplicated(txt, textSanitizer.length());
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
    } while (feof(file) == 0);
    fclose(file);

    cout<<"=========================="<<endl;
    cout<<"      TEXTO ORIGINAL    "<<endl;
    cout<<"=========================="<<endl;
    cout<<str<<endl;



    cout<<"=========================="<<endl;
    cout<<"      TEXTO TRADUCIDO    "<<endl;
    cout<<"=========================="<<endl;

    for (int i = 0; i < idx; ++i) {
        for (int j = 0; j < textSanitizer.length(); ++j) {
            if (words[i] == removedDuplicated[j] && !removedDuplicated[j].empty()) {
                finalString = replaceAll(finalString, words[i], translations[i]);
            }
        }
    }


    cout<<finalString<<endl;
}


