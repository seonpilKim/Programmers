# [아이템 줍기](https://programmers.co.kr/learn/courses/30/lessons/87694)
## 🤔접근
- 사각형 테두리는 지나갈 수 있다는 의미인 `1`을 표시하고, 사각형 내부는 지나갈 수 없다는 의미인 `2`를 표시하자.
    - 이렇게 표시를 함으로써, `BFS`를 통해 갈 수 있는 경로로만 이동하여 최단 경로를 구할 수 있다.
- 또한, `테두리가 1칸 차이로 붙어 있는 경우`에는, 최단 경로가 이상하게 만들어질 수 있으므로, 좌표 크기를 `2배`해주는 것이 핵심이다.
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `Simulation`
    - `BFS`
- <b>구현</b>
    - 먼저 좌표 크기를 `2배` 해주고, `영역 표시`를 해준다.
        - 처음에는 각각 `0`으로 초기화한다.
        - 사각형을 차례대로 테두리에는 `1`, 내부에는 `2` 표시를 해준다.
            - 테두리 표시를 할 때, 이미 사각형 내부인 경우에는 영역 표시를 생략한다.
    - 영역 표시가 끝났으면, BFS를 통해 시작 지점에서 출발 지점까지의 최단 경로를 구한 뒤, 2로 나눈 값을 반환한다.
## ✍ 피드백
## 💻 구현 코드
```c++
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> map(101, vector<int>(101, 0));

    // 영역 표시
    for (auto rec : rectangle) {
        int left_bottom_row = rec[1] * 2;
        int left_bottom_col = rec[0] * 2;
        int right_top_row = rec[3] * 2;
        int right_top_col = rec[2] * 2;

        for (int row = left_bottom_row; row <= right_top_row; row++) {
            if (map[row][left_bottom_col] == 0)
                map[row][left_bottom_col] = 1;
            if (map[row][right_top_col] == 0)
                map[row][right_top_col] = 1;
        }
        for (int col = left_bottom_col; col <= right_top_col; col++) {
            if (map[left_bottom_row][col] == 0)
                map[left_bottom_row][col] = 1;
            if (map[right_top_row][col] == 0)
                map[right_top_row][col] = 1;
        }
        for (int row = left_bottom_row + 1; row < right_top_row; row++) {
            for (int col = left_bottom_col + 1; col < right_top_col; col++)
                map[row][col] = 2;
        }
    }

    // BFS
    vector<vector<int>> dp(101, vector<int>(101, 1e9));
    queue<pair<int, pair<int, int>>> q;
    dp[characterY * 2][characterX * 2] = 0;
    q.emplace(0, make_pair(characterY * 2, characterX * 2));
    while (!q.empty()) {
        int cost = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        if (cost > dp[row][col])
            continue;

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            if (nextRow < 1 || nextCol < 1 || nextRow > 100 || nextCol > 100)
                continue;
            if (map[nextRow][nextCol] != 1)
                continue;
            if (dp[nextRow][nextCol] < cost + 1)
                continue;

            dp[nextRow][nextCol] = cost + 1;
            q.emplace(cost + 1, make_pair(nextRow, nextCol));
        }
    }
    
    answer = dp[itemY * 2][itemX * 2] / 2;

    return answer;
}
```