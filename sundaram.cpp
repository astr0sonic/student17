#include "sundaram.h"

std::vector<int> sieve(int n) {
    int limit = (n - 1) / 2;
    std::vector<bool> marked(limit + 1, false);
    std::vector<int> primes;

    for (int i = 1; i <= limit; i++) {
        int j = i;
        while ((i + j + 2 * i * j) <= limit) {
            marked[i + j + 2 * i * j] = true;
            j++;
        }
    }

    if (n > 2) {
        primes.push_back(2);
    }

    for (int i = 1; i <= limit; i++) {
        if (marked[i] == false) {
            primes.push_back(2 * i + 1);
        }
    }
    return primes;
}
