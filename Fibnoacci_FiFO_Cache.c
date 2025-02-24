#include "Fibnoacci_FiFO_Cache.h"

CacheEntry cache[CACHE_SIZE];  // Circular buffer for caching
int front = 0, rear = 0, count = 0;  // Queue pointers and count

// Initialize cache
void init_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].key = -1;  // Mark as unused
        cache[i].fib_result = 0;
    }
}

// Check if a value exists in the cache
unsigned long long cacher(int n) {
    for (int i = 0; i < count; i++) {
        int index = (front + i) % CACHE_SIZE;
        if (cache[index].key == n) {
            return cache[index].fib_result;  // Return cached value
        }
    }
    return -1;  // Indicate not found
}

// Add a new value to the cache (FIFO)
void add_to_cache(int n, unsigned long long fib_result) {
    if (count == CACHE_SIZE) {
        // If the cache is full, remove the oldest value
        front = (front + 1) % CACHE_SIZE;
        count--;
    }
    cache[rear].key = n;
    cache[rear].fib_result = fib_result;
    rear = (rear + 1) % CACHE_SIZE;
    count++;
}
