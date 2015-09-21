/*
  ID:   caizhuo2
  PROG: skidesign
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int computeCost(int h, vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
	if (nums[i] > h) 
	    ans += (nums[i] - h) * (nums[i] - h);
	else if (nums[i] + 17 < h) 
	    ans += (h - 17 - nums[i]) * (h - 17 - nums[i]);
    }
    return ans;
}

int main() {
    ifstream cin("skidesign.in");
    ofstream cout("skidesign.out");

    int N;
    cin >> N;
    vector<int> nums(N, 0);
    int h = 0, l = 100, idx_h = 0;
    for (int i = 0; i < N; i++) {
	cin >> nums[i];
	if (h < nums[i]) {
	    idx_h = i;
	    h = nums[i];
	}
	l = min(l, nums[i]);
    }
    int cost = 10000000;
    for (int i = h; i >= l; i--) {
	nums[idx_h] = i;
	cost = min(cost, computeCost(i, nums) + (h - i) * (h - i));
	//	cout << i << " " << cost << endl;
    }
    cout << cost << endl;

    return 0;
}
