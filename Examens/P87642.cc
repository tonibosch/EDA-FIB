#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int,int> Pos;

const vector<Pos> dir_pac = {{-1,0},{0,1},{1,0},{0,-1}};
const vector<Pos> dir_fant ={{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};

bool bfs(Tablero& t, Pos& pacman){
	queue<Pos> q;
	q.push(pacman);
    t[pacman.first][pacman.second] = 'X';
    while(not q.empty()){
        Pos act = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            Pos seg;
            seg.first = act.first + dir_pac[i].first;
            seg.second = act.second + dir_pac[i].second;
            if(t[seg.first][seg.second] == 'B') return true;            //Si trobam el bolet ja em acabat
            else if(t[seg.first][seg.second] == '.') {                  //Si es un punt el que em de fer es afegir-lo a la cua i marcar-lo com a visitat
                q.push(seg);
                t[seg.first][seg.second] = 'X';
            } 
        }
    }
    return false;
}

int main(){
    int f,c;
    while(cin >> f >> c){
        Tablero t(f,vector<char>(c));
        queue<Pos> cua_fant;
        Pos pacman;

        //Llegim tot el tablero, guardem la posició del pacman i dels fantasmes
        for(int i = 0; i < f; ++i){
            for(int j = 0; j < c; ++j){
                cin >> t[i][j];
                if(t[i][j] == 'P') pacman = {i,j};
                else if(t[i][j] == 'F') cua_fant.push({i,j});
            }
        }

        bool mort = false;
        while(not cua_fant.empty() and not mort){
            Pos fantasma = cua_fant.front();
            cua_fant.pop();

            for(int i = 0; i < 8 and not mort; ++i){
                Pos seg;
                seg.first = fantasma.first + dir_fant[i].first;
                seg.second = fantasma.second + dir_fant[i].second;
                if(seg == pacman) mort = true;
                else t[seg.first][seg.second] = 'X';
            }
        }

        if(mort) cout << "no" << endl;
        else {
            if(bfs(t,pacman)) cout << "si" << endl;
            else cout << "no" << endl;
        }
    }
}