/*
  ID:   caizhuo2
  PROG: fence
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int numNodes = 500;

void traverse(vector<vector<int> >& edges, vector<int>& ans, int start) {
    for (int i = 0; i < numNodes; i++) {
	if (edges[start][i] > 0) {
	    edges[start][i]--;
	    edges[i][start]--;
	    traverse(edges, ans, i);
	}
    }
    ans.push_back(start + 1);
}

int main() {
    ifstream cin("fence.in");
    ofstream cout("fence.out");

    int F;
    cin >> F;
    vector<vector<int> > edges(numNodes, vector<int>(numNodes, 0));
    for (int i = 0; i < F; i++) {
	int a, b;
	cin >> a >> b;
	edges[a - 1][b - 1]++;
	edges[b - 1][a - 1]++;
    }
    int start = -1;
    for (int i = 0; i < numNodes; i++) {
	int degree = 0;
	for (int j = 0; j < numNodes; j++) degree += edges[i][j];	    
	if (degree % 2 != 0) { start = i; break; }
    }
    if (start == -1) start = 0;

    vector<int> ans;
    traverse(edges, ans, start);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    return 0;
}
