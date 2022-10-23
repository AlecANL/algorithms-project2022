#include <iostream>
using namespace std;

void mainMenu();

void crudHandler();

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
            break;
        case 3:
            break;
        default:
            break;
    }


    return 0;
}
