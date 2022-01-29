#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, 1, 0, -1};

const int infinit = INT_MAX;

typedef vector<vector<char>> Tablero;
typedef vector<vector<int>> VVI;
typedef pair<int,int> parint;

bool pos_ok(int x, int y, int n, int m) {
	return x >= 0 and x < n and y >= 0 and y < m;
}

parint bfs(Tablero& tab,int n, int m){

    VVI dist(n,vector<int>(m,infinit));
    VVI pers(n,vector<int>(m,-1));

    queue<parint> q;
    q.push({0,0});

    dist[0][0] = 0;
    pers[0][0] = 0;
    if(tab[0][0] == 'P') ++pers[0][0];

    while(not q.empty()){
        parint act = q.front();
        q.pop();

        if(tab[act.first][act.second] == 'T') {
            return {dist[act.first][act.second],pers[act.first][act.second]};
        }
        for(int i = 0; i < 4; ++i){
            int x,y;
            x = act.first + X[i];
            y = act.second + Y[i];

            if(pos_ok(x,y,n,m) and tab[x][y] != '#') {
                int d = dist[act.first][act.second];
                int np = pers[act.first][act.second];

                if(tab[x][y] == 'P') ++np;
                if(dist[x][y] == infinit) {
                    q.push({x,y});
                    dist[x][y] = d + 1;
                    pers[x][y] = np;
                }
                else if(dist[x][y] == d+1 and pers[x][y] < np){
                    pers[x][y] = np;
                }
            }
        }
    }   
    return {-1,-1}; 
}

int main() {
    int n,m;
    while(cin >> n >> m){
        Tablero tab(n,vector<char>(m));

        bool hi_ha_telecos = false;
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < m; ++j) {
                cin >> tab[i][j];
                if(tab[i][j] == 'T') hi_ha_telecos = true;
            }
        }

        if(not hi_ha_telecos) cout << "El telecos ha fugit." << endl;
        else if(tab[0][0] == 'T') cout << "0 0" << endl;
        else {
            parint res = bfs(tab,n,m); //res.first = distancia minima; res.second = num persona max
			if (res.first == -1) cout << "El telecos esta amagat." << endl;
			else cout << res.first << ' ' << res.second << endl;
        }
    }
}