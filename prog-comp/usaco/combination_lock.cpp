/*
ID:   caizhuo2
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool match(int code[3], int i, int j, int k, int N) {
  return (min(abs(i - code[0]), N - abs(i - code[0])) <= 2 && 
	  min(abs(j - code[1]), N - abs(j - code[1])) <= 2 && 
	  min(abs(k - code[2]), N - abs(k - code[2])) <= 2);
}

int main() {
  ifstream cin("combo.in");
  ofstream cout("combo.out");

  int N;
  cin >> N;
  int farmer[3], master[3];
  cin >> farmer[0] >> farmer[1] >> farmer[2];
  cin >> master[0] >> master[1] >> master[2];

  int counter = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      for (int k = 1; k <= N; k++)
	if (match(farmer, i, j, k, N) || match(master, i, j, k, N))
	  counter++;
  cout << counter << endl;

  return 0;
}
