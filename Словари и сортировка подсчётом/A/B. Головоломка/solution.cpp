#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<uint64_t> counts(26, 0);
    int N, M;
    std::cin >> N >> M;
    std::string input;
    for (int i = 0; i < N; ++i) {
        std::cin >> input;
        for (auto c: input) {
            ++counts[c - 'A'];
        }
    }
    for (int i = 0; i < M; ++i) {
        std::cin >> input;
        for (auto c: input) {
            --counts[c - 'A'];
        }
    }
    for (int i = 0; i < counts.size(); ++i) {
        if (counts[i] > 0) std::cout << std::string(counts[i], 'A' + i);
    }
    std::cout << std::endl;
    return 0;
}
