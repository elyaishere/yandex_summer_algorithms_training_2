#include <iostream>
#include <stdint.h>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint64_t x_left{0}, x_right{1'000'000'000};
    bool ans;
    while (x_left < x_right) {
        std::cout << x_left << " " << 0 << std::endl;
        std::cout.flush();
        std::cin >> ans;
        std::cout << x_right << " " << 0 << std::endl;
        std::cout.flush();
        std::cin >> ans;
        if (ans) {
            x_left = ((x_left + x_right) >> 1) + 1;
        } else {
            x_right = ((x_left + x_right) >> 1);
        }
    }
    uint64_t y_left{0}, y_right{1'000'000'000};
    while (y_left < y_right) {
        std::cout << x_left << " " << y_left << std::endl;
        std::cout.flush();
        std::cin >> ans;
        std::cout << x_right << " " << y_right << std::endl;
        std::cout.flush();
        std::cin >> ans;
        if (ans) {
            y_left = ((y_left + y_right) >> 1) + 1;
        } else {
            y_right = ((y_left + y_right) >> 1);
        }
    }
    std::cout << "A " << x_left << " " << y_left << std::endl;
    std::cout.flush();
    return 0;
}