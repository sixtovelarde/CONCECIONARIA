#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    
    ifstream archivo ("pruebaleer.txt");

    if (! archivo.is_open()) {
        cout<<"no se pudo abrir el archivo que contiene la informacion concecionaria"<<endl;
        return 1;
    }
        string linea;
    while (getline(archivo, linea)){
        cout<<linea<<endl;
    }

    archivo.close();

    return 0;
}
