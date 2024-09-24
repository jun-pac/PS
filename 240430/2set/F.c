#include <stdint.h>

uint64_t x = 2; 
uint64_t y = 5; 
uint64_t mul(uint64_t a, uint64_t b) { 
    uint64_t e = a * b; // L0 
    return e;  // L1 
} 
uint64_t comp(uint64_t n) { 
    uint64_t e = 0; // L2 
    uint64_t f = 0; // L3 
    e = mul(x, n); // L4 
    f = mul(n, y); // L5 
    return e + f; // L6 
} 
int main() { 
    comp(2); // L7 
}