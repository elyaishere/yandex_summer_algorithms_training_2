#include <iostream>

struct Point {
    int x, y;

    int dist(const Point& p) const {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }

    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }
};

Point operator-(const Point& p1, const Point& p2) {
    return Point{.x = p1.x - p2.x, .y = p1.y - p2.y};
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    Point a, b, c, d;

    while (N-- > 0) {
        std::cin >> a.x >> a.y;
        std::cin >> b.x >> b.y;
        std::cin >> c.x >> c.y;
        std::cin >> d.x >> d.y;

        if (a.dist(b) == c.dist(d) && (a - b == c - d || a - b == d - c)) std::cout << "YES" << std::endl;
        else if (a.dist(c) == b.dist(d) && (a - c == b - d || a - c == d - b)) std::cout << "YES" << std::endl;
        else if (a.dist(d) == b.dist(c) && (a - d == b - c || a - d == c - b)) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }

    return 0;
}