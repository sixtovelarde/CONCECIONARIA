#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//como hacer una estructura de una persona (hacer antes del int)
struct persona{
    string nombre;
    int ci;
};
/*Creación de una instancia de persona: 
Se crea una instancia de persona llamada p1 y se le asignan valores a sus miembros.
 El nombre se establece en “tu nombre” y ci se establece en "ci".*/
int main (){
    persona p1;
    p1.nombre="sixto";
    p1.ci=30901576;
    //como abrir y crear un archivo binario "nombre.bin" en modo escritura
    fstream fs;
    fs.open("archivo_prueba.bin",ios::binary|ios::out);
    if(!fs.is_open()){
        cout<<"archivo no encontrado"<<endl;
        //escribir dentro del archivo
        fs.write((char*)&p1,sizeof(p1));
    }
    //cerrar archivo
    fs.close();
}