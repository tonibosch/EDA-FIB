#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef vector<set<int>> Graf; // guardamos un set para tener las adyacencias ordenadas
 
void escribir_camino(const vector<int> &camino, int i) {
    int n = camino.size();
    if (i != -1) {
        escribir_camino(camino, camino[i]);
        if (i == 0) cout << i;
        else cout << ' ' << i;
    }
}

void bfs(Graf &grafo, vector<int> &camino) {
    int n = grafo.size();
    vector<int> distancia(n, -1);
    distancia[0] = 0;
    queue<int> Q;
    Q.push(0);
 	bool fin = false;
    while (not Q.empty() and not fin) {
        int u = Q.front();
        Q.pop();
        if (u == n - 1) fin = true;
        else {
        	int m = grafo[u].size();
        	//set<int>::const_iterator it;
        	for (auto it = grafo[u].begin(); it != grafo[u].end(); it++) {
        		int v = *it;
	            if (distancia[v] == -1) {
	                distancia[v] = distancia[u] + 1;
	                camino[v] = u;
	                Q.push(v);
	            }
	        }
        }
    }
}
 
int main() {
    int n, m;
    while (cin >> n >> m) {
        Graf grafo(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            grafo[u].insert(v);
        }
        vector<int> camino(n, -1);
        bfs(grafo, camino);
        escribir_camino(camino, n - 1);
        cout << endl;
    }
}
