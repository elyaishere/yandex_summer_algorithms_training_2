#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdint.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    uint64_t N;
    std::cin >> N;

    std::vector<uint64_t> counts(26, 0);
    std::string input;
    std::cin >> input;
    for (auto c: input) {
        ++counts[c - 'A'];
    }
    std::string res;
    char center;
    bool center_set{false};
    for (int i = 0 ; i < counts.size(); ++i) {
        if (counts[i] == 0) continue;
        if (counts[i] % 2 == 0) {
            res += std::string(counts[i] / 2, 'A' + i);
        }
        else {
            if (!center_set) {
                center_set = true;
                center = 'A' + i;
            }
            if (--counts[i] > 0) {
                res += std::string(counts[i] / 2, 'A' + i);
            }
        }
    }
    auto reverse = res;
    std::reverse(reverse.begin(), reverse.end());
    if (center_set) {
        res += center;
    }
    res += reverse;
    std::cout << res << std::endl;
    return 0;
}
