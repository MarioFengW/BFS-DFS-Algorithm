#include "BFS.h"
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

Persona* bfs(const vector<vector<int>>& grafo, 
            vector<Persona>& personas, 
            const string& criterio,
            bool buscarPorADN) {
    
    vector<bool> visitado(personas.size(), false);
    queue<int> cola;
    
    // Iniciar la busqueda desde la primera persona
    cola.push(0);
    visitado[0] = true;
    
    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        
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

        // Agregar los nodos adyacentes a la cola
        for (int i = 0; i < grafo[actual].size(); i++) {
            if (grafo[actual][i] && !visitado[i]) {
                cola.push(i);
                visitado[i] = true;
            }
        }
    }
    
    return nullptr;
}