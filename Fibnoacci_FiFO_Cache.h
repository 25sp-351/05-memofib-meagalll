#ifndef FIFO_CACHE_H
#define FIFO_CACHE_H

#include <stdio.h>

#define CACHE_SIZE 10  // Define FIFO cache size

// Structure for a cache entry
typedef struct {
    int key;                  // Fibonacci number (n)
    unsigned long long fib_result;  // Fibonacci value
} CacheEntry;

// Function prototypes
unsigned long long cacher(int n);
void add_to_cache(int n, unsigned long long fib_result);
void init_cache();  // Initializes the cache

#endif  // FIFO_CACHE_H
