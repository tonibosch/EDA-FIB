#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Mapa;
typedef pair<int,int> Pos;

const Pos dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

bool pos_ok(int x, int y, int n, int m){
    return (x >= 0 and x < n and y >= 0 and y < m);
}

int bfs(Mapa& mapa, int n, int m, int f, int c){

    vector<vector<int>> dist(n,vector<int>(m,-1));
    dist[f][c] = 0;

    queue<Pos> q;
    q.push({f,c});

    vector<Pos> tresors;
    int ntresors = 0;

    while(not q.empty()) {
        Pos act = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i) {
            Pos seg;
            seg.first = act.first + dir[i].first;
            seg.second = act.second + dir[i].second;

            if(pos_ok(seg.first,seg.second,n,m) and dist[seg.first][seg.second] == -1 and mapa[seg.first][seg.second] != 'X'){
                dist[seg.first][seg.second] = dist[act.first][act.second] + 1; 

                if(mapa[seg.first][seg.second] == 't') {
                    ++ntresors;
                    tresors.push_back({seg.first,seg.second});
                }
        
                mapa[seg.first][seg.second] = 'X';
                q.push(seg);
            }
        }
    }
    if(ntresors < 2) return 0;
    else {
        int mida = tresors.size();
        Pos p = tresors[mida-2];
        return dist[p.first][p.second];
    }
}

int main() {
    int n,m;
    cin >> n >> m;

    Mapa mapa(n,vector<char>(m));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cin >> mapa[i][j];
    }

    int f,c;
    cin >> f >> c;

    int res = bfs(mapa,n,m,f-1,c-1);
    if(res == 0) cout << "no es pot arribar a dos o mes tresors" << endl;
    else cout << "segona distancia maxima: " << res << endl;
}