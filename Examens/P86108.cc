#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Mapa;

int back(Mapa& sol, int n, int m, int i, int j, int num) {
	if (i == n) return num;
	sol[i][j] = 'L';
	int cont = 0; //cuantos LOL formo poniendo la L
	//horizontal
	if (j >= 2 and sol[i][j-2] == 'L' and sol[i][j-1] == 'O') ++cont;
	//vertical
	if (i >= 2 and sol[i-2][j] == 'L' and sol[i-1][j] == 'O') ++cont;
	//diag1
	if (i >= 2 and j >= 2 and sol[i-2][j-2] == 'L' and sol[i-1][j-1] == 'O') ++cont;
	//diag2
	if (i >= 2 and j+2 < m and sol[i-2][j+2] == 'L' and sol[i-1][j+1] == 'O') ++cont;
	
	int ni, nj;
	if (j == m-1) {
		nj = 0;
		ni = i + 1;
	}
	else {
		ni = i;
		nj = j + 1;
	}
	
	int num_l = back(sol, n, m, ni, nj, num + cont);
	//num_l = numero maximo de LOL si pongo una L en la pos i, j
	
	sol[i][j] = 'O';
	int num_o = back(sol, n, m, ni, nj, num);
	
	return max(num_l, num_o);
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Mapa sol(n, vector<char>(m));
		cout << back(sol, n, m, 0, 0, 0) << endl;
	}
}

