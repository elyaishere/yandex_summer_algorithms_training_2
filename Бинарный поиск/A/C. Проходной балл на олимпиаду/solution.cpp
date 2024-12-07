#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <map>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint64_t N, M, R;
    std::cin >> N >> M >> R;

    std::map<uint64_t, std::vector<uint64_t>> region_to_scores;
    std::map<uint64_t, bool> region_to_winners;

    for (int i = 0; i < N; ++i) {
        uint64_t id, region, points;
        bool is_winner;
        std::cin >> id >> region >> points >> is_winner;
        if (is_winner) {
            region_to_winners[region] = true;
            --M;
            continue;
        }
        region_to_scores[region].push_back(points);
    }
    std::vector<uint64_t> all_scores;
    all_scores.reserve(N);
    for (auto& [region, scores]: region_to_scores) {
        std::sort(scores.begin(), scores.end());
        if (!region_to_winners[region] && scores.size() > 0) {
            --M;
            scores.pop_back();
        }
        for (auto s: scores) all_scores.push_back(s);
    }
    std::sort(all_scores.begin(), all_scores.end());
    if (M >= all_scores.size()) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::cout << all_scores[all_scores.size() - M - 1] + 1 << std::endl;
    return 0;
}