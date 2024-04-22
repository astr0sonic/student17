#include "eratosthenes.h"

std::vector<int> sieve(int n) {
    std::vector<int> input;
    input.resize(n + 1);
    std::vector<int> result;
    int new_size = 0; 
    for (ptrdiff_t i = 0; i < n + 1; i++) {
        input[i] = i;
    }
    for (ptrdiff_t i = 2; i < n + 1; i++) {
        if (input[i] != 0) {
            new_size++;
            for (ptrdiff_t j = i * i; j < n + 1; j += i) {
                input[j] = 0;
            }
        }
    }
    result.resize(new_size);
    for(ptrdiff_t i = 0; i < n + 1; i++){
        if(input[i] != 0) result.push_back(input[i]);
    }
    return input;
}
