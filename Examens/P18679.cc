#include <iostream>
#include <vector>
using namespace std;

void back(int i, const vector<int>& l, int pos, int n, int num_l) {
	if (pos >= -n/2 and pos <= n/2) {
		if (i == num_l) cout << pos << endl;
		else {
			back(i+1, l, pos + l[i], n, num_l);
			back(i+1, l, pos - l[i], n, num_l);
		}
	}
}

int main() {
	int n, num_l;
	cin >> n >> num_l;
	vector<int> l(num_l);
	for (int i = 0; i < num_l; ++i) cin >> l[i];
	
	back (0, l, 0, n, num_l);
}
