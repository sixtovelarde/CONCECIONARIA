#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct carro {
    int id;
    string marca;
    string modelo;
    int yer;
    string compradoA;
    string vendidoA;
    int preciovent;
    int preciocom;
    
};

struct cliente{
    int id;
    string nombre;
    string apellido;
    string email;
    int edad;
};

void aggcarro(ofstream archivocar){
    carro newcarro;
    cout<<"id del auto (a partir de 1001)"<<endl;
    cin>>newcarro.id;
    cout<<"Marca del auto"<<endl;
    cin>>newcarro.marca;
    cout<<"Año del auto"<<endl;
    cin>>newcarro.yer;

}

void verlistacarros(ifstream archivocli){
    carro carro;
    int comprados = 0;
    int vendidos =0;

}

int main(){
    
    ifstream archivo ("cars_data.txt");
    string linea;
    string texto;
    int id,marca;

    if (! archivo.is_open()) {
        cout<<"no se pudo abrir el archivo que contiene la informacion concecionaria"<<endl;
        return 1;
    }
        
    while (getline(archivo, linea)){
        texto=texto+linea+'\n';
    }
    cout<<texto<<endl;

    archivo.close();

    return 0;
}
