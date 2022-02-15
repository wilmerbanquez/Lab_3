#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char palabra[200];
    ofstream fout;
    ifstream fin;
    cout << "Ingrese una palabra: "; cin.getline(palabra, 200);
    int met; cout << "Ingrese el metodo de encriptacion (1 o 2): "; cin >> met;
    int sem; cout << "Ingrese la semilla: "; cin >> sem;
    fout.open("texto.txt");
    fout <<palabra;
    fout.close();
    fin.open("texto.txt");
    int i=0;
    while(fin.good())
    {
        char temp= fin.get();
        if(fin.good())
        {
            palabra[i]=temp;
        }
        i++;
    }
    fin.close();
    fout.open("texto.txt");
    int res;
    char bin[9];
    bin[8] = '\0';
    int aux = 7;
    for(int i = 0; palabra[i]!='\0';i++){
        while(palabra[i]>0){
            res = palabra[i]%2;
            palabra[i] = palabra[i]/2;
            bin[aux] = res + 48;
            aux--;
        }
        for(int i = 0;i<7;i++){
            if(bin[0] != 48 or bin[0]!= 49)
                bin[0] = 48;
        }
        fout << bin;
        aux = 7;
    }
    fout.close();
    fin.open("texto.txt");
    i=0;
    while(fin.good())
    {
        char temp= fin.get();
        if(fin.good())
        {
            palabra[i]=temp;
        }
        i++;
    }
    fin.close();
    if(met == 1){
        for(int i = 0; i<sem; i++){
            if(palabra[i]==49){
                palabra[i]--;
            }
            else
                if(palabra[i]==48){
                    palabra[i]++;
                }
        }

    }
    return 0;
}
