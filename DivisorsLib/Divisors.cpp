#include <iostream>
#include <chrono>
#include <cmath>

int countDivisors(long long n) {
    int count = 0;
    for (long long i = 1; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal, count only one
            if (n / i == i) {
                count++;
            }
            else {
                count += 2; // Count both i and n/i
            }
        }
    }
    return count;
}
