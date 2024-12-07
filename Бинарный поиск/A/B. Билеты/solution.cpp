#include <iostream>
#include <stdint.h>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint64_t A, B, C, X, K;
    std::cin >> A >> B >> C >> X >> K;

    if (X < A * K || X > B * K) {
        std::cout << (uint64_t)(X / K) << std::endl;
        return 0;
    }

    if (K > X) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::cout << std::max((X * 100) / (K * (100 + C)), A - 1) << std::endl;

    return 0;
}