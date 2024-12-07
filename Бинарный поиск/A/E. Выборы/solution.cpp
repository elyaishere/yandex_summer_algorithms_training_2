#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>


struct Party {
    uint64_t id, v;

    bool operator<(const Party& rhs) const {
        return v < rhs.v;
    }
};

struct Result {
    uint64_t votes, l, recovery;
};

uint64_t getcntvotes(int i, const std::vector<Party>& parties, const std::vector<uint64_t>& suffixsum, uint64_t level) {
    uint64_t l{0}, r = parties.size() - 1;
    while (l < r) {
        auto m = (l + r) >> 1;
        if (parties[m].v < level) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (parties[l].v < level) {
        return 0;
    }
    auto cntvotes = suffixsum[l] - level * (parties.size() - l);
    if (parties[i].v >= level) {
        cntvotes -= (parties[i].v - level);
    }
    return cntvotes;
}

Result check(const std::vector<Party>& parties, int i, const std::vector<uint64_t>& suffixsum) {
    uint64_t l{0}, r = 10e6;
    while (l < r) {
        auto level = (l + r + 1) >> 1;
        auto cntvotes = getcntvotes(i, parties, suffixsum, level);
        if (cntvotes + parties[i].v > level) {
            l = level;
        } else {
            r = level - 1;
        }
    }
    auto cntvotes = getcntvotes(i, parties, suffixsum, l);
    uint64_t recovery = 0;
    if (parties[i].v + cntvotes > l + 2) {
        recovery = parties[i].v + cntvotes - l - 2;
    }
    return {cntvotes - recovery, l, recovery};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint64_t n;
    std::cin >> n;
    std::vector<int64_t> p(n);
    std::vector<Party> parties(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> parties[i].v >> p[i];
        parties[i].id = i;
    }
    std::sort(parties.begin(), parties.end());
    
    std::vector<uint64_t> suffix_sums(n, 0);
    suffix_sums.back() = parties.back().v;
    for (int i = n - 2; i >= 0; --i) {
        suffix_sums[i] = suffix_sums[i + 1] + parties[i].v;
    }

    uint64_t mincost = 10e6 + 10e12 + 1;
    std::vector<uint64_t> ans(4);
    for (uint64_t i = 0; i < n; ++i) {
        if (p[parties[i].id] != -1) {
            auto res = check(parties, i, suffix_sums);
            if (p[parties[i].id] + res.votes < mincost) {
                mincost = p[parties[i].id] + res.votes;
                ans = {i, res.votes, res.l, res.recovery};
            }
        }
    }
    std::vector<uint64_t> resvotes(n, 0);
    for (uint64_t i = 0; i < n; ++i) {
        if (i == ans[0]) {
            resvotes[parties[i].id] = parties[i].v + ans[1];
        } else if (parties[i].v <= ans[2]) {
            resvotes[parties[i].id] = parties[i].v;
        } else {
            if (ans.back() > 0) {
                resvotes[parties[i].id] = ans[2] + 1;
                ans.back() -= 1;
            } else {
                resvotes[parties[i].id] = ans[2];
            }
        }
    }
    std::cout << mincost << std::endl;
    std::cout << parties[ans[0]].id + 1 << std::endl;
    for (auto i: resvotes) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
