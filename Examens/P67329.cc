#include <iostream>
#include <string>
using namespace std;

void ADN_backtraking(int i, int n, const string pal, string sol){
    if(i == n) {
        for(int j = 0; j < n; ++j) cout <<sol[j];
        cout << endl;
    }
    else {
        for(int j = 0; j < 4; ++j){
            sol[i] = pal[j];
            ADN_backtraking(i+1,n,pal,sol);
        }
    }
}

int main() {
    int n;
    cin >> n;

    string pal = "ACGT";
    string sol = string(n,' ');

    ADN_backtraking(0,n,pal,sol);
}

/*
#include <iostream>
#include <vector>
using namespace std;

void ADN_backtraking(int i, int n, const vector<char> pal, vector<char>& sol){
    if(i == n) {
        for(int j = 0; j < n; ++j) cout <<sol[j];
        cout << endl;
    }
    else {
        for(int j = 0; j < 4; ++j){
            sol[i] = pal[j];
            ADN_backtraking(i+1,n,pal,sol);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> pal = {'A','C','G','T'};
    vector<char> sol(n);

    ADN_backtraking(0,n,pal,sol);
}
*/