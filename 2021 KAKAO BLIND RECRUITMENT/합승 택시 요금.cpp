#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>> adj, const int& src) {
    const int n = adj.size();
    vector<int> costs(n + 1, 1e9);
    costs[src] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);
    while (!pq.empty()) {
        int curCost = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for (const auto &next: adj[curNode]) {
            int nextNode = next.first;
            int nextCost = next.second + curCost;
            
            if (costs[nextNode] > nextCost) {
                costs[nextNode] = nextCost;
                pq.emplace(-nextCost, nextNode);
            }
        }
    }

    return costs;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (const auto &fare: fares) {
        adj[fare[0]].emplace_back(fare[1], fare[2]);
        adj[fare[1]].emplace_back(fare[0], fare[2]);
    }

    const vector<int> &srcCosts = dijkstra(adj, s);
    const vector<int> &aCosts = dijkstra(adj, a);
    const vector<int> &bCosts = dijkstra(adj, b);

    for (int i = 1; i <= n; i++) {
        if (srcCosts[i] == 1e9 || aCosts[i] == 1e9 || bCosts[i] == 1e9) {
            continue;
        }
        answer = min(answer, srcCosts[i] + aCosts[i] + bCosts[i]);
    }

    return answer;
}
