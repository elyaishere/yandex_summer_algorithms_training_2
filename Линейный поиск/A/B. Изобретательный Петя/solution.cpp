#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string x, z;
    std::cin >> x >> z;
    int ptr = (int)z.size() - 1;
    int ptr_x = (int)x.size() - 1;
    int y_len{0};
    while (ptr >= 0) {
        if (ptr_x < 0) {
            ptr_x = (int)x.size() - 1;
        }
        if (z[ptr] != x[ptr_x]) {
            ++y_len;
            ptr = (int)z.size() - 1 - y_len;
            ptr_x = (int)x.size() - 1;
        } else {
            --ptr, --ptr_x;
        }
    }
    std::cout << z.substr(z.size() - y_len) << std::endl;
    return 0;
}