#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Arc;      //Primer es el cost, Second es el vertex adjacent
typedef vector<vector<Arc>> Graf;

int retallada(const Graf& g, int n){
    int suma = 0;
    priority_queue<Arc,vector<Arc>, greater<Arc>> pq;
    vector<bool> vis(n,false);
    vis[0] = true;
    int numv = 1;

    for(int i = 0; i < g[0].size(); ++i) pq.push(g[0][i]);      //Li posem totes les adjacencies del vertex 0

    while(numv < n){
        Arc u = pq.top();
        pq.pop();
        if(not vis[u.second]){
            suma += u.first;
            ++numv;
            vis[u.second] = true;
            for(int i = 0; i < g[u.second].size(); ++i){             
                Arc v = g[u.second][i];                        //Afegim totes les adjacencies del vertex que hem visitat
                pq.push(v);
            }
        }
    }
    return suma;
}

int main(){
    int n,m;
    while(cin >> n >> m){
        Graf g(n);
        int total = 0;

        for(int i = 0; i < m; ++i){
            int x,y,c;
            cin >> x >> y >> c;
            g[x].push_back({c,y});
            g[y].push_back({c,x});
            total += c;
        }

        int suma = retallada(g,n);
        cout << total - suma << endl;
    }
}

/* VERSIO 2 - Es la misma pero canviando el codigo del for, en esta esta de forma moderna
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Arc;
typedef vector<vector<Arc>> Graf;

int retallades(Graf& g, int n) {
    vector<bool> vis(n,false);
    vis[0] = true;
    int nvis = 1;       //Nombre de vertexs visitats

    priority_queue<Arc, vector<Arc>, greater<Arc>> pq;
    for(Arc uv : g[0]) pq.push(uv);
    int cost_min = 0;

    while(nvis < n){
        int v = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(not vis[v]){
            vis[v] = true;
            ++nvis;
            cost_min += cost;
            for(Arc vx : g[v]) {
                if(not vis[vx.second]) pq.push(vx);
            }
        }
    }
    return cost_min;
}

int main() {
    int n,m;
    while(cin >> n >> m){
        Graf g(n);
        int cost_total = 0;
        for(int i = 0; i < m ; ++i){
            int x,y,c;
            cin >> x >> y >> c;
            g[x].push_back({c,y});
            g[y].push_back({c,x});
            cost_total += c;
        }

        cout  << cost_total - retallades(g,n) << endl;
    }
}
*/