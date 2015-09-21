/*
  ID:   caizhuo2
  PROG: wormhole
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Point {
public:
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator() (const Point& a, const Point& b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
    }
};

bool hascycle(const vector<int>& neighbor, const vector<int>& pair) {
    for (int i = 0; i < neighbor.size(); i++) {
	vector<bool> visited(neighbor.size(), false);
	int curr = i;
	while (curr != -1 && !visited[curr]) {
	    visited[curr] = true;
	    //  cout << curr << "->" << pair[curr] << "->";
	    curr = neighbor[pair[curr]];
	}
	//cout << curr << endl;
	if (curr != -1) return true;
    }
    return false;
}

void count(const vector<int>& neighbor, vector<bool>& selected, 
	   vector<int>& pair, int start, int numSelected, int& ans) {
    if (numSelected == neighbor.size()) {
	if (hascycle(neighbor, pair)) {
	    ans++;
	    //	    for (int i = 0; i < pair.size(); i++)
	    //	cout << i << "'s parter is: " << pair[i] << endl;
	}
	//	cout << endl << endl;
	return;
    }
    
    for (int i = start; i < neighbor.size(); i++) {
	if (selected[i]) continue;
	selected[i] = true;
	for (int j = i + 1; j < neighbor.size(); j++) {
	    if (selected[j]) continue;
	    else {
		selected[j] = true;
		pair[i] = j;
		pair[j] = i;
		count(neighbor, selected, pair, i + 1, numSelected + 2, ans);
		selected[j] = false;
	    }
	}
	selected[i] = false;
    }
}

int main() {
    ifstream cin("wormhole.in");
    ofstream cout("wormhole.out");

    int N;
    cin >> N;
    vector<Point> points;
    for (int i = 0; i < N; i++) {
	int x, y;
	cin >> x >> y;
	points.push_back(Point(x, y));
    }
    sort(points.begin(), points.end(), Point());
    //    for (int i = 0; i < points.size(); i++)
    //	cout << "#" << i << " " << points[i].x << " " << points[i].y << endl;

    vector<int> neighbor(N, -1);
    for (int i = 0; i < points.size() - 1; i++)
	if (points[i].y == points[i + 1].y)
	    neighbor[i] = i + 1;

    vector<bool> selected(N, false);
    int ans = 0;
    vector<int> pair(N, 0);
    count(neighbor, selected, pair, 0, 0, ans);
    cout << ans << endl;
    return 0;
}
