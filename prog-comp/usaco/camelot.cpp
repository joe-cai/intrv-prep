/*
  ID:   caizhuo2
  PROG: camelot
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAXROW 30
#define MAXCOL 26
#define MAXNUM MAXROW * MAXCOL

int knight[MAXNUM];
int dist[MAXNUM][MAXNUM];
int pickup[MAXNUM][MAXNUM];
int nextX[] = {2,  2, -2, -2, 1, -1,  1, -1};
int nextY[] = {1, -1,  1, -1, 2,  2, -2, -2};
int nextX2[] = {1, 0, -1,  0,  1, -1, 1, -1};
int nextY2[] = {1, 1,  1, -1, -1, -1, 0,  0};

int distofKing(int king, int goal, int C) {
    int row = king / C, col = king % C;
    int targetRow = goal / C, targetCol = goal % C;
    return max(abs(targetRow - row), abs(targetCol - col));
}

int main() {
    ifstream cin("camelot.in");
    int R, C;
    cin >> R >> C;
    char kingC, knightC;
    int kingR, knightR;
    cin >> kingC >> kingR;
    int king = (kingR - 1) * C + kingC - 'A', numKnight = 0;
    while (cin >> knightC >> knightR) {
	knight[numKnight++] = (knightR - 1) * C + knightC - 'A';
    }
    cin.close();

    for (int i = 0; i < R * C; i++) {
	for (int j = 0; j < R * C; j++) {
	    dist[i][j] = R * C + 1;
	    pickup[i][j] = R * C;
	}
    }
    // cout << R << " " << C << endl;
    for (int i = 0; i < R * C; i++) {
	dist[i][i] = 0;
	queue<int> neighbors;
	neighbors.push(i);
	while (!neighbors.empty()) {
	    int curr = neighbors.front();
	    neighbors.pop();
	    for (int j = 0; j < sizeof(nextX) / sizeof(int); j++) {
		int nextR = curr / C + nextY[j], nextC = curr % C + nextX[j];
		// cout << nextR << " " << nextC << " " << dist[i][nextR * C + nextC] << "->";
		if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C) {
		    int next = nextR * C + nextC;
		    if (dist[i][next] > dist[i][curr] + 1) {
			dist[i][next] = dist[i][curr] + 1;
			neighbors.push(next);
		    }
		}
		// cout << dist[i][nextR * C + nextC] << endl;
	    }
	    // cout << endl;
	}
    }

    queue<int> neighbors; // king's neighbors
    neighbors.push(king);
    for(int depth = 0; depth <= 2 && !neighbors.empty(); depth++) {
	int size = neighbors.size();
	for (int i = 0; i < size; i++) {
	    int curr = neighbors.front();
	    neighbors.pop();
	    for (int goal = 0; goal < R * C; goal++) {
		for (int k = 0; k < numKnight; k++) {
		    pickup[goal][knight[k]] = 
			min(pickup[goal][knight[k]], dist[curr][goal] +
			    dist[knight[k]][curr] + distofKing(king, curr, C));
		}
	    }
	    for (int j = 0; j < sizeof(nextX2) / sizeof(int); j++) {
		int nextR = curr / C + nextY2[j];
		int nextC = curr % C + nextX2[j];
		if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C)
		    neighbors.push(nextR * C + nextC);
	    }
	}
    }

    // cout << king << endl;
    // for (int i = 0; i < numKnight; i++)
    // 	cout << knight[i] << endl;
    // for (int i = 0; i < R * C; i++) {
    // 	for (int j = 0; j < R * C; j++)
    // 	    cout << dist[j][i] << " ";
    // 	cout << endl;
    // }

    int sol = R * C * (numKnight + 1);
    for (int goal = 0; goal < R * C; goal++) {
	int ans = 0;
	for (int k = 0; k < numKnight; k++) ans += dist[goal][knight[k]];
	sol = min(sol, ans + distofKing(king, goal, C));
	for (int k = 0; k < numKnight; k++)
	    sol = min(sol, ans - dist[goal][knight[k]] 
		      + pickup[goal][knight[k]]);
    }
    
    ofstream cout("camelot.out");
    cout << sol << endl;
}
