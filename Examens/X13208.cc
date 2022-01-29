#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef vector<vector<int>> Mapa;
typedef pair<int,int> Pos;
typedef pair<int,Pos> Dist_pos;

const int infinit = INT_MAX;
const vector<Pos> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};

bool es_vorera(Pos p,int n) {
    return (p.first == 0 or p.second == 0 or p.first == n-1 or p.second == n-1);
}

int dijkstra(Mapa& mat, int n){

    Mapa suma(n,vector<int>(n,infinit));
    priority_queue<Dist_pos,vector<Dist_pos>,greater<Dist_pos>> pq;

    Pos inici = {n/2,n/2};
    pq.push({mat[n/2][n/2],inici});
    suma[n/2][n/2] = mat[n/2][n/2];

    while(not pq.empty()){
        Pos act = pq.top().second;
        pq.pop();

        if(es_vorera(act,n)) return suma[act.first][act.second];
        for (int i = 0; i < 4; ++i) {
            Pos seg;
			seg.first = act.first + dir[i].first;
			seg.second = act.second + dir[i].second;

            if(suma[seg.first][seg.second] > suma[act.first][act.second] + mat[seg.first][seg.second]) {
                suma[seg.first][seg.second] = suma[act.first][act.second] + mat[seg.first][seg.second];
                pq.push({suma[seg.first][seg.second],seg});
            }
            
        }
    }
    return 0;
}

int main(){
    int n;
    while(cin >> n) {
        Mapa mat(n,vector<int>(n));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) cin >> mat[i][j];
        }

        cout << dijkstra(mat,n) << endl;
    }




}

