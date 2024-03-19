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
    string marca;
    string comprador;
    int yer;
    int precio;
    int vendido;
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
