#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;

int dfs(const Tablero& t,int f, int c){
    int n = t.size();
    vector<vector<bool>> visitat(n,vector <bool>(t[0].size(), false));
    int pas_min = 0;
    queue <pair <pair <int,int>, int > > Q;                  //Tindrem la posició de la matriu pair<int,int> i la distancia al punt inicial

    Q.push(make_pair(make_pair(f,c),0));

    int x,y,dist;

    while(! Q.empty()){
        x = Q.front().first.first;
        y = Q.front().first.second;
        dist = Q.front().second;

        Q.pop();

        if(t[x][y] == 't') return dist;
        else if(!visitat[x][y]){
            visitat[x][y] = true;
            if(x != 0 and t[x-1][y] != 'X') Q.push(make_pair(make_pair(x-1,y),dist+1));
            if(x != t.size()-1 and t[x+1][y] != 'X') Q.push(make_pair(make_pair(x+1,y),dist+1));
            if(y != 0 and t[x][y-1] != 'X') Q.push(make_pair(make_pair(x,y-1),dist+1));
            if(y != t[0].size()-1 and t[x][y+1] != 'X') Q.push(make_pair(make_pair(x,y+1),dist+1));
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin >> n >> m;

    Tablero t(n,vector<char>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> t[i][j];                 //Llegim tot el tablero
        }
    }

    int f,c;
    cin >> f >> c;

    int pasos = dfs(t,f-1,c-1);
    if(pasos != -1) cout << "distancia minima: " << pasos << endl;
    else cout << "no es pot arribar a cap tresor" << endl;

}