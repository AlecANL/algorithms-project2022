#include <iostream>
using namespace std;

void mainMenu();

void crudHandler();
void codeTranslator();
void textTranslator();

int main() {
    int option;
    mainMenu();
    cin>>option;

    system("cls");

    switch (option) {
        case 1:
            crudHandler();
            break;
        case 2:
            textTranslator();
            break;
        case 3:
            codeTranslator();
            break;
        default:
            break;
    }


    return 0;
}
