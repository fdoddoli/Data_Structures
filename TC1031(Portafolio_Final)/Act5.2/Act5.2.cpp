/*
 * Programación de estructuras de datos y algoritmos fundamentales
 * Actividad 5.2 - Actividad integral sobre uso de códigos Hash
 * 
 * Equipo 13
 * 
 * Fernando Doddoli Lankenau - A00827038
 * Mauricio Eugenio Zambrano Díaz - A00827055
 * Cristóbal Alberto Escamilla Sada - A00827074
 * 
 * 28 de noviembre del 2020
 */

#include<fstream>
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

// Tipo de dato "registro": Almacena los datos de x dirección IP
struct registro{
    string mes;
    int dia;
    string hora;
    string razon;

    // Constructor de registro
    registro(string mes, int dia, string hora, string razon){
        this->mes = mes;
        this->dia = dia;
        this->hora = hora;
        this->razon = razon;
    }

    // Despliega el resumen del registro en pantalla
    // Complejidad: O(1)
    void print(){
        cout << "El " << dia << " de " << mes << " a las " << hora << " hubo un acceso fallido por: " << razon << endl;
    }
};

// Lee el archivo de entrada y almacena los datos en un unordered_map
// con la dirección IP como llave y un vector de registros como contenido
// Complejidad: O(n)
void leeArchivo(unordered_map< string, vector<registro> > &mapaHash){
    ifstream archivo("bitacoraACT5_2.txt");
    int dia;
    string mes, hora, ip, razon;

    while(archivo >> mes >> dia >> hora >> ip){
        getline(archivo, razon);
        razon = razon.substr(1);

        ip = ip.substr(0, ip.length()-5);

        mapaHash[ip].push_back(registro(mes, dia, hora, razon));
    }

    archivo.close();
}

// Despliega el número de accesos que tuvo la IP ingresada
// así como el resumen de cada acceso
// Complejidad: O(n)
void resumenIP(unordered_map< string, vector<registro> > mapaHash, string ip){
    cout << endl << "La IP " << ip << " tuvo " << mapaHash[ip].size() << " accesos fallidos:" << endl;

    for(int i = 0; i < mapaHash[ip].size(); i++)
        mapaHash[ip][i].print();
}

// Función principal mediante la cual se hacen los llamados a las funciones anteriores
int main(){
    unordered_map< string, vector<registro> > mapaHash;
    string ip;

    leeArchivo(mapaHash);

    do{
        cout << "\n(Teclee 0 cuando desee salir de la función).\nIngrese la dirección IP cuyo resumen desea consultar: ";

        cin >> ip;

        if(ip != "0")
            resumenIP(mapaHash, ip);

    } while(ip != "0");

    cout << endl;

    return 0;
}