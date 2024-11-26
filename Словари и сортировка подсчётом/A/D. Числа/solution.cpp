#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<uint64_t> a_counts(10, 0);
    std::vector<uint64_t> b_counts(10, 0);
    std::string input;
    std::cin >> input;
    for (auto c: input) ++a_counts[c - '0'];
    std::cin >> input;
    for (auto c: input) ++b_counts[c - '0'];

    bool print{false};
    for (int i = 9; i >= 0; --i) {
        int total = std::min(a_counts[i], b_counts[i]);
        if (i == 0 && total > 0 && !print) {
            print = true;
            std::cout << 0;
            break;
        }
        if (total > 0) {
            print = true;
            std::cout << std::string(total, '0' + i);
        }
    }
    if (!print) std::cout << -1;
    return 0;
}
