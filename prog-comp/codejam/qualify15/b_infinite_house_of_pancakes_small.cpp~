#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

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
	vector<int> back = plates;
	make_heap(plates.begin(), plates.end());
	int ans = INT_MAX, now = 0;
	while (!plates.empty()) {
	    int max_pc = plates.front();
	    ans = min(ans, now + max_pc);
	    if (max_pc <= 2 || now >= ans) break;
	    pop_heap(plates.begin(), plates.end());
	    plates.pop_back();
	    plates.push_back(max_pc / 2);
	    push_heap(plates.begin(), plates.end());
	    plates.push_back(max_pc - max_pc / 2);
	    push_heap(plates.begin(), plates.end());
	    now++;
	}
	cout << "Case #" << t << ": " << ans << endl;
	/*
	cout << D << endl;
	for (int d = 0; d < D; d++)
	    cout << back[d] << " ";
	cout << endl;
	*/
    }
    return 0;
}
