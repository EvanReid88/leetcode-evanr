// https://leetcode.com/problems/product-of-array-except-self/

// first attempt
// O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> lProducts(len);
        vector<int> rProducts(len);
        
        // product of elements to the left
        lProducts[0] = 1;
        for (int i = 1; i < len; i++) {
            lProducts[i] = nums[i - 1] * lProducts[i - 1];
        }
        
        // product of elements to the right
        rProducts[len - 1] = 1;
        for (int i = len - 2; i >= 0; i--) {
            rProducts[i] = nums[i + 1] * rProducts[i + 1];
        }
        
        // calculate product except self 
        for (int i = 0; i < len; i++) {
            nums[i] = lProducts[i] * rProducts[i];
        }
        
        return nums;
    }
};

// two pass solution
// O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len); // lProduct
        
        // product of elements to the left
        result[0] = 1;
        for (int i = 1; i < len; i++) {
            result[i] = nums[i - 1] * result[i - 1];
        }
        
        // product of elements to the right
        int rProduct = 1;
        for (int i = len - 1; i >= 0; i--) {
            result[i] = result[i] * rProduct;
            rProduct *= nums[i];
        }
    
        return result;
    }
};