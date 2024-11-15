#include "Persona.h"
#include <fstream>
#include <random>
#include <sstream>

using namespace std;

Persona::Persona(string nombre, string apellido, string direccion, 
                string adn, string ciudad, string telefono)
    : nombre(nombre), apellido(apellido), direccion(direccion), 
      adn(adn), ciudad(ciudad), telefono(telefono) {}

// Métodos para obtener los datos de la persona
string Persona::getNombre() const { return nombre; }
string Persona::getApellido() const { return apellido; }
string Persona::getDireccion() const { return direccion; }
string Persona::getADN() const { return adn; }
string Persona::getCiudad() const { return ciudad; }
string Persona::getTelefono() const { return telefono; }
string Persona::getNombreCompleto() const { return nombre + " " + apellido; }

// Función para leer el archivo y cargar los datos de personas
vector<Persona> leerArchivo(const string& nombreArchivo) {
    vector<Persona> personas;
    ifstream archivo(nombreArchivo);
    string linea;
    
    // Leerá cada línea del archivo
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, apellido, direccion, adn, ciudad, telefono;
        
        // Separar los campos por comas
        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        getline(ss, direccion, ',');
        getline(ss, adn, ',');
        getline(ss, ciudad, ',');
        getline(ss, telefono);
        
        // Crear un objeto Persona y agregarlo al vector
        personas.emplace_back(nombre, apellido, direccion, adn, ciudad, telefono);
    }
    
    return personas;
}

// Función para crear un grafo
vector<vector<int>> crearGrafo(int numNodos) {
    vector<vector<int>> grafo(numNodos, vector<int>(numNodos, 0));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    
     // Crear conexiones aleatorias entre los nodos
    for (int i = 0; i < numNodos; i++) {
        for (int j = i + 1; j < numNodos; j++) {
            if (dis(gen)) {
                grafo[i][j] = grafo[j][i] = 1;
            }
        }
    }
    return grafo;
}