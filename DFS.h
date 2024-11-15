#ifndef DFS_H
#define DFS_H

#include "Persona.h"
#include <vector>

using namespace std;

Persona* dfs(const vector<vector<int>>& grafo, 
            vector<Persona>& personas, 
            const string& criterio,
            bool buscarPorADN);

#endif