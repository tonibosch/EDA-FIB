#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Pos;
typedef vector<vector<int>> Mapa;
const Pos salts[8] =  {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

bool pos_ok(Pos p, int n, int m){
    return (p.first >= 0 and p.first < n and p.second >= 0 and p.second < m);
}

int bfs(int n, int m, Pos ini, Pos fin){
    Mapa dist(n,vector<int>(m,-1));
    queue<Pos> q;

    q.push(ini);
    dist[ini.first][ini.second] = 0;

    while(not q.empty()){
        Pos act = q.front();
        q.pop();
        if(act == fin) return dist[act.first][act.second];
        for(int i = 0; i < 8; ++i){
            Pos seg;
            seg.first = act.first + salts[i].first;
            seg.second = act.second + salts[i].second;
            if(pos_ok(seg,n,m) and dist[seg.first][seg.second] == -1) {
                dist[seg.first][seg.second] = dist[act.first][act.second] + 1;
                q.push(seg);
            }
        }
    }
    return -1;
}

int main(){
    int n,m,W,L,k;
    while(cin >> n >> m >> W >> L >> k){
        vector<Pos> pos(k+1);
        pos[0] = {0,0};
        for(int i = 1; i < k+1; ++i) cin >> pos[i].first >> pos[i].second;
        int suma_punt = 0;
        int max = 0;
        bool fin = false;
        int i = 0; 
        while(i < k and not fin) {
            int dist = bfs(n,m, pos[i], pos[i+1]);
            if(dist == -1) fin = true;
            else {
                suma_punt = suma_punt + W - (L*dist);
                if(suma_punt > max) max = suma_punt;
            }
            ++i;
        }
        cout << max << endl;
    }
}