#include <iostream>
#include <vector>
#include <stdint.h>
#include <string>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::getline(std::cin, input);
    std::vector<uint64_t> balance(input.size(), 0);
    uint64_t cur_balance = 0;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == ')') ++cur_balance;
        else --cur_balance;
        balance[i] = cur_balance;
    }
    uint64_t ans = (input.size() + 1) * (input.size() + 2) / 2;
    int64_t prev_zero = -1;
    for (int i = 0; i < input.size(); ++i) {
        if (balance[i] == 0) {
            ans += (i - prev_zero - 1) * (i - prev_zero) / 2;
            prev_zero = i;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
