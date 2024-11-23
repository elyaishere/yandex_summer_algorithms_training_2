#include <iostream>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int P;
    std::cin >> P;
    int c = int(P / 3) + int(P % 3 != 0);
    if (P - c <= c) {
        std::cout << -1 << std::endl;
        return 0;
    }
    if (P % 3 == 0) {
        std::cout << int(P / 3) << " " << int(P / 3) << " " << int(P / 3) << std::endl;
    } else if (P % 3 == 1) {
        std::cout << int(P / 3) << " " << int(P / 3) << " " << int(P / 3) + 1 << std::endl;
    } else {
        std::cout << int(P / 3) << " " << int(P / 3) + 1 << " " << int(P / 3) + 1 << std::endl;
    }
    c = int(P / 2) - int(P % 2 == 0); 
    std::cout << P - 2 * c << " " << c << " " << c << std::endl;
    return 0;
}