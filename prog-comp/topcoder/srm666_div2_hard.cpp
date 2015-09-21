class CollectingTokens {
public:
    int dp[50][50][100][2];
    vector<vector<int>> tree;
    int f(int node, int branch, int steps, int ret) {
	int res = dp[node][branch][steps][ret];
	if (res == -1) {
	    res = 0;
	    if (branch != tree[node].size()) {
		for (int s = 0; s <= steps; s++) {
		    int child = tree[node][branch];
		    // distribute steps: get into the branch and return
		    if (steps - s - 2 >= 0) 
			res = max(res, tokens[child] + f(child, 0, s, 1) +
				  f(node, branch + 1, steps - s - 2, ret));
		    // distribute steps: get into the branch and not return
		    if (steps - s - 1 >= 0)
			res = max(res, tokens[child] + f(child, 0, s, 0) +
				  f(node, branch + 1, steps - s - 1, 1);
		}
		// ignore the branch
		res = max(res, f(node, branch + 1, steps, ret));
	    }
	    dp[node][branch][steps][ret] = res;
	}
	return res;
    }
    int maxTokens(vector<int> A, vector<int> B, vector<int> tokens, int L) {
	// parse the input into the tree structure
	tree.resize(tokens.size());

	queue<int> nodes;
	nodes.push(0);
	set<int> visited;
	visited.insert(0);
	while (!nodes.empty()) {
	    int curr = nodes.front();
	    nodes.pop();
	    for (int i = 0; i < A.size(); i++) {
		if (curr == A[i] - 1 && visited.count(A[i] - 1) == 0) {
		    tree[curr].push_back(B[i] - 1);
		    visited.insert(B[i] - 1);
		}
		if (curr == B[i] - 1 && visited.count(B[i] - 1) == 0) {
		    tree[curr].push_back(A[i] - 1);
		    visited.insert(A[i] - 1);
		}
	    }
	}
	
	memset(dp, -1, sizeof(dp));
	return tokens[0] + f(0, 0, L, 0);
    }
};
