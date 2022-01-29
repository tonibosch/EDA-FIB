#include <iostream>
#include <queue>
#include <vector>
using namespace std;


typedef vector<char> V;
typedef vector<vector<char>> M;
typedef vector<vector<bool>> MB;
typedef pair<int,int> Pos;


Pos moves[4] = {{-1,0},{0,1},{1,0},{0,-1}};

void print(const vector<char>& v) {
    for (char c : v) cout << c;
    cout << endl;
}

bool pos_ok(Pos p,int n, int m) {
    return (p.first >= 0 and p.first < n and p.second >= 0 and p.second < m);
}

void solve(const vector<vector<char>>& mat, Pos ini, vector<vector<bool>>& mark, vector<char>& sol, const Pos& fin, int n, int m){
    
    if (ini == fin) print(sol);
    else for (int k = 0; k < 4; ++k) {
        Pos seg;
        seg.first = ini.first + moves[k].first;
        seg.second = ini.second + moves[k].second;
        if (pos_ok(seg,n,m) and !mark[seg.first][seg.second]) {
            
            
            sol.push_back(mat[seg.first][seg.second]);
            mark[seg.first][seg.second] = true;
            
            solve(mat,seg,mark,sol,fin,n,m);
            
            sol.pop_back();
            mark[seg.first][seg.second] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    M mat(n,vector<char>(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];
    
    int io, jo, ie, je;
    cin >> io >> jo >> ie >> je;
    Pos ini;
    ini.first = io;
    ini.second = jo;
    Pos fin;
    fin.first = ie;
    fin.second = je;
    MB mark(n,vector<bool>(m,false));
    mark[io][jo] = true;
    vector<char> sol = {mat[io][jo]};
    solve(mat,ini,mark,sol,fin, n, m);//pasa solucion, visitados, input de matriz y las posiciones
}
