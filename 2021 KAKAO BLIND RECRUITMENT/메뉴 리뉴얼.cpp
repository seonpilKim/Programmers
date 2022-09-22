#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void dfs(map<string, int>& m, const string& order, const int& size, int& best, string cur, int index) {
    if (cur.size() == size) {
        sort(cur.begin(), cur.end());
        best = max(best, ++m[cur]);
        return;
    }

    for (int i = index; i < order.size(); i++) {
        dfs(m, order, size, best, cur + order[i], i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m;
    vector<int> best(11);

    for (const int& size : course) {
        for (const string& order : orders) {
            if (order.size() < size) {
                continue;
            }

            dfs(m, order, size, best[size], "", 0);
        }
    }

    auto iter = m.begin();
    while (iter != m.end()) {
        string newCourse = (*iter).first;
        int orderCount = (*iter).second;
        if (orderCount >= 2 && orderCount == best[newCourse.size()]) {
            answer.push_back(newCourse);
        }
        ++iter;
    }

    return answer;
}
