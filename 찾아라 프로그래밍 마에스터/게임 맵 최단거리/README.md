# [게임 맵 최단거리](https://programmers.co.kr/learn/courses/30/lessons/1844)
## 🤔접근
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `DP`
    - `BFS`
- <b>구현</b>
    - 코드 참고
## ✍ 피드백
## 💻 구현 코드
```c++
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int solution(vector<vector<int>> maps) {
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 1e9));
    queue<tuple<int, int, int>> q;
    dp[0][0] = 1;
    q.emplace(0, 0, 1);
    while (!q.empty()) {
        auto cur = q.front();
        int row = get<0>(cur);
        int col = get<1>(cur);
        int cost = get<2>(cur);
        q.pop();

        if (cost > dp[row][col])
            continue;

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];
            int nextCost = cost + 1;

            if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m)
                continue;
            if (maps[nextRow][nextCol] == 0)
                continue;
            if (dp[nextRow][nextCol] <= nextCost)
                continue;

            dp[nextRow][nextCol] = nextCost;
            q.emplace(nextRow, nextCol, nextCost);
        }
    }

    answer = (dp[n - 1][m - 1] == 1e9 ? -1 : dp[n - 1][m - 1]);

    return answer;
}
```