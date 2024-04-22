#include "eratosthenes.h"

std::vector<int> sieve(int n) {
    std::vector<int> input;
    input.resize(n + 1);
    for (ptrdiff_t i = 0; i < n + 1; i++) {
        input[i] = i;
    }
    for (ptrdiff_t i = 2; i < n + 1; i++) {
        if (input[i] != 0) {
            // cout << input[i] << " ";
            for (ptrdiff_t j = i * i; j < n + 1; j += i) {
                input[j] = 0;
            }
        }
    }
    return input;
}
