#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int dp[101][101];
int apples[101];
vector<vector<int> > child;
int f(int n, int q) {
    if (q == 0 || child[n].size() == 0) dp[n][q] = 0;
    else if (dp[n][q] == -1) {
	int res = 0;
	if (child[n].size() == 2) {
	    res = max(res, f(child[n][0], q - 1) + apples[child[n][0]]);
	    for (int i = 0; i <= q - 2; i++)
		res = max(res, f(child[n][0], i) + f(child[n][1], q - 2 - i)
			  + apples[child[n][0]] + apples[child[n][1]]);
	    res = max(res, f(child[n][1], q - 1) + apples[child[n][1]]);
	} else
	    res = max(res, f(child[n][0], q - 1) + apples[child[n][0]]);
	dp[n][q] = res;
    }
    return dp[n][q];
}

int main() {
    int N, Q;
    // ifstream cin("data");
    cin >> N >> Q;
    vector<int> end1(N - 1, 0), end2(N - 1, 0), val(N - 1, 0);
    for (int i = 0; i < N - 1; i++) cin >> end1[i] >> end2[i] >> val[i];

    // parse the tree
    unordered_set<int> roots;
    roots.insert(1);
    child.resize(N + 1);
    bool done = false;
    while (!done) {
	done = true;
	for (int i = 0; i < N - 1; i++) {
	    if (roots.count(end1[i]) && roots.count(end2[i]) == 0) {
		child[end1[i]].push_back(end2[i]);
		roots.insert(end2[i]);
		apples[end2[i]] = val[i];
		done = false;
	    } else if (roots.count(end1[i]) == 0 && roots.count(end2[i])) {
		child[end2[i]].push_back(end1[i]);
		roots.insert(end1[i]);
		apples[end1[i]] = val[i];
		done = false;
	    }
	}
    }

    memset(dp, -1, sizeof(dp));
    cout << f(1, Q) << endl;

    return 0;
}
