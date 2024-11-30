#include <algorithm>
#include <vector>
#include <iostream>
#include <stdint.h>

struct CandyBin {
    uint64_t quantity;
    int number;
};

void SolveThree(uint64_t a, uint64_t b, uint64_t c) {
    auto count = std::min(a, c);
    a -= count;
    b += count * 2;
    c -= count;
    if (a == 0 && c == 0) {
        std::cout << "1\n" << b << std::endl;
        return;
    }
    if (a == 0) {
        std::cout << "2\n" << b << " " << c << std::endl;
        return;
    }
    if (c == 0) {
        std::cout << "2\n" << a << " " << b << std::endl;
        return;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int K;
    std::cin >> K;
    std::vector<CandyBin> bins(K);
    for (auto &i: bins) std::cin >> i.quantity >> i.number;
    if (K == 1 && bins[0].number == 1) {
        std::cout << "1\n" << bins[0].quantity << std::endl;
        return 0;
    }
    if (K == 1 && bins[0].number == 2) {
        std::cout << "2\n" << bins[0].quantity << " " << bins[0].quantity << std::endl;
        return 0;
    }

    int left{0}, right{K - 1};
    uint64_t left_from = bins[left].quantity;
    uint64_t left_to;
    if (--bins[left].number > 0) {
        left_to = left_from;
        --bins[left].number;
    } else {
        if (left < right) {
            left_to = bins[++left].quantity;
            --bins[left].number;
        } else {
            left_to = left_from;
            left_from = 0;
        }
    }
    if (bins[left].number == 0 && left < right) ++left;

    uint64_t right_from = bins[right].quantity;
    uint64_t right_to;
    if (--bins[right].number > 0) {
        right_to = right_from;
        --bins[right].number;
    } else {
        if (left < right) {
            right_to = bins[--right].quantity;
            --bins[right].number;
        } else {
            right_to = right_from;
            right_from = 0;
        }
    }
    if (bins[right].number == 0 && left < right) --right;

    while (true) {
        if (left_from == 0 && right_from == 0) {
            // 0 left_to right_to 0
            std::cout << "2\n" << left_to << " " << right_to << std::endl;
            return 0;
        }

        if (left_from == 0) {
            // 0 left_to right_to right_from
            SolveThree(left_to, right_to, right_from);
            return 0;
        }

        if (right_from == 0) {
            // left_from left_to right_to 0
            SolveThree(left_from, left_to, right_to);
            return 0;
        }

        if (left_to == 0) {
            std::cout << "1\n" << right_to << std::endl;
            return 0;
        }

        if (right_to == 0) {
            std::cout << "1\n" << left_to << std::endl;
            return 0;
        }

        auto count = std::min(left_from, right_from);
        left_to += count;
        right_to += count;
        left_from -= count;
        right_from -= count;
        
        if (left_from == 0) {
            if (bins[left].number > 0) {
                --bins[left].number;
                left_from = left_to;
                left_to = bins[left].quantity;
                if (bins[left].number == 0 && left < right) ++left;
            } else if (left < right) {
                ++left;
                --bins[left].number;
                left_from = left_to;
                left_to = bins[left].quantity;
                if (bins[left].number == 0 && left < right) ++left;
            }
        }

        if (right_from == 0) {
            if (bins[right].number > 0) {
                --bins[right].number;
                right_from = right_to;
                right_to = bins[right].quantity;
                if (bins[right].number == 0 && left < right) --right;
            } else if (left < right) {
                --right;
                --bins[right].number;
                right_from = right_to;
                right_to = bins[right].quantity;
                if (bins[right].number == 0 && left < right) --right;
            }
        }
    }
}
