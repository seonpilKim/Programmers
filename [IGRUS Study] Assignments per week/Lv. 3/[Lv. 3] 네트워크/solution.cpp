#include <string>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    queue<int> q;
    int networks[200];
    fill(networks, networks + 200, 0);

    for (int i = 0; i < computers.size(); i++) {
        if (networks[i] == 0) {
            q.push(i);
            answer++;
        }

        while (!q.empty()) {
            int network = q.front(); q.pop();
            networks[network] = 1;

            int idx = 0;
            for (int computer : computers[network]) {
                if (computer == 1 && networks[idx] == 0) q.push(idx);
                idx++;
            }
        }
    }

    return answer;
}