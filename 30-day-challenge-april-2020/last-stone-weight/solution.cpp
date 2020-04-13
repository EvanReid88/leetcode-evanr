// https://leetcode.com/problems/last-stone-weight/

// priority queue solution
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if (s1 == s2) {
                continue;
            }
            else {
                pq.push(abs(s1 - s2));
            }
        }
        
        if (pq.size()) return pq.top();
        
        return 0;
    }
};