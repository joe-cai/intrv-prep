/*
  ID:   caizhuo2
  PROG: game1
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ifstream cin("game1.in");
    ofstream cout("game1.out");
    
    int N;
    cin >> N;
    vector<int> board(N, 0);
    vector<vector<int> > scores1(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
	cin >> board[i];
	scores1[i][i] = board[i];
    }
    cin.close();

    for (int l = 1; l < N; l++) {
	int subsum = 0;
	for (int i = 0; i < l; i++) subsum += board[i];
	for (int i = 0; i < N - l; i++) {
	    subsum += board[i + l];
	    scores1[i][i + l] = 
		max(subsum - scores1[i + 1][i + l],
		    subsum - scores1[i][i + l - 1]);
	    subsum -= board[i];
	}
    }
    // for (int row = 0; row < N; row++) {
    // 	for (int col = 0; col < N; col++)
    // 	    cout << scores1[row][col] << " ";
    // 	cout << endl;
    // }
    cout << scores1[0][N - 1] << " ";
    if (N > 1) cout << min(scores1[0][N - 2], scores1[1][N - 1]) << endl;
    else cout << 0 << endl;
    cout.close();

    return 0;
}
