/*
  ID:   caizhuo2
  PROG: rockers
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define maxSong 20
#define maxDisk 20
#define maxMin 20
int songs[maxSong + 1];
int dp[maxSong + 1][maxDisk + 1][maxMin + 1];

int main() {
    ifstream cin("rockers.in");
    int N, T, M;
    cin >> N >> T >> M;
    for (int i = 1; i <= N; i++) cin >> songs[i];
    cin.close();

    for (int song = 1; song <= N; song++) {
	for (int disk = 1; disk <= M; disk++) {
	    for (int min = 0; min <= T; min++) {
		dp[song][disk][min] = 
		    max(dp[song - 1][disk][min], 
			(songs[song] > min)? dp[song][disk - 1][T] : 
			(dp[song - 1][disk][min - songs[song]] + 1));
	    }
	}
    }

    // for (int i = 0; i <= M; i++) {
    // 	for (int j = 0; j <= T; j++)
    // 	    cout << dp[4][i][j] << " ";
    // 	cout << endl;
    // }
    ofstream cout("rockers.out");
    cout << dp[N][M][T]  << endl;
}
