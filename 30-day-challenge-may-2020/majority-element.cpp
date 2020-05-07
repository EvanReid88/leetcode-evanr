// https://leetcode.com/problems/majority-element/

// hashmap solution
// O(n) Time
// O(n) Space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int majoritySize;
        if (nums.size() == 1) {
            return nums[0];
        } else {
            majoritySize = (nums.size() / 2) - 1;
        }
        
        for (auto a: nums) {
            if (map.find(a) != map.end()) {
                // if number exists in map,
                // increase count and check if it is majority
                map[a]++;
                if (map[a] > majoritySize) {
                    return a;
                }
            }
            else {
                map[a] = 0;
            }
        }
        
        return -1;
    }
};

// Boyor-Moore Algorithm
// O(n) Time
// O(1) Space
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer candidate = null;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
}

// TODO sorting solution