#include <iostream>
using namespace std;

void crudMenu();
void mainMenu();
int generateADummyId();


struct TranslatedWord {
    int id;
    char word[50];
    char translation[50];
    char functionality[200];
};

void addTranslatedWord();
void showTranslatedWordAdded();
void updateTranslatedWord();
void updateTranslatedWord();
void deleteTranslatedWord();
void viewRegisterHandler();

const char *translatedWords_file = "words.dat";

void crudHandler() {
    system("cls");

    int option;

    crudMenu();
    cin>>option;

    if (cin.fail()) {
        cout<<"El sistema no soporta caracteres especiales. Por favor ingresa un numero."<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        crudMenu();
        cin>>option;
    }

    system("cls");

    switch (option) {
        case 1:
            addTranslatedWord();
            break;
        case 2:
            updateTranslatedWord();
            break;
        case 3:
            deleteTranslatedWord();
            break;
        case 4:
            viewRegisterHandler();
            break;
        default:
            cout<<"Opcion invalida intenta nuevamente. "<<endl;
            crudHandler();
    }
}

void addTranslatedWord() {
    system("cls");

    FILE * file = fopen(translatedWords_file, "a+b");
    char response;
    TranslatedWord translatedWord;

    do {
        fflush(stdin);


        cout<<"Ingresa una palabran: ";
        cin.getline(translatedWord.word, 50);
        cout<<"Ingresa la traduccion: ";
        cin.getline(translatedWord.translation, 50);
        cout<<"Ingresa la funcionalidad: ";
        cin.getline(translatedWord.functionality, 200);
        translatedWord.id = generateADummyId();


        fwrite(&translatedWord, sizeof(translatedWord), 1, file);

        cout<<"Neceistas ingresar mas palabras ? (s/n): ";
        cin>>response;

        system("cls");
    } while (response == 's' || response == 'S');

    fclose(file);
    showTranslatedWordAdded();
}

void showTranslatedWordAdded() {
    system("cls");
    FILE* file = fopen(translatedWords_file, "rb");
    TranslatedWord translatedWord;
    int idx = 0;

    if (!file) {
        file = fopen(translatedWords_file, "w+b");
    }

    fread(&translatedWord, sizeof(translatedWord), 1, file);
    cout<<"________________________________________________"<<endl;
    cout<<"  ID  "<<" | "<<" Palabra "<<"| "<<" Tranduccion "<<"| "<<"      Funcionalidad      "<<endl;

    do {
        cout<<idx<<" | "<<translatedWord.word<<" | "<<translatedWord.translation<<" | "<<translatedWord.functionality<<endl;
        fread(&translatedWord, sizeof(translatedWord), 1, file);

        idx += 1;
    } while (feof(file) == 0);

    fclose(file);
}

void updateTranslatedWord() {
    system("cls");

    int idx;
    char response;
    FILE* file = fopen(translatedWords_file, "r+b");
    TranslatedWord translatedWord;


    cout<<"Para actualizar un registro debes conocer el identficador de este. Si no lo conoces,"<<endl;
    cout<<"Regresar al menu de opciones e ingresa a ver registros donde encontraras el identficador."<<endl;
    cout<<"__________________________________________________________________________________________"<<endl;

    cout<<"Desear regresar al menu principal? (s/n): ";
    cin>>response;

    if (response == 's' || response == 'S') {
        crudHandler();
        return;
    }

    cout<<"Ingresa el identificador (id) del registro que deseas modificar: ";
    cin>>idx;

    if (cin.fail()) {
        cout<<"El sistema no soporta caracteres especiales. Por favor ingresa un numero."<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout<<"Ingresa el identificador (id) del registro que deseas modificar: ";
        cin>>idx;
    }

    fseek(file, idx * sizeof(translatedWord), SEEK_SET);
    cout<<"Ingresa una palabran: ";
    cin.ignore();
    cin.getline(translatedWord.word, 50);
    cout<<"Ingresa la traduccion: ";
    cin.getline(translatedWord.translation, 50);
    cout<<"Ingresa la funcionalidad: ";
    cin.getline(translatedWord.functionality, 200);
    translatedWord.id = generateADummyId();

    fwrite(&translatedWord, sizeof(translatedWord), 1, file);

    fclose(file);

    cout<<"Desear regresar al menu principal ? (s/n): ";
    cin>>response;

    if (response == 's' || response == 'S') {
        crudHandler();
        return;
    }
}

void deleteTranslatedWord() {
    system("cls");

    int idx = 0, currentId = 0;
    char response;
    char backHomeResponse;
    const char * tmp_fileName = "words_tmp_file.dat";
    FILE* file = fopen(translatedWords_file, "rb");
    FILE* tmp_file = fopen(tmp_fileName, "w+b");
    TranslatedWord translatedWord;


    cout<<"Para actualizar un registro debes conocer el identficador de este. Si no lo conoces,"<<endl;
    cout<<"Regresar al menu de opciones e ingresa a ver registros donde encontraras el identficador."<<endl;
    cout<<"__________________________________________________________________________________________"<<endl;

    cout<<"Desear regresar al menu principal? (s/n): ";
    cin>>response;

    if (response == 's' || response == 'S') {
        crudHandler();
        return;
    }

    cout<<"Ingresa el identificador (id) del registro que deseas eliminar: ";
    cin>>idx;

    if (cin.fail()) {
        cout<<"El sistema no soporta caracteres especiales. Por favor ingresa un numero."<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout<<"Ingresa el identificador (id) del registro que deseas eliminar: ";
        cin>>idx;
    }

    while(fread(&translatedWord, sizeof(translatedWord), 1, file)) {
        if (currentId != idx) {
            fwrite(&translatedWord, sizeof(translatedWord), 1, tmp_file);
        }

        currentId++;
    }

    fclose(file);
    fclose(tmp_file);

    file = fopen(translatedWords_file, "wb");
    tmp_file = fopen(tmp_fileName, "rb");

    while (fread(&translatedWord, sizeof(translatedWord), 1, tmp_file)) {
        fwrite(&translatedWord, sizeof(translatedWord), 1, file);
    }

    fclose(file);
    fclose(tmp_file);

    cout<<"Desear regresar al menu principal ? (s/n): ";
    cin>>backHomeResponse;

    if (backHomeResponse == 's' || backHomeResponse == 'S') {
        crudHandler();
        return;
    }
}


void viewRegisterHandler() {
    char response;
    showTranslatedWordAdded();

    cout<<"Desear regresar al menu de manejo de traducciones ? (s/n): ";
    cin>>response;

    if (response == 's' || response == 'S') {
        crudHandler();
        return;
    }
}