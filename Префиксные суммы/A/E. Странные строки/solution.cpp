#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <unordered_map>
#include <map>

std::vector<std::pair<char, uint64_t>> rle(const std::string& s) {
    std::vector<std::pair<char, uint64_t>> ans{{'#', 0}};
    for (auto c: s) {
        if (c == ans.back().first) {
            ans.back().second += 1;
        } else {
            ans.push_back({c, 1});
        }
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::cin >> input;
    auto rles = rle(input);
    std::unordered_map<char, uint64_t> singles;
    uint64_t ans = 0;
    for (const auto& now: rles) {
        if (now.first == '#') continue;
        auto prev = singles[now.first];
        singles[now.first] = std::max(singles[now.first], now.second);
        ans += singles[now.first] - prev;
    }

    std::unordered_map<std::string, std::vector<std::pair<uint64_t, uint64_t>>> pairs;
    for (int i = 1; i < rles.size() - 1; ++i) {
        std::string pair{rles[i].first, rles[i + 1].first};
        pairs[pair].push_back({rles[i].second, rles[i + 1].second});
    }

    for (const auto& [pair, lens]: pairs) {
        std::map<uint64_t, uint64_t> flen;
        for (const auto& nowlen: lens) {
            if (flen.find(nowlen.first) == flen.end()) {
                flen[nowlen.first] = 0;
            }
            flen[nowlen.first] = std::max(nowlen.second, flen[nowlen.first]);
        }
        uint64_t maxsecond{0};
        for (auto nowfirst = flen.rbegin(); nowfirst != flen.rend(); ++nowfirst) {
            auto nowmaxsecond = std::max(maxsecond, nowfirst->second);
            ans += (nowmaxsecond - maxsecond) * nowfirst->first;
            maxsecond = nowmaxsecond;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
