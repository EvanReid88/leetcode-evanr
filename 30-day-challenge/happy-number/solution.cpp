// https://leetcode.com/problems/happy-number

// first attempt
// O(n^2)
class Solution {
public:
    bool isHappy(int n) {
        string happyStr = to_string(n);
        
        // if n is 4, output will never be 1
        while (n != 1 && n != 4) {
            n = 0;
            for (auto a: happyStr) {
                int digit = (int)a - 48;
                n += digit * digit;
            }
            happyStr = to_string(n);
        }
        
        return n == 1;
    }
};

// without strings
// O(n^2)
class Solution {
public:
    bool isHappy(int n) {
        // if n is 4, output will never be 1
        while (n != 1 && n != 4) {
            int sum = 0;
            while (n > 0) {
                int remainder = n % 10;
                sum += remainder * remainder;
                n = n / 10;   
            }
            n = sum;
        }
        
        return n == 1;
    }
};

// hashset solution
// O(n^2)
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        
        while(n != 1) {
            if(set.find(n) == set.end()) {
                set.insert(n);
            }
            else {
                return false;   
            }
            
            int sum = 0;
            while(n != 0) {
                int remainder = n % 10;
                sum += remainder * remainder;
                n = n / 10;
            }
            n = sum;
        }
        
        return true;
    }
};

// floyds cycle detection approach
// O(1)
class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if(fast == 1) return 1;
        } while(slow != fast);
        
        return 0;
    }
};