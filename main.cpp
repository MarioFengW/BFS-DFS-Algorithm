#include "Persona.h"
#include "BFS.h"
#include "DFS.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <iomanip>


using namespace std;

// Función para mostrar la información de una persona
void mostrarPersona(const Persona* persona) {
    if (persona) {
        cout << "\n=== Informacion de la persona encontrada ===" << endl;
        cout << "Nombre completo: " << persona->getNombreCompleto() << endl;
        cout << "Direccion: " << persona->getDireccion() << endl;
        cout << "Ciudad: " << persona->getCiudad() << endl;
        cout << "Telefono: " << persona->getTelefono() << endl;
        cout << "ADN: " << persona->getADN() << endl;
    } else {
        cout << "\nPersona no encontrada." << endl;
    }
}

int main() {
    // Leer los datos del archivo y crear el grafo
    vector<Persona> personas = leerArchivo("people.txt");
    vector<vector<int>> grafo = crearGrafo(personas.size());
    
    string adn;
    cout << "Ingrese el codigo de ADN a buscar: ";
    getline(cin, adn);

    cout << "\nBuscando..." << endl;

    // Busqueda con BFS y DFS
    auto inicioBFS = chrono::high_resolution_clock::now();
    Persona* resultadoBFS = bfs(grafo, personas, adn, true);
    auto finBFS = chrono::high_resolution_clock::now();
    auto duracionBFS = chrono::duration_cast<chrono::milliseconds>(finBFS - inicioBFS).count();

    auto inicioDFS = chrono::high_resolution_clock::now();
    Persona* resultadoDFS = dfs(grafo, personas, adn, true);
    auto finDFS = chrono::high_resolution_clock::now();
    auto duracionDFS = chrono::duration_cast<chrono::milliseconds>(finDFS - inicioDFS).count();

    // Mostrar resultado una sola vez
    mostrarPersona(resultadoBFS);

    // Mostrar tiempos y comparacion
    cout << "\n=== Tiempos de busqueda ===" << endl;
    cout << "BFS: " << duracionBFS << " ms" << endl;
    cout << "DFS: " << duracionDFS << " ms" << endl;

    long long diferencia = abs(duracionBFS - duracionDFS);
    string algoritmoRapido = (duracionBFS < duracionDFS) ? "BFS" : "DFS";
    cout << "\nEl algoritmo " << algoritmoRapido << " fue mas rapido por "
         << diferencia << " milisegundos" << endl;

    return 0;
}