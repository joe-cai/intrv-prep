/*
  ID:   caizhuo2
  PROG: fence9
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define rightMargin 10

int main() {
    ifstream cin("fence9.in");
    int n, m, p;
    cin >> n >> m >> p;
    
    int firstLine = 0, secondLine = 0;
    for (int h = m - 1; h > 0; h--) {
	firstLine += rightMargin - h * n / m;
	secondLine += rightMargin - (h * (n - p) + m * p) / m;
    }

    // cout << firstLine << " " << secondLine << endl;
    for (int h = m - 1; h > 0; h--)
	if (h * (n - p) % m == 0) secondLine++;

    ofstream cout("fence9.out");
    cout << firstLine - secondLine << endl;
}
