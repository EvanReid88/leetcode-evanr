
// simple solution
// O(n^1.5) Time
// O(1) Space
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        } 
        // only need to consider up to sqrt(n)
        // if n divisible by p, then n = p * q
        // p < q, so p < sqrt(n)
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            } 
        }
        
        // if no divisible numbers found, n prime
        return true;
    }
    
    int countPrimes(int n) {
        int count = 0;
        
        // check each number < n 
        for (int i = 1; i < n; i++) {
           if (isPrime(i)) count++;
        }
        return count;
    }
};

// TODO Sieve of Eratosthenes solution