#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graf;

bool colorear(const Graf& g, int u, int color, vector<int>& col) {
	if (col[u] == -1) {             //No pintat
		col[u] = color;             
        bool coloreable = true;
        int n = g[u].size();
        for(int i = 0; i < n and coloreable; ++i){      //Recorrem les adjacències
            int v = g[u][i];
            coloreable = colorear(g,v,1-color,col);
        }
        return coloreable;
    }
    else return (col[u] == color);
}

bool dos_colors(const Graf& g) {
    int n = g.size();
    vector<int> col(n,-1);                              //Si no està visitat el color es -1, hi ha dos colors, el color 0 i el color 1
    bool color = true;
    for(int i = 0; i < n and color; ++i){               //Feim el bucle perquè pot ser no connex
        if(col[i] == -1)
            color = colorear(g,i,0,col);
    }
    return color;                                       //Si pot tenir dos color retorna true; sino retorna false
}



int main() {
    int n,m;
    while(cin >> n >> m){
        Graf g(n);

        for(int i = 0; i < m; ++i){
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
			g[y].push_back(x);
        }
        if(dos_colors(g)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}