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
    aux = 0;
    if(met == 1){
        for(int i = 0;i<sem;i++){
            if(palabra[i] == 48){
                aux++;
            }
        }
        for(int i = 0; i<sem; i++){
            if(palabra[i]==49){
                palabra[i]--;
            }
            else
                if(palabra[i]==48){
                    palabra[i]++;
                }
        }
        int aux1 = sem-aux;
        if(aux>aux1){
            aux = 2;
        }
        else
            if(aux<aux1){
                aux = 3;
            }
        else
                if(aux==aux1){
                    aux = 1;
                }
int aux2 = 1;
int aux3 = 0;
int cont = 0;
int a = 2;
for(int j = sem; palabra[j]==49 or palabra[j]==48; j++){
    if(palabra[j]==48){
        aux3++;
    }
    if(aux2%aux==0 and palabra[j]==48){
        palabra[j]++;
    }
    else
        if(aux2%aux==0 and palabra[j]==49){
            palabra[j]--;
        }
    aux2++;
    if(j == (a*sem)-1 and cont>0){
        aux1 = sem-aux3;
        if(aux3>aux1){
            aux = 2;
        }
        if(aux3<aux1){
            aux = 3;
        }
        if(aux3 == aux1){
            aux=1;
        }
        aux3 = 0;
        a +=1;
    }
    cont+=4;
}
fout.open("texto.txt");
for(int i = 0; palabra[i]== 48 or palabra[i]==49;i++){
    fout << palabra[i];
}
fout.close();
    }
    else
        if(met == 2){
            cout << palabra;
        }
    return 0;
}
