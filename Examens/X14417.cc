#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<string>> Matriu;
typedef pair<int,int> Pos;

const vector<Pos> dir = {{1,0},{0,-1},{-1,0},{0,1}};

bool pos_ok(Pos seg, int n, int m){
    return (seg.first >= 0 and seg.first < n and seg.second >= 0 and seg.second < m);
}

int bfs(const Matriu& mat, string& paraula, int n, int m, Pos& ini) {

    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<Pos> q;
    q.push(ini);
    dist[ini.first][ini.second] = 0;

    while(not q.empty()){
        Pos act = q.front();
        q.pop();

        if(mat[act.first][act.second] == paraula) {
            ini = act;
            return dist[act.first][act.second];

        }
        for(int i = 0; i < 4; ++i) {
            Pos seg;
            seg.first = act.first + dir[i].first;
            seg.second = act.second + dir[i].second;

            if (pos_ok(seg, n, m) and dist[seg.first][seg.second] == -1 and mat[seg.first][seg.second] != "*") {
                dist[seg.first][seg.second] = dist[act.first][act.second] + 1;
                q.push(seg);
            }
        }
    }
    return -1;

}


int main() {
    int n,m;
    while(cin >> n >> m) {
        Matriu mat(n,vector<string>(m));

        for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cin >> mat[i][j];
		}

        int npar;
        cin >> npar;
        vector<string> par(npar);
        for (int i = 0; i < npar; ++i) cin >> par[i];	

        int suma = 0; 
        bool fin = false;
        int i = 0; 
        Pos ini = {0,0};
        while(i < npar and not fin) {
            int dist = bfs(mat,par[i],n,m,ini);
            if(dist == -1) fin = true;
            else suma += dist;
            ++i;
        }
        
        if (fin) cout << "impossible" << endl;
		else cout << suma+npar << endl;
    }
}