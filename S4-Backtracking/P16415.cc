#include <iostream>
#include <vector>
using namespace std;

int diag1(int i, int j, int n){
    return n-j-1+i;
}

int diag2(int i, int j){
    return i+j;
}

void reines1(vector<bool>& col, vector<bool>& d1, vector<bool>& d2, int i, int n, int& cont) {
    if(i == n) ++cont;
    else {
        for(int j = 0; j < n; ++j){
            int di1 = diag1(i,j,n);
            int di2 = diag2(i,j);
            if(not col[j] and not d1[di1] and not d2[di2]){
                col[j] = true;
                d1[di1] = true;
                d2[di2] = true;

                reines1(col,d1,d2,i+1,n,cont);
                col[j] = false;
                d1[di1] = false;
                d2[di2] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<bool> col(n,false);
    vector<bool> d1(2*n-1,false);
    vector<bool> d2(2*n-1,false);
    int cont = 0;

    reines1(col,d1,d2,0,n,cont);
    cout << cont << endl;

}