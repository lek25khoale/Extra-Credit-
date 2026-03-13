#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    string name;
    int start, finish, weight;
};

vector<int> schedule;

int latest_compatible(const vector<Job>& jobs, int j) { //find the latest job that finishes before job j starts
    int lo = 0, hi = j - 1, result = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[j].start) {
            result = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return result;
}

void schedule_fill(const vector<Job>& jobs) { // fills the schedule table from bottom up
    int n = jobs.size();
    schedule.assign(n, 0);

    for (int j = 0; j < n; ++j) {
        int p = latest_compatible(jobs, j);
        int include = jobs[j].weight + (p >= 0 ? schedule[p] : 0);
        int exclude = (j > 0) ? schedule[j - 1] : 0; 
        schedule[j] = max(include, exclude);
    }
}

void find_solution(const vector<Job>& jobs, int j, vector<string>& selected) {
    if (j < 0)
        return;

    int p = latest_compatible(jobs, j);
    int include = jobs[j].weight + (p >= 0 ? schedule[p] : 0);
    int exclude = (j > 0) ? schedule[j - 1] : 0;

    if (include >= exclude) {
        selected.push_back(jobs[j].name);
        find_solution(jobs, p, selected);
    } else {
        find_solution(jobs, j - 1, selected);
    }
}

void print_jobs(const vector<Job>& jobs) {
    cout << "Jobs:\n";
    for (const auto& j : jobs)
        cout << "  " << j.name << ": start=" << j.start
             << " finish=" << j.finish
             << " weight=" << j.weight << "\n";
}

int main() {
    vector<Job> jobs = {
        {"1", 0, 3,  1},
        {"2", 2, 5,  2},
        {"3", 4, 7,  3},
        {"4", 6, 9,  4},
        {"5", 8, 11, 5}
    };

    print_jobs(jobs);

    schedule_fill(jobs);

    vector<string> selected;
    find_solution(jobs, jobs.size() - 1, selected);

    // reverse to show in order
    reverse(selected.begin(), selected.end());

    cout << "\nSelected jobs:\n";
    int total = 0;
    for (const string& name : selected) {
        for (int i = 0; i < (int)jobs.size(); ++i) {
            if (jobs[i].name == name) {
                cout << "  " << name << ": start=" << jobs[i].start
                     << " finish=" << jobs[i].finish
                     << " weight=" << jobs[i].weight << "\n";
                total += jobs[i].weight;
            }
        }
    }

    cout << "\nTotal weight: " << total;

    return 0;
}