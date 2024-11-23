#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    int mx{0};
    int sm{0};
    int x;
    for (int i = 0; i < N; ++i) {
        std::cin >> x;
        sm += x;
        mx = std::max(mx, x);
    }
    if (2 * mx > sm) {
        std:: cout << 2 * mx - sm << std::endl;
    }
    else {
        std::cout << sm << std::endl;
    }
    
    return 0;
}