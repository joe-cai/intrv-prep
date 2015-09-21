#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
/*
class Child {
public:
    int parent;
    int val;
    Child(int p = 0, int v = 0) : parent(p), val(v) {}
    bool operator() (const Child& a, const Child& b) { return a.val > b.val; }
};
*/
int dp[101][101];
vector<vector<int>> child;
int f(int n, int q) {
    if (dp[n][q] == -1) {
	
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
    vector<int> parent(N + 1, -1);
    vector<int> apples(N + 1, 0);
    parent[1] = 0;
    bool done = false;
    while (!done) {
	done = true;
	for (int i = 0; i < N - 1; i++) {
	    if (parent[end1[i]] != -1 && parent[end2[i]] == -1) {
		parent[end2[i]] = end1[i];
		apples[end2[i]] = val[i];
		done = false;
	    } else if (parent[end1[i]] == -1 && parent[end2[i]] != -1) {
		parent[end1[i]] = end2[i];
		apples[end1[i]] = val[i];
		done = false;
	    }
	}
    }

    // count degrees
    vector<int> degrees(N + 1, 0);
    for (int i = 1; i <= N; i++) degrees[parent[i]]++;
    vector<int> branches(N + 1, 0);
    for (int i = 1; i <= N; i++)
	if (degrees[i] == 0)
	    branches[parent[i]]--;
    done = false;
    while (!done) {
	done = true;
	for (int i = 1; i <= N; i++)
	    if (branches[i] < 0) {
		done = false;
		branches[parent[i]] -= branches[i];
		branches[i] = -branches[i];
	    }
    }
    memset(dp, -1, sizeof(dp));

    cout << f(1, Q) << endl;
	
    /*
    int ans = 0;
    // build max-heap
    vector<Child> children;
    for (int i = 1; i <= N; i++) {
	if (branches[i] == 0)
	    children.push_back(Child(parent[i], apples[i]));
	ans += apples[i];
    }

    make_heap(children.begin(), children.end(), Child());
    for (int i = 0; i < N - 1 - Q; i++) {
	pop_heap(children.begin(), children.end(), Child());
	int node = children.back().parent;
	ans -= children.back().val;
	children.pop_back();
	branches[node]--;
	if (branches[node] == 0) {
	    children.push_back(Child(parent[node], apples[node]));
	    push_heap(children.begin(), children.end(), Child());
	}
    }
    */
    return 0;
}
