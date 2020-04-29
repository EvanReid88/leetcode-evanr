// https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/531/week-4/3313/

class FirstUnique {
// hashmap / queue solution
// can be done with linked list
private:
    unordered_map<int, int> map;
    queue<int> queue;
public:
    // O(N)
    FirstUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            queue.push(nums[i]);
        }
    }
    
    // O(max(q, N))
    int showFirstUnique() {
        while (!queue.empty() && map[queue.front()] > 1) {
            queue.pop();
        }
        if (queue.empty()) {
            return -1;
        }
        
        return queue.front();
    }
    
    // O(1) 
    void add(int value) {
        map[value]++;
        if (map[value] == 1) {
            queue.push(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */