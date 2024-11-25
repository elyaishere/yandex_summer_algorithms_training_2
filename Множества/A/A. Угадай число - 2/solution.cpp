#include <iostream>
#include <set>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::unordered_set<int> numbers;
    for (int i = 1; i <= n; ++i) {
        numbers.insert(i);
    }

    std::string input;
    std::getline(std::cin, input);
    std::getline(std::cin, input);
    while (input != "HELP") {
        std::istringstream ss(input);
        std::unordered_set<int> numbers_;
        int d;
        while (ss >> d) {
            numbers_.insert(d);
        }
        auto tmp = numbers_;

        for (auto i: numbers_) {
            if (numbers.find(i) != numbers.end()) {
                numbers.erase(i);
            } else {
                tmp.erase(i);
            }
        }
        if (tmp.size() > numbers.size()) {
            std::cout << "YES" << std::endl;
            numbers = std::move(tmp);
        } else {
            std::cout << "NO" << std::endl;
        }
        std::getline(std::cin, input);
    }
    std::set<int> res(numbers.begin(), numbers.end());
    for (auto i: res) std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}