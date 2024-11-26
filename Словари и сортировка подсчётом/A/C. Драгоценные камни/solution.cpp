#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stdint.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::string S;
    std::cin >> S;

    std::unordered_map<char, std::unordered_set<char>> pairs;
    std::string pair;
    for (int i = 0; i < k; ++i) {
        std::cin >> pair;
        pairs[pair[0]].insert(pair[1]);
    }
    std::unordered_map<char, uint64_t> counts;
    uint64_t total{0};
    for (int i = n - 1; i >= 0; --i) {
        if (auto it = pairs.find(S[i]); it != pairs.end()) {
            for (auto c: it->second) {
                total += counts[c];
            }
        }
        ++counts[S[i]];
    }
    std::cout << total << std::endl;
    
    return 0;
}
