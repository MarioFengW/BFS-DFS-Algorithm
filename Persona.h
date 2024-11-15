#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <vector>

using namespace std;

class Persona {
private:
    // Atributos
    string nombre;
    string apellido;
    string direccion;
    string adn;
    string ciudad;
    string telefono;

public:
    // Constructor
    Persona(string nombre, string apellido, string direccion, 
            string adn, string ciudad, string telefono);
    
    // Métodos
    string getNombre() const;
    string getApellido() const;
    string getDireccion() const;
    string getADN() const;
    string getCiudad() const;
    string getTelefono() const;
    string getNombreCompleto() const;
};

// Función para leer un archivo de texto
vector<Persona> leerArchivo(const string& nombreArchivo);

// Función para crear un grafo
vector<vector<int>> crearGrafo(int numNodos);

#endif