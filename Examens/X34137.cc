#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Graf;

void dfs(const Graf& g, int u, vector<bool>& vis) {
	if (not vis[u]) {
		vis[u] = true;
		for (int w: g[u])
			dfs(g, w, vis);
	}
}

int main () {
    int n, u, v, m;
    while (cin >> n >> u >> v >> m) {
        Graf g(n);
        Graf g_inv(n); //Per desfer el cami
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            g[x].push_back(y); //Vertex que va de x a y.
            g_inv[y].push_back(x);
        }
        vector<bool> vis_u(n, false);
		dfs(g, u, vis_u); //Fem un dfs des de u a tots els vertex del graf
		if (not vis_u[v]) cout << 0 << endl; //Si no hem visitat el vertex v, vol dir que no hi ha cami de u a v.
		else {
			vector<bool> vis_v(n, false); 
			dfs(g_inv, v, vis_v); //Fem un dfs de v a tots els vertex amb el graf invertit per saber si hi ha cami de tornada
			int cont = 0; //Contem les maneres d'anar de u a v passant per un mateix vertex
			for (int i = 0; i < n; ++i) {
				if (vis_u[i] and vis_v[i] and i != u and i!= v) ++cont; //Si el vertex l'hem visitat anant de u a v i de v a u i són diferents que ells mateixos es a dir, de u i v, sumem 1.
			}
			cout << cont << endl;
		}
	}
}
