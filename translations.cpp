#include <iostream>
using namespace std;


class Translations {
private:
    string word, translation;

public:
    Translations() {

    }

    Translations(string word, string translation) {
        this->word = word;
        this->translation = translation;
    }

    string getWord() {
        return this->word;
    }

    string getTranslation() {
        return this->translation;
    }

};