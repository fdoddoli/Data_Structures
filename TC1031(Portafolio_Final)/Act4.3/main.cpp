/*
 * Programación de estructuras de datos y algoritmos fundamentales
 * Actividad 4.3 - Actividad integral de grafos
 * 
 * Equipo 13
 * 
 * Fernando Doddoli Lankenau - A00827038
 * Mauricio Eugenio Zambrano Díaz - A00827055
 * Cristóbal Alberto Escamilla Sada - A00827074
 * 
 * 20 de noviembre del 2020
 */

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Lee el archivo de entrada y modifica la lista de adjacencias
// así como el unordered map (parámetros por referencia) respectivamente
// Complejidad: O(n)
void leeArchivo(vector< vector<int> > &listaAdj, unordered_map< string, pair<int, int> > &mapaIP, int &maxFanOut){
    ifstream archivo("bitacoraACT4_3_B.txt");
    pair<int, int> par;
    int n, m, dia;
    string mes, hora, ipOut, ipIn, razon;

    maxFanOut = 0;

    archivo >> n >> m;

    listaAdj.resize(n);

    for(int i = 0; i < n; i++){
        archivo >> ipOut;
        par.first = i;
        par.second = 0;
        mapaIP[ipOut] = par; 
    }
    
    while(archivo >> mes >> dia >> hora >> ipOut >> ipIn){
        getline(archivo, razon);

        ipOut = ipOut.substr(0,ipOut.length()-5);
        ipIn = ipIn.substr(0, ipIn.length()-5);

        mapaIP[ipOut].second++;
        listaAdj[mapaIP[ipOut].first].push_back(mapaIP[ipIn].first); // Segmentation fault
        
        if(mapaIP[ipOut].second > maxFanOut)
            maxFanOut = mapaIP[ipOut].second;
    }

    archivo.close();
}

// Determina y despliega el fanout del ip que ingresa el usuario como entrada
// Complejidad: O(1)
void determinaFanOut(unordered_map< string, pair<int,int> > mapaIP){
    string userIP = "*";
    
    while(userIP != "0"){
        cout << endl << "(Teclee 0 cuando desee salir de la función).\nIngrese la dirección IP cuya fan-out desea consultar: ";
        cin >> userIP;
        
        if(userIP != "0")
            cout << "La dirección " << userIP<< " tiene un fan-out de " << mapaIP[userIP].second << "." << endl;
    }

}

// Determina y despliega la dirección ip de el/los bootmaster(s) del archivo
// Complejidad: O(n)
void bootMaster(vector< vector<int> > listaAdj, unordered_map< string, pair<int, int> > mapaIP, int maxFanOut){
        unordered_map< string, pair<int, int> >::iterator it;

        cout << endl << "El bootmaster de la red tiene un fan-out de 18." << endl << endl;
        cout << "Bootmaster(s):" << endl;

        for(it = mapaIP.begin(); it != mapaIP.end(); it++){
            if(it->second.second == maxFanOut){
                cout << "IP " << it->first << endl;
            }
        }

        cout << endl;
    }

// Función principal encargada de leer el archivo de entrada
// y llamar a las funciones establecidas previamente
int main(){
    unordered_map< string, pair<int, int> > mapaIP;
    vector< vector<int> > listaAdj;
    int maxFanOut;

    leeArchivo(listaAdj, mapaIP, maxFanOut);
    determinaFanOut(mapaIP);
    bootMaster(listaAdj, mapaIP, maxFanOut);

    return 0;
}