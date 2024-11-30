#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<uint64_t> lengths;
    std::vector<uint64_t> lengths2;
    lengths.reserve(N);
    lengths2.reserve(N);
    for (int i = 0; i < N; ++i) {
        uint64_t l;
        std::cin >> l;
        lengths.push_back(l);
        lengths2.push_back(l * l);
    }

    uint64_t counter{0};
    for (int i = 2; i < N; ++i) {
        if (lengths[i] == lengths[0]) continue;
        for (int j = 0; j < i - 1; ++j) {
            // first left > lengths[i] - lengths[j]
            auto left = std::upper_bound(lengths.begin() + j + 1, lengths.begin() + i, lengths[i] - lengths[j]);
            if (left == lengths.begin() + i) continue;
            // last right <= lengths2[i] - lengths2[j]
            auto right = std::lower_bound(lengths2.begin() + j + 1, lengths2.begin() + i, lengths2[i] - lengths2[j]);
            if (right == lengths2.begin() + j + 1) continue;
            --right;
            counter += std::distance(lengths2.begin(), right) - std::distance(lengths.begin(), left) + 1;
        }
    }
    std::cout << counter << std::endl;
    return 0;
}
