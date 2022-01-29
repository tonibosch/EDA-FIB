#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
typedef vector<vector<int>> Grafo;

bool es_ciclic(const Grafo& g) {
	int n = g.size();
	vector<int> ge(n, 0);
	
	for (int i = 0; i < n; ++i) {
		for (int v: g[i]) 
			++ge[v];
	}
	queue<int> Q;
	for (int i = 0; i < n; ++i) {
		if (ge[i] == 0) Q.push(i);
	}
	while (not Q.empty()) {
		int u = Q.front();
		Q.pop();
		--n; //hemos visitado un vertice nuevo
		for (int v: g[u]) {
			--ge[v];
			if (ge[v] == 0) Q.push(v);
		}
	}
	return n > 0;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Grafo g(n);
		
		int x, y;
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			g[x].push_back(y); //x es adyacente a y
		}
		if (es_ciclic(g)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}


