#include <iostream>
#include <unordered_set>
#include <stdint.h>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::unordered_set<uint64_t> edges;
    uint64_t i, j;
    for (int k = 0; k < m; ++k) {
        std::cin >> i >> j;
        if (i == j) {
            continue;
        }
        if (i > j) {
            std::swap(i, j);
        }
        uint64_t c = i * 1e6 + j;
        edges.insert(c);
    }
    std::cout << n << " " << edges.size() << std::endl;
    for (const auto& e: edges) {
        std::cout << uint64_t(e / 1e6) << " " << e % uint64_t(1e6) << std::endl;
    }
    return 0;
}