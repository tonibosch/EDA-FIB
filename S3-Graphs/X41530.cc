#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<int>> graf;


bool hay_cicles(const graf& g, int i, vector<bool>& visitat){
    stack<pair<int,int>> S;      //first: vertize adyacente, second: vertize de donde vengo
    S.push({i,-1});

    while(not S.empty()) {
        int u = S.top().first;
        int ant = S.top().second;
        S.pop();
        if(not visitat[u]){
            visitat[u] = true;
            for(int j = 0; j < g[u].size(); ++j){
                int v = g[u][j];
                if(not visitat[v]) S.push({v,u});
                else if(v != ant) return true;
            }
        }
    }
    return false;
}


int bosc(const graf& g){
    int n = g.size();
    vector<bool> visitat(n,false); 
    bool cicle = false;    
    int cont = 0;

    for(int i = 0;i < n; ++i){                          //Conta quantes parts connexes hi ha
        if(not visitat[i]){
            if(hay_cicles(g,i,visitat)) cicle = true;
            else ++cont;
        }
    }
    if(cicle) return -1;                                
    else return cont;                                   //Retorna el número d'arbres
}

int main(){
    int n, m;
    while(cin >> n >> m){
        graf g(n,vector<int>(m));
        int x,y;
        //vector<bool> visitat(n);
        for(int i = 0; i < m; ++i){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);

        }
        int num_arb = -1;
        num_arb = bosc(g);

        if(num_arb != -1) cout << num_arb << endl;
        else cout << "no" << endl;
    }


}