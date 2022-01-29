#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Pos;

const int X[4] = {1,0,-1,0};
const int Y[4] = {0,1,0,-1};

bool pos_ok(int i, int j, int n, int m){
    return (i >= 0 and i < n and j >= 0 and j < m);
}

bool bfs(vector<vector<char>>& t, Pos ini, int n, int m){
    queue<Pos> Q;
    Q.push(ini);

    while(not Q.empty()){
        Pos act = Q.front();
        Q.pop();

        for(int i = 0; i < 4; ++i){
            Pos seg;
            seg.first = act.first + X[i];
            seg.second = act.second + Y[i];
            if(pos_ok(seg.first,seg.second,n,m) and t[seg.first][seg.second] == 'F') return true;
            if(pos_ok(seg.first,seg.second,n,m) and t[seg.first][seg.second] == '.' ) {
                Q.push({seg.first,seg.second});
                t[act.first][act.second] = 'X';
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    while(cin >> n >> m){
        Pos ini;
        queue<Pos> cua_monstres;
        vector<vector<char>> t(n,vector<char> (m));

        //Legim tota la matriu
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j) {
                cin >> t[i][j];
                if(t[i][j] == 'I') ini = {i,j};
                else if(t[i][j] == 'M') cua_monstres.push({i,j});
            }
        }

        
        while(not cua_monstres.empty()){
            Pos act = cua_monstres.front();
            cua_monstres.pop();

            for(int i = 0; i < 4; ++i){
                Pos seg;
                seg.first = act.first + X[i];
                seg.second = act.second + Y[i];
                if(pos_ok(seg.first,seg.second,n,m)) t[seg.first][seg.second] = 'X';
            }
        }

        if(bfs(t,ini,n,m)) cout << "SI" << endl;
        else cout << "NO" << endl;

    }
}

/* VERSIO 2
#include <iostream>
#include <vector>
using namespace std;

const int X[4] = {1,0,-1,0};
const int Y[4] = {0,1,0,-1};

typedef vector<vector<char>> Mapa;
typedef pair<int,int> Pos;

bool pos_ok(Pos seg, int n, int m){
    if(seg.first >= 0 and seg.first < n and seg.second >= 0 and seg.second < m) return true;
    else return false;
}

bool dfs(Mapa& mapa, Pos ini, Pos fi, int n, int m){
    if(ini == fi) return true;
    else {
        for(int i = 0; i < 4; ++i){
            Pos seg;
            seg.first = ini.first + X[i];
            seg.second = ini.second + Y[i];
            if(pos_ok(seg,n,m) and mapa[seg.first][seg.second] != 'X') {
                mapa[seg.first][seg.second] = 'X';
                if(dfs(mapa, seg, fi, n, m)) return true;
            }
        }
        return false;
    }
}

int main(){
    int n,m;
    while(cin >> n >> m){
        Mapa mapa(n,vector<char>(m));
        vector<Pos> monstres;
        Pos ini,fi;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> mapa[i][j];
                if(mapa[i][j] == 'M') monstres.push_back({i,j});
                else if(mapa[i][j] == 'I') ini = {i,j};
                else if(mapa[i][j] == 'F') fi = {i,j};

            }
        }

        for(uint i = 0; i < monstres.size(); ++i){
            Pos act = monstres[i];
            for(int j = 0; j < 4; ++j){
                Pos seg;
                seg.first = act.first + X[j];
                seg.second = act.second + Y[j];
                if(pos_ok(seg,n,m) and mapa[seg.first][seg.second] != 'M') mapa[seg.first][seg.second] = 'X';
            }
        }

        if(dfs(mapa,ini,fi,n,m)) cout << "SI" << endl;
        else cout << "NO" << endl;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
            cout << mapa[i][j];
            }
            cout << endl;
        }


    }
}
*/