#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <stdint.h>

uint64_t GetReminder(const std::string& number, uint64_t mod) {
    uint64_t res = 0;
    for (auto c: number) {
        res = (res * 10 + c - '0') % mod;
    }
    return res;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::vector<uint64_t> mods{uint64_t(10e9) + 7, uint64_t(10e9) + 11, uint64_t(10e9) + 13};
    std::vector<std::unordered_set<uint64_t>> hashes(mods.size());
    constexpr int max_fib_num = 40000;

    for (int i = 0; i < mods.size(); ++i) {
        uint64_t f1{1}, f2{1};
        hashes[i].insert(1);
        for (int j = 0; j < max_fib_num; ++j) {
            auto t = (f1 + f2) % mods[i];
            f1 = f2;
            f2 = t;
            hashes[i].insert(f2);
        }
    }

    int n;
    std::cin >> n;
    std::string num;
    std::getline(std::cin, num);
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, num);
        bool is_fib = true;
        for (int j = 0; j < mods.size(); ++j) {
            is_fib = is_fib && (hashes[j].find(GetReminder(num, mods[j])) != hashes[j].end());
        }
        if (is_fib) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}