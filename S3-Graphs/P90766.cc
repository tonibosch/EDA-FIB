#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <char> > mat;

void dfs_rec(const mat& G, int f, int c, vector<vector<bool>>& visitat, int& num_tresors){
    if(not visitat[f][c]){
        visitat[f][c] = true;
        if(G[f][c] == 't') {
            ++num_tresors;
            if (c != G[0].size()-1) dfs_rec(G, f, c+1, visitat, num_tresors);
			if (f != G.size()-1) dfs_rec(G, f+1, c, visitat, num_tresors);
			if (c != 0) dfs_rec(G, f, c-1, visitat, num_tresors);
			if (f != 0) dfs_rec(G, f-1, c, visitat, num_tresors);
        }
        else if(G[f][c] == '.'){
            if (c != G[0].size()-1) dfs_rec(G, f, c+1, visitat, num_tresors);
			if (f != G.size()-1) dfs_rec(G, f+1, c, visitat, num_tresors);
			if (c != 0) dfs_rec(G, f, c-1, visitat, num_tresors);
			if (f != 0) dfs_rec(G, f-1, c, visitat, num_tresors);
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
    int num_tresors = 0;
    dfs_rec(graf, f-1, c-1, visitat,num_tresors);

    cout << num_tresors << endl;
}