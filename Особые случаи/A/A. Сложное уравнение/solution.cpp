#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (a == 0) {
        if (b == 0) std::cout << "INF" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    else {
        int x = - b / a;
        if (x * a + b != 0 || c * x + d == 0) std::cout << "NO" << std::endl;
        else std::cout << x << std::endl;
    }

    return 0;
}