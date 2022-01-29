#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> Arcp; // first = dist , second = adyacente
typedef vector<vector<Arcp>> Graf;

const int infinit = INT_MAX;

int dijkstra(const Graf& g, int ini, int fin) {
	int n = g.size();
	vector<bool> vis(n, false);
	priority_queue<Arcp, vector<Arcp>, greater<Arcp>> Q;
	vector<int> dist(n, infinit);
	
	dist[ini] = 0;
	Q.push({0, ini});
	
	while (not Q.empty()) {
		Arcp act = Q.top();
		int u = act.second;
		Q.pop();
		if (act.second == fin) return dist[act.second];
		else if (not vis[act.second]) {
			vis[act.second] = true;
			for (Arcp seg: g[act.second]) {
				int v = seg.second;
				int c = seg.first;
				int d_max = max(dist[u], c);
				if (d_max < dist[v]) {
					dist[v] = d_max;
					Q.push({d_max, v});
				}
			}
		}
	}
	return infinit;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Graf g(n);
		for (int i = 0; i < m; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			g[u].push_back({c, v});
		}
		cout << dijkstra(g, 0, 1) << endl;
	}
}

