/*
  ID:   caizhuo2
  PROG: range
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define maxN 250
int field[maxN][maxN];
int dp[maxN][maxN];
int upper[maxN];
int square[maxN];

int main() {
    ifstream cin("range.in");
    int N;
    cin >> N;
    char c;
    for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++) {
	    cin >> c;
	    field[i][j] = (c == '1');
	}

    for (int j = 0; j < N; j++) {
	dp[0][j] = field[0][j] == 1;
	upper[j] = dp[0][j];
    }
    for (int i = 1; i < N; i++) {
	dp[i][0] = field[i][0] == 1;
	int lefter = field[i][0] == 0;
	for (int j = 1; j < N; j++) {
	    upper[j] = (field[i][j] == 0)? 0 : upper[j] + 1;
	    dp[i][j] = min(j - lefter + 1, upper[j]);
	    if (field[i][j] == 0) dp[i][j] = 0;
	    else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
	    lefter = (field[i][j] == 0)? j + 1 : lefter;
	}
    }

    // for (int i = 0; i < N; i++) {
    // 	for (int j = 0; j < N; j++)
    // 	    cout << dp[i][j] << " ";
    // 	cout << endl;
    // }

    for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	    for (int k = 0; k <= dp[i][j]; k++)
		square[k]++;

    ofstream cout("range.out");
    for (int i = 2; i <= N; i++)
	if (square[i] > 0) cout << i << " " << square[i] << endl;
    return 0;
}
