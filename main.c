#include <stdio.h>
#include "Fibnoacci_FiFO_Cache.h"

// ref. lec 3 & cwid: 886293364 - 4: FIFO first in first out


// Fibonacci function with memoization
unsigned long long fib_func(int n) {
    // Base cases
    if (n <= 1)
        return n;
    
    // If the value computed = return 
    unsigned long long fib_cache = cacher(n);
    if (fib_cache[n] != -1) {
        return fib_cache[n]; 
    }

    // recursive call
    unsigned long long fib_result[n] = fib_func(n - 1) + fib_func(n - 2);
    return fib_result[n]; // store in cache
}

int main() {
    init_cache();  // Init the cache

    // Testing the Fibonacci function
    printf("fib(0) = %d\n", fib_func(0));
    printf("fib(1) = %d\n", fib_func(1));
    printf("fib(10) = %d\n", fib_func(10));
    printf("fib(20) = %d\n", fib_func(20));
    printf("fib(100) = %d\n", fib_func(100));

    return 0;
}

