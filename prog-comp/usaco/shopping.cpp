/*
  ID:   caizhuo2
  PROG: shopping
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAXOFFER 100
#define MAXITEMS 6
#define MAXCODES 1000
int cost[MAXITEMS][MAXITEMS][MAXITEMS][MAXITEMS][MAXITEMS];

int codes[MAXOFFER][MAXITEMS];
int total[MAXOFFER][MAXITEMS];
int offer[MAXOFFER];

int price[MAXITEMS];
int need[MAXITEMS];
int map[MAXCODES];

bool is_valid(int s, int idx[5]) {
    for (int i = 0; i < MAXITEMS && codes[s][i] != 0; i++) {
	int slot = map[codes[s][i]] - 1;
	if (slot < 0 || total[s][i] > idx[slot]) return false;
    }
    return true;
}

int main() {
    ifstream cin("shopping.in");
    ofstream cout("shopping.out");
    
    int S;
    cin >> S;
    for (int s = 0; s < S; s++) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
	    cin >> codes[s][i];
	    cin >> total[s][i];
	}
	cin >> offer[s];
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
	int c;
	cin >> c;
	cin >> need[i];
	cin >> price[i];
	map[c] = i + 1;
    }

    int idx[5];
    for (idx[0] = 0; idx[0] < MAXITEMS; idx[0]++)
	for (idx[1] = 0; idx[1] < MAXITEMS; idx[1]++)
	    for (idx[2] = 0; idx[2] < MAXITEMS; idx[2]++)
		for (idx[3] = 0; idx[3] < MAXITEMS; idx[3]++)
		    for (idx[4] = 0; idx[4] < MAXITEMS; idx[4]++)
			cost[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]] = 10000;
    cost[0][0][0][0][0] = 0;

    for (idx[0] = 0; idx[0] < MAXITEMS; idx[0]++)
	for (idx[1] = 0; idx[1] < MAXITEMS; idx[1]++)
	    for (idx[2] = 0; idx[2] < MAXITEMS; idx[2]++)
		for (idx[3] = 0; idx[3] < MAXITEMS; idx[3]++)
		    for (idx[4] = 0; idx[4] < MAXITEMS; idx[4]++) {
			for (int s = 0; s < S; s++) {
			    int rem[5];
			    for (int i = 0; i < 5; i++) rem[i] = idx[i];
			    for (int i = 0; i < MAXITEMS && codes[s][i] != 0; i++) {
				int slot = map[codes[s][i]] - 1;
				rem[slot] = idx[slot] - total[s][i];
			    }
			    if (is_valid(s, idx)) {
				cost[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]] =
				    min(cost[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]],
					cost[rem[0]][rem[1]][rem[2]][rem[3]][rem[4]] + offer[s]);
			    }
			} // special offer
			for (int n = 0; n < N; n++) {
			    if (idx[n] > 0) {
				int rem[5];
				for (int i = 0; i < 5; i++) rem[i] = idx[i];
				rem[n] = idx[n] - 1;
				cost[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]] =
				    min(cost[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]],
					cost[rem[0]][rem[1]][rem[2]][rem[3]][rem[4]] + price[n]);
			    }
			} // regular price
		    }
    cout << cost[need[0]][need[1]][need[2]][need[3]][need[4]] << endl;
    return 0;
}
