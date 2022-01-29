#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <char> > mat;

void dfs_rec(const mat& G, int f, int c, vector<vector<bool>>& visitat, bool& tresor_trobat){
    if(not visitat[f][c] and not tresor_trobat){
        visitat[f][c] = true;
        if(G[f][c] == 't') tresor_trobat = true;
        else if(G[f][c] == '.'){
            if (c != G[0].size()-1) dfs_rec(G, f, c+1, visitat, tresor_trobat);
			if (f != G.size()-1) dfs_rec(G, f+1, c, visitat, tresor_trobat);
			if (c != 0) dfs_rec(G, f, c-1, visitat, tresor_trobat);
			if (f != 0) dfs_rec(G, f-1, c, visitat, tresor_trobat);
        }
    }
}

int main (){
    int n,m;
    cin >> n >> m;

    vector <vector <char> > graf(n, vector <char>(m));

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