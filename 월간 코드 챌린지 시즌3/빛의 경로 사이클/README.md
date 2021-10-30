# [아이템 줍기](https://programmers.co.kr/learn/courses/30/lessons/87694)
## 🤔접근
- 각 칸마다 빛을 4방향에서 한 번씩 쏘았을 때, 중복되지 않는 사이클을 찾고, 그 사이클의 길이를 구해야 한다.
    - 완전탐색을 진행하되, `각 칸마다 + 각 방향마다` 방문여부를 체크함으로써 사이클을 찾자.
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `Simulation`
    - `DFS`
- <b>구현</b>
    - isVisited[`행`][`열`][`현재 칸으로 들어오는 방향`] -> 이 배열로 사이클 여부를 판단하였다.
    - 격자에 적힌 문자에 따라 알맞게 `변형된 방향`과 `이동할 위치`을 구해서 DFS을 이용하여 완전탐색을 진행하였다.
    - 방문여부를 초기화하지 않아야 사이클 여부를 판단할 수 있음에 주의하자.
    - 만약, 사이클의 길이가 0이라면 이미 체크한 사이클이므로 바로 탐색을 종료하였다.
## ✍ 피드백
## 💻 구현 코드
```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void DFS(const vector<string>& grid, vector<int>& answer, vector<vector<vector<bool>>>& isVisited,
    int curRow, int curCol, int curDir, int cnt) {

    if (isVisited[curRow][curCol][curDir]) {
        if (cnt != 0)
            answer.push_back(cnt);
        return;
    }

    int maxRow = grid.size() - 1;
    int maxCol = grid[0].size() - 1;
    int nextRow = curRow;
    int nextCol = curCol;
    char dir = grid[curRow][curCol];
    int nextDir = curDir;
    
    if (curDir == UP) {
        if (dir == 'S') {
            nextDir = UP;
            nextRow = (curRow - 1 < 0 ? maxRow : curRow - 1);
        }
        else if (dir == 'L') {
            nextDir = LEFT;
            nextCol = (curCol - 1 < 0 ? maxCol : curCol - 1);
        }
        else if (dir == 'R') {
            nextDir = RIGHT;
            nextCol = (curCol + 1 > maxCol ? 0 : curCol + 1);
        }
    }
    else if (curDir == RIGHT) {
        if (dir == 'S') {
            nextDir = RIGHT;
            nextCol = (curCol + 1 > maxCol ? 0 : curCol + 1);
        }
        else if (dir == 'L') {
            nextDir = UP;
            nextRow = (curRow - 1 < 0 ? maxRow : curRow - 1);
        }
        else if (dir == 'R') {
            nextDir = DOWN;
            nextRow = (curRow + 1 > maxRow ? 0 : curRow + 1);
        }
    }
    else if (curDir == DOWN) {
        if (dir == 'S') {
            nextDir = DOWN;
            nextRow = (curRow + 1 > maxRow ? 0 : curRow + 1);
        }
        else if (dir == 'L') {
            nextDir = RIGHT;
            nextCol = (curCol + 1 > maxCol ? 0 : curCol + 1);
        }
        else if (dir == 'R') {
            nextDir = LEFT;
            nextCol = (curCol - 1 < 0 ? maxCol : curCol - 1);
        }
    }
    else if (curDir == LEFT) {
        if (dir == 'S') {
            nextDir = LEFT;
            nextCol = (curCol - 1 < 0 ? maxCol : curCol - 1);
        }
        else if (dir == 'L') {
            nextDir = DOWN;
            nextRow = (curRow + 1 > maxRow ? 0 : curRow + 1);
        }
        else if (dir == 'R') {
            nextDir = UP;
            nextRow = (curRow - 1 < 0 ? maxRow : curRow - 1);
        }
    }

    isVisited[curRow][curCol][curDir] = true;
    DFS(grid, answer, isVisited, nextRow, nextCol, nextDir, cnt + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    int maxRow = grid.size() - 1;
    int maxCol = grid[0].size() - 1;
    
    vector<vector<vector<bool>>> isVisited(maxRow + 1, vector<vector<bool>>(maxCol + 1, vector<bool>(4, false)));
    
    for(int row = 0; row <= maxRow; row++) {
        for(int col = 0; col <= maxCol; col++) {
            DFS(grid, answer, isVisited, row, col, UP, 0);
            DFS(grid, answer, isVisited, row, col, RIGHT, 0);
            DFS(grid, answer, isVisited, row, col, DOWN, 0);
            DFS(grid, answer, isVisited, row, col, LEFT, 0);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
```