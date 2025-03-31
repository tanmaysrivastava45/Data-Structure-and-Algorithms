#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Simple Sieve of Eratosthenes to find primes up to sqrt(n)
vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;
    
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
            for (int i = p * p; i <= limit; i += p)
                isPrime[i] = false;
        }
    }
    return primes;
}

// Function to count primes less than n using the segmented sieve approach
int countPrimes(int n) {
    if (n <= 2) return 0;  // No primes less than 2
    
    int limit = sqrt(n);
    vector<int> primes = simpleSieve(limit);  // Get primes up to sqrt(n)
    
    // Boolean array for the range [2, n-1], initialized to true
    vector<bool> isPrime(n, true);
    
    // Mark 0 and 1 as non-prime
    isPrime[0] = isPrime[1] = false;
    
    // Mark non-prime numbers in the range [2, n-1]
    for (int prime : primes) {
        // Start marking from prime * prime
        int start = prime * prime;
        if (start >= n) continue;  // No need to mark beyond the range
        
        for (int j = start; j < n; j += prime) {
            isPrime[j] = false;
        }
    }
    
    // Count the prime numbers in the range [2, n-1]
    int primeCount = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            primeCount++;
        }
    }
    
    return primeCount;
}

int main() {
    int n = 30;
    cout << "Number of primes less than " << n << ": " << countPrimes(n) << endl;
    return 0;
}
