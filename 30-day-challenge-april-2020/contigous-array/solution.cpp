// https://leetcode.com/problems/contiguous-array

// hashmap solution 1
// o(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unsigned int contLen = 0;
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            
            auto a = map.find(sum);

            if (sum == 0) {
                if (contLen < i + 1) contLen = i + 1;
            }
            else if (a != map.end()) {
                if (contLen < i - a->second) contLen = i - a->second;
            }
            else if (a == map.end()) {
                map[sum] = i;
            }
        }
        return contLen;
    }
};

// hashmap solution two
// O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unsigned int contLen = 0;
        unordered_map<int, int> map;
        
        map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;

            if (map.find(sum) != map.end()) {
                contLen = i - map[sum] > contLen 
                        ? i - map[sum] : contLen;
            }
            else {
                map[sum] = i;
            }
        }
        return contLen;
    }
};