#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int& ans, vector<int> plates, int timer) {
    int max_pc = 0, max_plate = -1;
    for (int i = 0; i < plates.size(); i++) {
	if (plates[i] >= max_pc) {
	    max_pc = plates[i];
	    max_plate = i;
	}
    }
    if (max_pc == 1) {
	ans = min(ans, timer + 1);
	return;
    }

    for (int i = 0; i < plates.size(); i++)
	plates[i]--;
    solve(ans, plates, timer + 1);

    for (int i = 0; i < plates.size(); i++)
	plates[i]++;
    if (max_pc / 2 != 0) {
	plates.push_back(max_pc / 2);
	plates[max_plate] -= max_pc / 2;
	solve(ans, plates, timer + 1);
    }
}

int main() {
    ifstream cin("B-small-practice.in");
    ofstream cout("B-small-practice.out");
    // ifstream cin("b.in");
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	int D;
	cin >> D;
	vector<int> plates(D, 0);
	for (int d = 0; d < D; d++)
	    cin >> plates[d];
	int ans = INT_MAX;
	solve(ans, plates, 0);
	cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
