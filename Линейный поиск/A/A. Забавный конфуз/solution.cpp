#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;
    int64_t mn, mx;
    std::cin >> mn;
    mx = mn;
    int64_t x;
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> x;
        mn = std::min(mn, x);
        mx = std::max(mx, x);
    }
    std::cout << mx - mn << std::endl;
    return 0;
}