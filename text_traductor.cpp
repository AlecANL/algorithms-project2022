#include <iostream>
#include <sstream>
using namespace std;

const char *fileTxtTranslatorName = "words.dat";

struct TranslatedWord {
    int id;
    char word[50];
    char translation[50];
    char functionality[200];
};

string* split(string str);
string sanitizeText(string str);
string* removeDynamicStringDuplicated(string n[], int size);
string replaceAll(string& s, string const& toReplace, string const& replaceWith);

void getWords(string str);

void textTranslator() {
    cin.ignore();

    string txt;
    cout<<"Ingresa el texto a traducir: ";
    getline(cin, txt);

    getWords(txt);
    system("pause");
}



void getWords(string str) {
    system("cls");
    FILE* file = fopen(fileTxtTranslatorName, "rb");
    TranslatedWord translatedWord;
    int idx = 0;

    const string textSanitizer = sanitizeText(str);
    string* txt = split(textSanitizer);

    string* removedDuplicated = removeDynamicStringDuplicated(txt, textSanitizer.length());
    string finalString = str;
    string* words = new string[100];
    string* translations = new string[100];



    if (!file) {
        file = fopen(fileTxtTranslatorName, "w+b");
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
            if (translations[i] == removedDuplicated[j] && !removedDuplicated[j].empty()) {
                finalString = replaceAll(finalString, translations[i], words[i]);
            }
        }
    }


    cout<<finalString<<endl;
}

