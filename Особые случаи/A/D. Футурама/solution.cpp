#include <iostream>
#include <numeric>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> body_to_mind(N + 1);
    std::iota(body_to_mind.begin(), body_to_mind.end(), 0);
    int i, j;
    for (int k = 0; k < M; ++k) {
        std::cin >> i >> j;
        std::swap(body_to_mind[i], body_to_mind[j]);
    }
    for (int k = 1; k < N - 1; ++k) {
        if (body_to_mind[k] != k) {
            int now = k;
            while (body_to_mind[now] != k) {
                std::cout << now << " " << N - 1 << std::endl;
                std::swap(body_to_mind[now], body_to_mind[N - 1]);
                now = body_to_mind[N - 1];
            }
            std::cout << now << " " << N << std::endl;
            std::swap(body_to_mind[now], body_to_mind[N]);
            now = body_to_mind[N];
            std::cout << now << " " << N << std::endl;
            std::swap(body_to_mind[now], body_to_mind[N]);
            now = body_to_mind[N];
            std::cout << body_to_mind[N - 1] << " " << N - 1 << std::endl;
            std::swap(body_to_mind[body_to_mind[N - 1]], body_to_mind[N - 1]);
        }
    }
    if (body_to_mind[N - 1] == N) {
        std::cout << N - 1 << " " << N << std::endl;
        std::swap(body_to_mind[N - 1], body_to_mind[N]);
    }
    
    return 0;
}