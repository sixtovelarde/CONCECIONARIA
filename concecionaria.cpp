#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

struct carro {
    int id;
    string maker;
    string model;
    int year;
    string sold_to;
    string bought_to;
    int sold_for;
    int bought_for;
    bool vendido;
    string comprador;
};

struct cliente {
    int id;
    string first_name;
    string last_name;
    string email;
    int age;
};

//agregar carros
void aggcarro (ofstream& archivomod){
    carro newcarro;
    cout<<"id del auto (a partir de 1001)"<<endl;
    cin>>newcarro.id;
    cout<<"Marca del auto"<<endl;
    cin>>newcarro.maker;
    cout<<"Modelo del auto"<<endl;
    cin>>newcarro.model;
    cout<<"Año del auto"<<endl;
    cin>>newcarro.year;
    cout<<"Comprado a (age del comprador)"<<endl;
    cin>>newcarro.sold_to;
    cout<<"Vendido a (age de la persona a la que se le vendio)"<<endl;
    cin>>newcarro.bought_to;
    cout<<"Precio de venta"<<endl;
    cin>>newcarro.sold_for;
    cout<<"Precio de compra"<<endl;
    cin>>newcarro.bought_for;
    newcarro.vendido = false;
    archivomod<<"\n"<<newcarro.id<<";"<<newcarro.maker<<";"<<newcarro.model<<";"<<newcarro.year<<";"<<newcarro.sold_to<<";"<<newcarro.bought_to<<";"<<newcarro.sold_for<<";"<<newcarro.bought_for<<endl;
    cout<<"Carro agregado con exito"<<endl;
}
//ver lista
void verlistacarros (ifstream& archivoleer){
    carro carro;
    cliente cliente;
    int COMPRADOS = 0;
    int VENDIDOS = 0;

    cout<<"Lista de carros:\n";
    while (archivoleer>>carro.id>>carro.maker>>carro.year>>carro.sold_for>>cliente.first_name>>cliente.last_name){
        if (carro.vendido){
            cout<<carro.id<<", "<<carro.maker<<", "<<carro.year<<", "<<carro.sold_for<<".\n"<<"Vendido a:"<<cliente.first_name<<cliente.last_name<<"."<<endl;
            VENDIDOS++;
        }
        else {
            cout<<carro.id<<", "<<carro.maker<<", "<<carro.year<<endl;
            COMPRADOS++;
        }
    }
    cout<<"\nCarros comprados: "<<COMPRADOS<<endl;
    cout<<"Carros vendidos: "<<VENDIDOS<<endl;

}
//mostrar datos de un vendedor o comprador
void vervendedor(ifstream& archivoclileer) {
    string idvendedor;
    cout << "Ingrese el ID del cliente que desea buscar:\n";
    cin >> idvendedor;

    if (!archivoclileer.is_open()) {
        cout << "Error al abrir el archivo de clientes." << endl;
        return ;
    }

    string linea;
    while (getline(archivoclileer, linea)) {

        if (linea.substr(0, 4) == idvendedor) {
            cout << "Datos del vendedor:\n" << linea << endl;
        }
    }
}

//agregar cliente
void aggcliente(ofstream& archivoclimod) {
    cliente newcliente;
    cout<<"id del cliente (a partir de 101)\n";
    cin>>newcliente.id;
    cout<<"1er Nombre del cliente"<<endl;
    cin>>newcliente.first_name;
    cout<<"1er apellido del cliente"<<endl;
    cin>>newcliente.last_name;
    cout<<"ingrese Correo electronico del cliente"<<endl;
    cin>>newcliente.email;
    cout<<"Edad del cliente"<<endl;
    cin>>newcliente.age;
    archivoclimod<<"\n"<<newcliente.id<<";"<<newcliente.first_name<<";"<<newcliente.last_name<<";"<<newcliente.email<<";"<<newcliente.age<<endl;
    cout<<"cliente agregado con exito"<<endl;
}
//comparar perdidas y ganancias
void diferenciasventas(){
    carro carro;
    
}

int main(){

    ofstream archivomod("cars_data.csv", ios::app);//1 agregar carros
    ifstream archivoleer("cars_data.csv");//2 ver lista de carros

    ofstream archivoclimod("clients.csv", ios::app);
    ifstream archivoclileer("clients.csv");//3 buscar vendedor

    if (!archivomod.is_open() || !archivoleer.is_open() || !archivoclileer.is_open() || !archivoclimod.is_open()) {
        cout<<"Error al abrir el archivo cars_data.csv"<<endl;
        return 1;
    }
    int opcion;
    cout<<"1. Agregar carro\n2. Mostrar lista de carros\n3. Mostrar informacion de un cliente\n4. Agregar un cliente"<<endl;
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
        case 4:
            aggcliente(archivoclimod);
            break;
        default:
            cout<<"Error elija otra opcion.."<<endl;
            break;
    }

    archivomod.close();//1
    archivoleer.close();//2
    
    archivoclimod.close();//4
    archivoclileer.close();//3

    return 0;
}