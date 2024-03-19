/*Una concesionaria quiere un programa para administrar los datos de los carros usados que compra.
En la reunión con los dueños estos fueron los requisitos que se mencionaron para la primera etapa.

• Se debe de mostrar los carros comprados o vendidos a un cliente, como una lista, ejemplo:

Carros comprados: 2
Carros vendidos: 1

Lista de carros comprados:

Chevrolet Optra, 2004
Ford festiva, 2000

Lista de carros vendidos:

Chevrolet Camaro, 2011

• Mostrar los datos del vendedor o comprador de un carro.

• Agregar información de un carro comprado y modificar su información si ha sido vendido (agregar información del cliente también)

• Eliminar datos de un carro o cliente.

• Mostrar si en la compra y venta de un carro se ha tenido pérdidas o ganancias, y cuánto es la diferencia.
los carros no vendidos se consideran perdidas hasta venderlos.
*/
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
