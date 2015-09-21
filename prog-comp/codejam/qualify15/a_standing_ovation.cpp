#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream cin("A-small-practice.in");
    ofstream cout("A-small-practice.out");

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	int N;
	cin >> N;
	string shyness;
	cin >> shyness;
	int ans = 0, standing = 0;
	for (int n = 0; n <= N; n++) {
	    // cout << standing << " " << n << endl;
	    if (standing < n && shyness[n] != '0') {
		ans += n - standing;
		standing = n + shyness[n] - '0';
	    } else 
		standing += shyness[n] - '0';
	}
	cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
