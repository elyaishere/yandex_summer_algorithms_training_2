#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

std::string CropName(const std::string& name, char c, int cnt) {
    int pos = 0;
    for (int j = 0; j < name.size(); ++j) {
        if (name[j] == c && ++pos == cnt) {
            pos = j + 1;
            break;
        }
    }
    return name.substr(pos);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a_name, b_name;
    std::cin >> a_name >> b_name;
    std::string res;
    bool exit = false;
    while (!exit) {
        std::vector<uint64_t> a_counts(26, 0);
        std::vector<uint64_t> b_counts(26, 0);
        exit = true;
        for (auto c: a_name) ++a_counts[c - 'a'];
        for (auto c: b_name) ++b_counts[c - 'a'];
        for (int i = 25; i >= 0; --i) {
            if (a_counts[i] > 0 && b_counts[i] > 0) {
                auto cnt = std::min(a_counts[i], b_counts[i]);
                char c = 'a' + i;
                res += std::string(cnt, c);
                a_name = CropName(a_name, c, cnt);
                b_name = CropName(b_name, c, cnt);
                exit = false;
                break;
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}
