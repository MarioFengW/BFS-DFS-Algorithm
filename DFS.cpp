#include "DFS.h"
#include <stack>

using namespace std;

Persona* dfs(const vector<vector<int>>& grafo, 
            vector<Persona>& personas, 
            const string& criterio,
            bool buscarPorADN) {
    
    vector<bool> visitado(personas.size(), false);
    stack<int> pila;
    
    // Iniciar la búsqueda desde el primer nodo
    pila.push(0);
    
    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();
        
        if (!visitado[actual]) {
            visitado[actual] = true;
            
            // Verificar si es la persona buscada
            if (buscarPorADN) {
                if (personas[actual].getADN() == criterio) {
                    return &personas[actual];
                }
            } else {
                if (personas[actual].getNombre() == criterio) {
                    return &personas[actual];
                }
            }
            
            // Agregar los nodos adyacentes a la pila
            for (int i = grafo[actual].size() - 1; i >= 0; i--) {
                if (grafo[actual][i] && !visitado[i]) {
                    pila.push(i);
                }
            }
        }
    }
    
    return nullptr;
}