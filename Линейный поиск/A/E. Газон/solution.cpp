#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t x0, y0, x1, y1;
    std::cin >> x0 >> y0 >> x1 >> y1;
    int64_t x3, y3, r;
    std::cin >> x3 >> y3 >> r;
    if (x0 > x1) {
        std::swap(x0, x1);
    }
    if (y0 > y1) {
        std::swap(y0, y1);
    }

    int64_t total{0};
    for (int64_t y = std::max(y0, y3 - r); y <= std::min(y1, y3 + r); ++y) {
        auto x = std::pow(r*r - (y3 - y) * (y3 - y), 0.5);
        int64_t xmx = std::min(x1, (int64_t)std::floor(x3 + x));
        int64_t xmn = std::max(x0, (int64_t)std::ceil(x3 - x));
        if (xmx >= xmn) {
            total += xmx - xmn + 1;
        }
    }
    std::cout << total << std::endl;
    return 0;
}