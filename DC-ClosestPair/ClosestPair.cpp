#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// A 2D point with a label
struct Point {
    string name;
    double x, y;
};

// A pair of closest points and their distance
struct Closest {
    Point p1, p2;
    double dist;
};

double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// brute forcing all pairs in a small subset of points
Closest bforce(const vector<Point>& pts, int low, int high) {
    Closest best = {pts[low], pts[low + 1], distance(pts[low], pts[low + 1])};
    for (int i = low; i <= high; ++i) {
        for (int j = i + 1; j <= high; ++j) {
            double d = distance(pts[i], pts[j]);
            if (d < best.dist)
                best = {pts[i], pts[j], d};
        }
    }
    return best;
}

Closest strip_closest(vector<Point> strip, double delta) {
    // sort strip by y-coordinate
    sort(strip.begin(), strip.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });

    Closest best = {strip[0], strip[1], delta};

    for (int i = 0; i < (int)strip.size(); ++i) {
        for (int j = i + 1; j < (int)strip.size() && (strip[j].y - strip[i].y) < best.dist; ++j) {
            double d = distance(strip[i], strip[j]);
            if (d < best.dist)
                best = {strip[i], strip[j], d};
        }
    }
    return best;
}

Closest closest_pair(const vector<Point>& pts, int low, int high) {
    // if 3 or fewer points, use brute force
    if (high - low <= 2)
        return bforce(pts, low, high);

    int mid = (low + high) / 2;
    double mid_x = pts[mid].x;

    // recurse on both halves
    Closest left  = closest_pair(pts, low, mid);
    Closest right = closest_pair(pts, mid + 1, high);

    // best result from both halves
    Closest best = (left.dist < right.dist) ? left : right;
    double delta = best.dist;

    // collect points within delta of the dividing line into a strip
    vector<Point> strip;
    for (int i = low; i <= high; ++i) {
        if (abs(pts[i].x - mid_x) < delta)
            strip.push_back(pts[i]);
    }

    // check strip for a closer cross-half pair
    if (strip.size() >= 2) {
        Closest strip_best = strip_closest(strip, delta);
        if (strip_best.dist < best.dist)
            best = strip_best;
    }

    return best;
}

void print_points(const vector<Point>& pts) {
    cout << "Points:\n";
    for (const auto& p : pts)
        cout << "  " << p.name << ": (" << p.x << ", " << p.y << ")\n";
}

int main() {
    vector<Point> points = {
        {"A", 2.0,  3.0},
        {"B", 4.0,  7.0},
        {"C", 5.0,  1.0},
        {"D", 7.0,  4.0},
        {"E", 8.0,  9.0},
        {"F", 10.0, 2.0},
        {"G", 12.0, 6.0}
    };

    print_points(points);

    Closest result = closest_pair(points, 0, points.size() - 1);

    cout << "\nClosest pair:\n";
    cout << "  " << result.p1.name << ": (" << result.p1.x << ", " << result.p1.y << ")\n";
    cout << "  " << result.p2.name << ": (" << result.p2.x << ", " << result.p2.y << ")\n";
    cout << "  Distance: " << result.dist << "\n";

    return 0;
}