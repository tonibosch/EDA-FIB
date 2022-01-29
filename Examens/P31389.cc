#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tablero;

void escriure_sol(const Tablero& tab, int f, int c) {
    for(int i = 0; i < f; ++i){
        for(int j = 0; j < c; ++j) cout << tab[i][j];
        cout << endl;
    }
    cout << endl;
}

bool pos_ok(int i, int j, int f, int c){
    return (i >= 0 and j >= 0 and i < f and j < c);
}

bool amenaza(vector<bool>& files, vector<bool>& columnes, int i, int j) {
    return (files[i] or columnes[j]);
}

void backtracking(Tablero& tab, vector<bool>& files, vector<bool>& columnes, int f, int c, int i, int j, int ntorres) {
    if(ntorres == f) escriure_sol(tab,f,c);
    else {
        int ni = i;
        int nj = j+1;

        if(nj == c){
            nj = 0;
            ++ni;
        }
        if(i != f) {
            if(pos_ok(i,j,f,c) and not amenaza(files,columnes,i,j)){
                tab[i][j] = 'R';
                files[i] = true;
                columnes[j] = true;
                backtracking(tab,files,columnes,f,c,ni,nj,ntorres+1);
                files[i] = false;
                columnes[j] = false;
            }
            tab[i][j] = '.';
            backtracking(tab,files,columnes,f,c,ni,nj,ntorres);
        }
    }
}


int main(){
    int f,c;
    cin >> f >> c;

    Tablero tab(f,vector<char>(c,'.'));

    vector<bool> files(f,false);
    vector<bool> columnes(c,false);

    backtracking(tab,files,columnes,f,c,0,0,0);

}