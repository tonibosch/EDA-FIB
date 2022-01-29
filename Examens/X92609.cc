#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int backtracking(int i, int x, int n, const VI& v, int suma, int max_suma) {
	//no es posible hacer el cambio
	if (suma > x or suma + max_suma < x) return 0;
	if (i == n) return 1; //hay una solución
	int cont = 0;
	for (int k = 0; k <= 2; ++k) //hay 3 opciones:0 -> no usar la moneda i, 
								 //1 -> usar la moneda i 1 vez, 2 -> usar la moneda i 2 veces
		cont += backtracking(i+1, x, n, v, suma+k*v[i], max_suma-2*v[i]);
	return cont;
}

int main() {
	int x, n;
	while (cin >> x >> n) {
		VI v = VI(n);
		int s = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			s += v[i];
		}
				
		cout << backtracking(0, x, n, v, 0, 2*s) << endl;
	}
}
