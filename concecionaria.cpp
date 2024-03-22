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
    bool vendido;
    string comprador;
};

struct cliente{
    int idcliente;
    string nombre;
    string apellido;
    string email;
    int edad;
};
//agregar cliente
void aggcliente (ofstream& archivoclimod){
    cliente newcliente;
    cout<<"id del cliente (a partir de 101)"<<endl;
    cin>>idcliente;
    

}
//agregar carros
void aggcarro (ofstream& archivomod){
    carro newcarro;
    cout<<"id del auto (a partir de 1001)"<<endl;
    cin>>newcarro.id;
    cout<<"Marca del auto"<<endl;
    cin>>newcarro.marca;
    cout<<"Modelo del auto"<<endl;
    cin>>newcarro.modelo;
    cout<<"Año del auto"<<endl;
    cin>>newcarro.yer;
    cout<<"Comprado a (edad del comprador)"<<endl;
    cin>>newcarro.compradoA;
    cout<<"Vendido a (edad de la persona a la que se le vendio)"<<endl;
    cin>>newcarro.vendidoA;
    cout<<"Precio de venta"<<endl;
    cin>>newcarro.preciovent;
    cout<<"Precio de compra"<<endl;
    cin>>newcarro.preciocom;
    newcarro.vendido = false;
    archivomod<<"\n"<<newcarro.id<<";"<<newcarro.marca<<";"<<newcarro.modelo<<";"<<newcarro.yer<<";"<<newcarro.compradoA<<";"<<newcarro.vendidoA<<";"<<newcarro.preciovent<<";"<<newcarro.preciocom<<endl;



}
//ver lista
void verlistacarros (ifstream& archivoleer){
    carro carro;
    cliente cliente;
    int COMPRADOS = 0;
    int VENDIDOS = 0;

    cout<<"Lista de carros:\n";
    while (archivoleer>>carro.id>>carro.marca>>carro.yer>>carro.preciovent>>cliente.nombre>>cliente.apellido){
        if (carro.vendido){
            cout<<carro.id<<", "<<carro.marca<<", "<<carro.yer<<", "<<carro.preciovent<<".\n"<<"Vendido a:"<<cliente.nombre<<cliente.apellido<<"."<<endl;
            VENDIDOS++;
        }
        else {
            cout<<carro.id<<", "<<carro.marca<<", "<<carro.yer<<endl;
            COMPRADOS++;
        }
    }
    cout<<"\nCarros comprados: "<<COMPRADOS<<endl;
    cout<<"Carros vendidos: "<<VENDIDOS<<endl;

}
//mostrar datos de un vendedor o comprador
void vervendedor(ifstream& archivoclileer) {
    string idvendedor;
    cout << "Ingrese el ID del vendedor que desea buscar:\n";
    cin >> idvendedor;

    if (!archivoclileer.is_open()) {
        cout << "Error al abrir el archivo de clientes." << endl;
        return;
    }

    string linea;
    while (getline(archivoclileer, linea)) {
        if (linea.find(idvendedor) != string::npos) {
            cout << "Datos del vendedor:\n" << linea << endl;
        }
    }
}

int main(){

    ofstream archivomod("cars_data.txt", ios::app);//1 agregar carros
    ifstream archivoleer("cars_data.txt");//2 ver lista de carros

    ofstream archivoclimod("clients.txt", ios::app);
    ifstream archivoclileer("clients.txt");//3 buscar vendedor

    if (!archivomod.is_open() || !archivoleer.is_open()) {
        cout<<"Erroro al abrir el archivo cars_data.txt"<<endl;
        return 1;
    }
    int opcion;
    cout<<"1. Agregar carro\n2. Mostrar lista de carros\n3. Mostrar informacion de un vendedor"<<endl;
    cin>> opcion;

    switch (opcion){
        case 1:
            aggcarro(archivomod);
            break;
        case 2:
            verlistacarros(archivoleer);
            break;
        case 3:
            vervendedor(archivoclileer);
            break;
        default:
            cout<<"Error elija otra opcion."<<endl;
            break;
    }

    archivomod.close();//1
    archivoleer.close();//2
    

    archivoclileer.close();//3

    return 0;
}