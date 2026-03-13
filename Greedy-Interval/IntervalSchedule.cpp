#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Interval {
    string name;
    int start;
    int end;
};

vector<Interval> interval_schedule(vector<Interval> intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.end < b.end;
    }); // sort by end time

    int end_interval = 0; // store end time of the last selected interval
    vector<Interval> random_set;

    for (const auto& interval : intervals) { // greedy select intervals that don't overlap with the last selected
        if (end_interval <= interval.start) { // Only pick  interval if it starts after the last one ends
            end_interval = interval.end;
            random_set.push_back(interval);
        }
    }

    return random_set;
}

void print_intervals(const vector<Interval>& intervals) {
    cout << "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        const auto& iv = intervals[i];
        cout << "(\"" << iv.name << "\", " << iv.start << ", " << iv.end << ")";
        if (i + 1 < intervals.size()) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    vector<Interval> intervals = {
        {"A", 0, 6}, {"B", 2, 4}, {"C", 1, 5}, {"D", 4, 6},
        {"E", 5, 10}, {"F", 6, 9}, {"G", 9, 10}, {"H", 8, 11}
    };

    cout << "Job intervals given:\n";
    print_intervals(intervals);
    cout << "\n";

    auto result = interval_schedule(intervals);

    cout << "Selected compatible jobs:\n";
    print_intervals(result);

    cout << "\nNumber of jobs selected:\n";
    cout << result.size() << "\n";

    return 0;
}