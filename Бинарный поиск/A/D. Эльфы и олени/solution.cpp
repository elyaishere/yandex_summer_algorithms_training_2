#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>


struct Participant {
    uint64_t id, quality;

    bool operator<(const Participant& rhs) const {
        return quality < rhs.quality;
    }
};

struct Result {
    struct Triple {
        uint64_t deer, elf_l, elf_r;
    };
    std::vector<Triple> ans;
    bool is_good;
};

Result check(uint64_t cnt, const std::vector<Participant>& deers, const std::vector<Participant>& elfs) {
    uint64_t nowdeer{0};
    std::vector<Result::Triple> ans;
    for (int l = 0; l < cnt; ++l) {
        auto r = elfs.size() - cnt + l;
        while (nowdeer < deers.size() && deers[nowdeer].quality <= elfs[l].quality) ++nowdeer;
        if (nowdeer == deers.size() || deers[nowdeer].quality >= elfs[r].quality) return {.ans = {}, .is_good = false};
        ans.push_back({deers[nowdeer].id, elfs[l].id, elfs[r].id});
        ++nowdeer;
    }
    return {.ans = std::move(ans), .is_good = true};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint64_t n, m;
    std::cin >> m >> n;
    std::vector<Participant> deers(m);
    std::vector<Participant> elfs(n);
    for (int i = 1; i <= m; ++i) {
        std::cin >> deers[i - 1].quality;
        deers[i - 1].id = i;
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> elfs[i - 1].quality;
        elfs[i - 1].id = i;
    }
    std::sort(deers.begin(), deers.end());
    std::sort(elfs.begin(), elfs.end());

    uint64_t l{0}, r{std::min(m, n >> 1)};
    while (l < r) {
        auto m = (l + r + 1) >> 1;
        auto res = check(m, deers, elfs);
        if (res.is_good) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    std::cout << l << std::endl;
    auto res = check(l, deers, elfs);
    for (const auto& t: res.ans) {
        std::cout << t.deer << " " << t.elf_l << " " << t.elf_r << std::endl;
    }

    return 0;
}