/*Una concesionaria quiere un programa para administrar los datos de los carros usados que compra. En la reunion con los duenos estos fueron
los requisitos que mencionaron para la primera etapa.

*Se debe de mostrar los carros comprados o vendidos a un cliente, como una lista, ejemplo:

 carros comprados: 2
 carros vendidos: 1

Lista de carros comprados:

 Chevrolet Optra, 2004
 Ford Festiva, 2000

Lista de carros vendidos:

 Chevrolet Camaro, 2011

1. Mostrar los datos del vendedor o comprador de un carro.
2. Agregar informacion de un carro comprado y modificar sun informacion si ha sido vendido (agregar informacion del cliente tambien)
3. Eliminar datos de un carro o cliente.
4. Mostrar si en la compra y venta de un carro se ha ytenido perdidas o ganancias, y cuanto es la diferencia. (Los carros no vendidos se consideran
perdidas hasta venderlos)
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream archivo ("cars_data.txt");

    if (!archivo.is_open()){
        cout<<"no se pudo abrir el archivo que contiene la informacion de los autos"<<endl;
        return 1;
    }
        string linea;
    while (getline(archivo, linea)){
        cout<< linea<<endl;
    }
    archivo.close();

    return 0;
}
