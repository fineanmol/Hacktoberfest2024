// Solving issue #7095
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double totalDistance(const std::vector<int>& path, const std::vector<Point>& cities) {
    double dist = 0.0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        dist += distance(cities[path[i]], cities[path[i + 1]]);
    }
    dist += distance(cities[path.back()], cities[path[0]]);
    return dist;
}

void printPath(const std::vector<int>& path) {
    for (int city : path) {
        std::cout << city << " -> ";
    }
    std::cout << path[0] << std::endl;
}

int main() {
    int n; // Number of cities
    std::cout << "Enter the number of cities: ";
    std::cin >> n;

    std::vector<Point> cities(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter the coordinates of city " << i << " (x y): ";
        std::cin >> cities[i].x >> cities[i].y;
    }

    std::vector<int> path(n);
    for (int i = 0; i < n; ++i) {
        path[i] = i;
    }

    double minDistance = std::numeric_limits<double>::max();
    std::vector<int> bestPath;

    do {
        double dist = totalDistance(path, cities);
        if (dist < minDistance) {
            minDistance = dist;
            bestPath = path;
        }
    } while (std::next_permutation(path.begin() + 1, path.end()));

    std::cout << "Shortest Path: ";
    printPath(bestPath);
    std::cout << "Shortest Distance: " << minDistance << std::endl;

    return 0;
}
