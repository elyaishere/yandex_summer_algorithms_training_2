#include <iostream>
#include <vector>

enum class item {empty, x, o};

std::vector<int> count_wins(const std::vector<item>& f) {
    std::vector<int> wins{0, 0, 0};
    for (int j = 0; j < f.size(); j += 3) {
        if (f[j] == f[j+1] && f[j+2] == f[j+1]) wins[(int)f[j]]++;
    }
    for (int j = 0; j < 3; j++) {
        if (f[j] == f[j+3] && f[j+6] == f[j+3])  wins[(int)f[j]]++;
    }
    if (f[0] == f[4] && f[8] == f[4]) wins[(int)f[0]]++;
    if (f[2] == f[4] && f[6] == f[4]) wins[(int)f[2]]++;
    return wins;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x_cnt = 0, o_cnt = 0;

    std::vector<item> field(9, item::empty);
    for (auto& i: field) {
        int x;
        std::cin >> x;
        i = static_cast<item>(x);
        if (i == item::x) x_cnt++;
        if (i == item::o) o_cnt++;
    }
    if ((x_cnt - o_cnt > 1) || (o_cnt > x_cnt)) std::cout << "NO" << std::endl;
    else {
        auto wins = count_wins(field);
        if (wins[1] == 2 && wins[2] == 0 && x_cnt + o_cnt == 9) std::cout << "YES" << std::endl;
        else if (!(wins[1] + wins[2] == 1 || wins[1] + wins[2] == 0)) std::cout << "NO" << std::endl;
        else if (wins[1] && !(x_cnt - o_cnt == 1)) std::cout << "NO" << std::endl;
        else if (wins[2] && !(x_cnt - o_cnt == 0)) std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;
    }
    return 0;
}