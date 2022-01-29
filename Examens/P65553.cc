#include <iostream>
#include <map>
using namespace std;

int main() {
	int n; 
	while (cin >> n) {
		map<string, int> m;
		int total = 0;
		
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			++m[s]; //añade el juego si no esta y si esta incrementa 1 al num de juegos
			++total;
		}
		cin >> n;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			int num_j = m[s];
			if (num_j + 1 <= total - num_j) {
				++m[s];
				++total;
			}
		}
		
		for (auto it = m.begin(); it != m.end(); ++it) {
			cout << it->first << ' ' << it->second << endl;
		}
		cout << string(20, '-') << endl;
	}
}










