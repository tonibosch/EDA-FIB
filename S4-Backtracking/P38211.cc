#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> fila;
typedef vector<fila> Matriu;

int diag1(int i, int j, int n){
    return n-j-1+i;
}

int diag2(int i, int j){
    return i+j;
}

void escriure_solucio(const Matriu& mat, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << mat[i][j];
        }
        cout << endl;
    }
}

bool reines3(Matriu& mat, vector<bool>& col, vector<bool>& d1, vector<bool>& d2, int i, int n) {
    if(i == n) {
        escriure_solucio(mat,n);
        return true;
    }
    else {
        for(int j = 0; j < n; ++j){
            int di1 = diag1(i,j,n);
            int di2 = diag2(i,j);
            if(not col[j] and not d1[di1] and not d2[di2]){
                mat[i][j] = 'Q';
                col[j] = true;
                d1[di1] = true;
                d2[di2] = true;

                if(reines3(mat,col,d1,d2,i+1,n)) return true;
                
                mat[i][j] = '.';
                col[j] = false;
                d1[di1] = false;
                d2[di2] = false;
            }
        }
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    Matriu mat(n,fila(n,'.'));
    vector<bool> col(n,false);
    vector<bool> d1(2*n-1,false);
    vector<bool> d2(2*n-1,false);

    if(not reines3(mat,col,d1,d2,0,n)) cout << "NO SOLUTION" << endl; 


}