#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Matriu;
typedef vector<bool> FB;
typedef vector<FB> MB;
typedef pair<int,int> Pos;

const vector<Pos> dirs_cavall = {{-1,2},{-2,1},{1,2},{-1,-2},{2,1},{2,-1},{1,-2},{-2,-1}}; //Conte els 8 possibles moviments que pot fer un cavall
const vector<Pos> dirs_alfil = {{1,1},{-1,-1},{-1,1},{1,-1}}; //Conte els 4 possibles moviments que pot fer un alfil

bool pos_ok(int i, int j, int n, int m) {
    return 0 <= i and i < n and 0 <= j and j < m;
}

int bfs(int n, int m, Pos p, Matriu& taulell, vector< vector<bool> >& vis, const vector<Pos>& dirs, int num_dirs) {
    int monedes = 0;
    vis[p.first][p.second] = true;
    for (int i = 0; i < num_dirs; ++i) {
        Pos seg;
        seg.first = p.first + dirs[i].first;
        seg.second = p.second + dirs[i].second;
        if (pos_ok(seg.first,seg.second,n,m) and taulell[seg.first][seg.second] != 'T' and not vis[seg.first][seg.second])
            monedes += bfs (n, m, seg, taulell, vis, dirs, num_dirs);
    }
    if ('0' <= taulell[p.first][p.second] and taulell[p.first][p.second] <= '9') {
        monedes += taulell[p.first][p.second] - '0';
        taulell[p.first][p.second] = '.';
    }
    return monedes;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Matriu taulell (n, Fila(m));
        vector<Pos> pos_cavalls;
        vector<Pos> pos_alfils;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> taulell[i][j];
                if (taulell[i][j] == 'K') pos_cavalls.push_back({i,j});
                if (taulell[i][j] == 'B') pos_alfils.push_back({i,j});
            }
        }

        int monedes = 0;
        MB vis_cavalls(n, FB(m, false));
        for (int i = 0; i < pos_cavalls.size(); ++i) {
            Pos p = pos_cavalls[i];
            if (not vis_cavalls[p.first][p.second]) {
                monedes += bfs(n, m, p, taulell, vis_cavalls, dirs_cavall, 8);
            }
        }

        MB vis_alfils(n, FB(m, false));
        for (int i = 0; i < pos_alfils.size(); ++i) {
            Pos p = pos_alfils[i];
            if (not vis_alfils[p.first][p.second]) {
                monedes += bfs(n, m, p, taulell, vis_alfils, dirs_alfil, 4);
            }
        }
        cout << monedes << endl;
    }
}