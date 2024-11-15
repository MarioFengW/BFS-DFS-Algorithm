#ifndef BFS_H
#define BFS_H

#include "Persona.h"
#include <vector>

using namespace std;

Persona* bfs(const vector<vector<int>>& grafo, 
            vector<Persona>& personas, 
            const string& criterio,
            bool buscarPorADN);

#endif