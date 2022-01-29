#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <char> > mat;

const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};

void dfs_rec(const mat& G, int f, int c, vector<vector<bool>>& visitat, bool& tresor_trobat){
    pair<int, int> pos;
    pos.first = f;
    pos.second = c;
    if(not visitat[f][c] and not tresor_trobat){
        visitat[f][c] = true;
        if(G[f][c] == 't') tresor_trobat = true;
        else if(G[f][c] == '.'){
            for(int i = 0; i < 4; ++i) {
                int x = pos.first + X[i];
                int y = pos.second + Y[i];

                if (x >= 0 and x < G.size() and y >= 0 and y < G[0].size()) 
                    dfs_rec(G,x,y,visitat,tresor_trobat);
            }
        }
    }
}

int main (){
    int n,m;
    cin >> n >> m;

   mat graf(n, vector <char>(m));

    for(int i = 0; i < n; ++i){                     //Inicializamos la matriz
        for(int j = 0; j < m; ++j){
            cin >> graf[i][j];
        }
    }

    int f,c;
    cin >> f >> c;

    vector <vector <bool> > visitat(n, vector <bool>(m, false));
    bool tresor_trobat = false;
    dfs_rec(graf, f-1, c-1, visitat, tresor_trobat);

    if(tresor_trobat) cout << "yes" << endl;
    else cout << "no" << endl;
}