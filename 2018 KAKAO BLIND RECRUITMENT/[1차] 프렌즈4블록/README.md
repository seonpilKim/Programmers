# [[1차] 프렌즈4블록](https://programmers.co.kr/learn/courses/30/lessons/17679)
___
## 🤔접근
- 보드의 최대 크기가 30x30 이므로, 완전 탐색으로 풀었다.
___
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `Simulation`
    - `Brute Force`
	- `set`
- <B>구현</B>
    - 먼저 보드를 하나씩 탐색하면서, 현재 블록 기준으로 2x2 블록씩 4방향으로 탐색해서 동일 블록으로만 이루어져 있으면, set 자료구조를 이용하여 위치를 저장하였다.
        - 중복되어 저장되는 경우를 방지하기 위해 set 자료구조를 이용하였다.
    - 탐색이 끝난 후, 지워질 블록들이 존재하는지 파악한 후, 각 블록들을 지워주었다.
    - 다시 보드를 밑에서부터 탐색하면서, 빈 공간이 있다면 위쪽에 존재하는 블록을 아래로 내려주었다.
    - 마지막으로, 지워진 블록의 개수를 answer 변수에 더해주었다.
    - 지워질 블록들이 더 이상 존재하지 않을 때 까지 위 과정을 반복하였다.
___
## ✍ 피드백
___
## 💻 구현 코드
```c++
#include <string>
#include <vector>
#include <set>

using namespace std;

const int dr[4][3] = {{-1, -1, 0}, {-1, -1, 0}, {1, 1, 0}, {1, 1, 0}};
const int dc[4][3] = {{0, -1, -1}, {0, 1, 1}, {0, -1, -1}, {0, 1, 1}};

// 30 x 30 -> 완전탐색
int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (true) {
        set<pair<int, int>> s; // 지워질 블록들의 위치 저장
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                char cur = board[row][col];
                if (cur == ' ')
                    continue;

                for (int i = 0; i < 4; i++) {
                    vector<pair<int, int>> v; // 같은 블록 위치 저장

                    for (int j = 0; j < 3; j++) {
                        int newRow = row + dr[i][j];
                        int newCol = col + dc[i][j];

                        if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
                            continue;
                        if (board[newRow][newCol] != cur)
                            continue;
                        
                        v.emplace_back(newRow, newCol);
                    }

                    if (v.size() == 3) { // 같은 블록이 2x2 형태로 있는 경우
                        for (auto pos : v)
                            s.emplace(pos.first, pos.second);
                    }
                }
            }
        }
        
        // 2x2 형태로 4개가 붙어 있는 블록이 더 이상 없는 경우
        if (s.empty())
            break;
        
        // 블록 지우기
        auto iter = s.begin();
        while (iter != s.end()) {
            board[iter->first][iter->second] = ' ';
            ++iter;
        }
        
        // 블록 아래로 떨어뜨리기
        for (int row = m - 1; row > 0; row--) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] != ' ')
                    continue;
                
                for (int i = row - 1; i >= 0; i--) {
                    if (board[i][col] != ' ') {
                        board[row][col] = board[i][col];
                        board[i][col] = ' ';
                        break;
                    }
                }
            }
        }
        
        // 지워진 블록 개수 더해주기
        answer += s.size();
    }

    return answer;
}
```