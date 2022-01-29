#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Arc;
typedef vector<vector<Arc>> Graf;

int prim(Graf& g, int n) {

    vector<bool> vis(n,false);
    vis[0] = true;
    int nvis = 1;               //numero de vertexs visitats

    priority_queue<Arc,vector<Arc>,greater<Arc>> pq;
    for(Arc x : g[0]) pq.push(x);

    int cost_MST = 0;

    while(nvis < n){
        int cost = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if(not vis[v]){
            for(Arc p: g[v]) {
                if(not vis[p.second]) pq.push(p);
            }
            vis[v] = true;
            ++nvis;
            cost_MST += cost;
        }
    }
    return cost_MST;
}

int main(){
    int n,m;
    while(cin >> n >> m) {
        
        Graf g(n);
        for(int i = 0; i < m; ++i){
            int u,v,w;
            cin >> u >> v >> w;

            g[u-1].push_back({w,v-1});
            g[v-1].push_back({w,u-1});
        }
        cout << prim(g,n) << endl;
    }
}