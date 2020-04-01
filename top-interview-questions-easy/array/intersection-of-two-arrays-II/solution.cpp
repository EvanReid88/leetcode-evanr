// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // value, count
        unordered_map<int, int> map;
        vector<int> response;
        
        // get count of each value
        for (auto a: nums1) {
            map[a]++;
        }
        for (auto a: nums2) {
            // if value count > 0, 
            // push value to vector and subtract count by one
            if (map[a]-- > 0){
                response.push_back(a);  
            } 
        }
        return response;
    }
};

// TODO solve with sorted arrays