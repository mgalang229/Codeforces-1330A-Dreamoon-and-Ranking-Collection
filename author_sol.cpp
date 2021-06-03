#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, x;
		cin >> n >> x;
		// create 'achieve' boolean vector to mark the places that were achieved and set all values to false
		vector<int> achieve(201, false);
		for (int i = 1; i <= n; i++) {
			int ranking;
			cin >> ranking;
			// mark the numbers (places) that were achieved
			achieve[ranking] = true;
		}
		int res = 0;
		// run a loop from '(n + x)' to 1
		for (int k = n + x; k > 0; k--) {
			// create 'v' variable to count the number of places that we will achieve from every 1 to 'k'
			int v = 0;
			// run a loop from 1 to 'k'
			for (int i = 1; i <= k; i++) {
				if (!achieve[i]) {
					// then, if the place is not yet achieve, then increment 'v', which means it will be achieved
					v++;
				}
			}
			if (v <= x) {
				// if 'v' is less than or equal to 'x', then store this number because this is the maximum place that we can achieve with proper sequence
				// it also means that we have created a continuous sequence from 1 to a certain 'k' from participating 'x' more rated contests
				res = k;
				// break the loop as well
				break;
			}
		}
		cout << res << '\n';
	}
	return 0;
}
