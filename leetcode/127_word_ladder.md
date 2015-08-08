#Word Ladder
Modified from the two-end solution of `VaultBoy`. This solution is intuitive, and does not modify the given data like other solutions.
```C++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord == endWord) return 1;

        unordered_set<string> beginSet, endSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);

        queue<string> beginQueue, endQueue;
        beginQueue.push(beginWord);
        endQueue.push(endWord);

        int dist = 2;
        while (!beginQueue.empty() && !endQueue.empty()) {
            queue<string>& currQueue = (beginQueue.size() < endQueue.size())? beginQueue : endQueue;
            unordered_set<string>& currSet = (beginQueue.size() < endQueue.size())? beginSet : endSet;
            unordered_set<string>& otherSet = (beginQueue.size() >= endQueue.size())? beginSet : endSet;
            
            int size = currQueue.size();
            for (int s = 0; s < size; s++) {
                string curr = currQueue.front();
                currQueue.pop();
                for (int i = 0; i < curr.size(); i++) {
                    char letter = curr[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (letter == c) continue;
                        curr[i] = c;
                        if (otherSet.count(curr) > 0) return dist;
                        if (currSet.count(curr) == 0 && wordDict.count(curr) > 0) {
                            currSet.insert(curr);
                            currQueue.push(curr);
                        }
                    }
                    curr[i] = letter;
                }
            }
            dist++;
        }
        
        return 0;
    }
};
```