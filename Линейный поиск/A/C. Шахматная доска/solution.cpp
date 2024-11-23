#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<std::vector<bool>> f(8, std::vector<bool>(8, false));
    int x, y;
    for (int i = 0; i < N; ++i) {
        std::cin >> x >> y;
        f[x - 1][y - 1] = true;
    }
    int p{0};
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (f[i][j]) p += 4;
            if (f[i][j] && j + 1 < 8 && f[i][j+1]) p -= 2;
            if (f[i][j] && i + 1 < 8 && f[i+1][j]) p -= 2;
        }
    }
    std::cout << p << std::endl;
    return 0;
}