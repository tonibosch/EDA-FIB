#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Matriu;

const int X[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int Y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

bool pos_ok(int i, int j, int n) {
	return i >= 0 and i < n and j >= 0 and j < n;
}

bool amenaza(const Matriu& mat, int x, int y,int n) {
    for (int i = 0; i < 8; ++i) {
		int xsig = x + X[i];
		int ysig = y + Y[i];
		if (pos_ok(xsig, ysig, n) and mat[xsig][ysig] == 'K') return true;
	}
	return false;
}

void escriure_sol(const Matriu& mat, int n){ 
    for(int k = 0; k < n; ++k){
        for(int p = 0; p < n; ++p){
            cout << mat[k][p];
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

void backtracking(Matriu& mat, int n, int r, int i, int j, int nreis){
    if(r == nreis) {
        escriure_sol(mat,n);
    }
    else if(i != n){
        int ni = i;
        int nj = j;
        ++nj;
        if(nj == n){
            nj = 0;
            ++ni;
        }
        if(not amenaza(mat,i,j,n)){
            mat[i][j] = 'K';
            backtracking(mat,n,r,ni,nj,nreis+1);
        }
        mat[i][j] = '.';
        backtracking(mat,n,r,ni,nj,nreis);
    }
}

int main() {
    int n,r;
    cin >> n >> r;

    Matriu mat(n,vector<char>(n,'.'));

    backtracking(mat,n,r,0,0,0);
}