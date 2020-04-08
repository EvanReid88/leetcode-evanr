// first attempt
class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> set;
        for (auto a: arr) {
            set.insert(a);
        }
        int count = 0;
        
        for (auto a: arr) {
            if (set.find(a + 1) != set.end()) count++;
        }
        return count;
    }
};