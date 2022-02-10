#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char palabra[200];
    ofstream fout;
    ifstream fin;
    cout << "Ingrese una palabra: "; cin.getline(palabra, 200);
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
        cout << bin;
        aux = 7;
    }
    return 0;
}
