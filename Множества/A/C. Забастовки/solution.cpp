#include <iostream>
#include <unordered_set>
#include <stdint.h>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;
    std::unordered_set<int> days;
    for (int i = 1; i <= N; ++i) {
        if (i % 7 != 6 && i % 7 != 0) {
            days.insert(i);
        }
    }
    int counter = 0;
    int a, b;
    for (int i = 0; i < K; ++i) {
        std::cin >> a >> b;
        auto tmp = days;
        for (auto i: days) {
            if ((i >= a) && ((i - a) % b == 0) && (tmp.find(i) != tmp.end())) {
                ++counter;
                tmp.erase(i);
            }
        }
        days = std::move(tmp);
    }
    std::cout << counter << std::endl;
    return 0;
}