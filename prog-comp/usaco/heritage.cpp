/*
  ID:   caizhuo2
  PROG: heritage
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void postorder(const string& inorder, const string& preorder, ofstream& cout) {
    if (inorder.size() == 0) return;
    // cout << inorder << " " << preorder << endl;
    char root = preorder[0];
    int pos = 0;
    while (inorder[pos] != root) pos++;
    postorder(inorder.substr(0, pos), preorder.substr(1, pos), cout);
    postorder(inorder.substr(pos + 1), preorder.substr(pos + 1), cout);
    cout << root;
}

int main() {
    ifstream cin("heritage.in");
    string inorder;
    cin >> inorder;
    string preorder;
    cin >> preorder;
    // cout << inorder << " " << preorder << endl;
    ofstream cout("heritage.out");
    postorder(inorder, preorder, cout);
    cout << endl;
}
