#include <iostream>
#include <algorithm>
#include <vector>
#include <stdint.h>

enum class Type {Cap, Top, Pants, Boots};

struct Wear {
    uint64_t color;
    Type type;

    bool operator<(const Wear& rhs) const {
        return color < rhs.color;
    }
};

std::vector<Wear> ReadColors(Type type) {
    uint64_t N;
    std::cin >> N;
    std::vector<Wear> colors(N + 1, {.type = type});
    for (int i = 0; i < N; ++i) std::cin >> colors[i].color;
    colors[N].color = 100001;
    std::sort(colors.begin(), colors.end());
    return colors;
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto cap_colors = ReadColors(Type::Cap);
    auto top_colors = ReadColors(Type::Top);
    auto pants_colors = ReadColors(Type::Pants);
    auto boots_colors = ReadColors(Type::Boots);

    std::vector<Wear> merge(cap_colors.size() + top_colors.size() + pants_colors.size() + boots_colors.size() - 4);
    uint64_t pos{0};
    int64_t i{0}, j{0}, k{0}, t{0};
    while (i < cap_colors.size() - 1 || j < top_colors.size() - 1 || k < pants_colors.size() - 1 || t < boots_colors.size() - 1) {
        auto next = std::min({cap_colors[i], top_colors[j], pants_colors[k], boots_colors[t]});
        switch (next.type) {
            case Type::Cap:
                ++i;
                break;
            case Type::Top:
                ++j;
                break;
            case Type::Pants:
                ++k;
                break;
            case Type::Boots:
                ++t;
                break;
            default:
                break;
        }
        merge[pos++] = std::move(next);
    }
    i = j = k = t = -1;
    int64_t ansi, ansj, ansk, anst;
    uint64_t best = 100000;
    for (int64_t p = 0; p < merge.size(); ++p) {
        switch (merge[p].type) {
            case Type::Cap:
                i = p;
                break;
            case Type::Top:
                j = p;
                break;
            case Type::Pants:
                k = p;
                break;
            case Type::Boots:
                t = p;
                break;
            default:
                break;
        }
        if (i != -1 && j != -1 && k != -1 && t != -1) {
            auto mn = std::min({i, j, k, t});
            auto mx = std::max({i, j, k, t});
            if (merge[mx].color - merge[mn].color < best) {
                ansi = merge[i].color, ansj = merge[j].color, ansk = merge[k].color, anst = merge[t].color;
                best = merge[mx].color - merge[mn].color;
            }
        }
    }
    std::cout << ansi << " " << ansj << " " << ansk << " " << anst << std::endl;
    return 0;
}
