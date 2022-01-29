#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

const int infinit = INT_MAX;

typedef pair<int,int> Arc;
typedef vector<vector<Arc>> Graf;

int dijkstra(const Graf& g,const vector<int>& cost_nit, int a, int b, int n){

    vector<int> dist(n,infinit);
    dist[a] = 0;

    vector<bool> vis(n,false);

    priority_queue<Arc, vector<Arc>, greater<Arc>> pq;
    pq.push({0,a});
    int cost_total = 0;

    while(not pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(not vis[u]){
            vis[u] = true;
            if(u == b) return dist[u];

            for(Arc x: g[u]){
                int v = x.second;
                int c = x.first;

                if(v != b) c += cost_nit[v];
                if(dist[v] > dist[u] + c){
                    dist[v] = dist[u] + c;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    if(cost_total == 0) return -1;
    return cost_total;
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> cost_nit(n);
    for(int i = 0; i < n; ++i) cin >> cost_nit[i];

    Graf g(n);
    for(int i = 0; i < m; ++i) {
        int u,v,c;
        cin >> u >> v >> c;
        g[u].push_back({c,v});
        g[v].push_back({c,u});
    }

    int a,b;
    while(cin >> a >> b){
        int cost = dijkstra(g,cost_nit,a,b,n);
        cout << "c(" << a << "," << b << ") = ";
        if(cost == -1) cout << "+oo" << endl;
        else cout << cost << endl;
    }
}