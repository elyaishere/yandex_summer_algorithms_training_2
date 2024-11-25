#include <iostream>
#include <unordered_set>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> points(n);
    std::vector<int> numbers(n, 0);
    for (auto& i: points) std::cin >> i;
    std::unordered_set<int> used;
    std::unordered_set<int> used_twice;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> numbers[i];
        if (used.find(numbers[i]) != used.end()) {
            used_twice.insert(numbers[i]);
        }
        used.insert(numbers[i]);
    }
    int best_less = -1;
    int best_num = -1;
    for (int i = 1; i <= 101; ++i) {
        auto points_tmp = points;
        auto used_tmp = used;
        auto used_twice_tmp = used_twice;
        numbers[n - 1] = i;
        if (used_tmp.find(i) != used_tmp.end()) {
            used_twice_tmp.insert(i);
        }
        used_tmp.insert(i);
        int win_score = 102;
        for (int j = 101; j > 0; --j) {
            if ((used_tmp.find(j) != used_tmp.end()) && (used_twice_tmp.find(j) == used_twice_tmp.end())) {
                win_score = j;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (numbers[j] == win_score) {
                points_tmp[j] += win_score;
            }
        }
        int less = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (points_tmp[j] < points_tmp.back()) {
                ++less;
            }
        }
        if (less > best_less) {
            best_less = less;
            best_num = i;
        }
    }
    std::cout << best_num << std::endl;
    return 0;
}