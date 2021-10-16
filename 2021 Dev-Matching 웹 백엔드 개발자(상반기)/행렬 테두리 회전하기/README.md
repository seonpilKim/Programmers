# [행렬 테두리 회전하기](https://programmers.co.kr/learn/courses/30/lessons/77485)
___
## 🤔접근
- 주어진 조건에 따라 구현하는 문제이다.
___
## 💡풀이
- <b>구현</b>
    - 먼저, 좌측 상단의 값(minRow, minCol)을 start 변수에 저장해두고, answer 배열에 push하였다.
    - 다음으로 반시계 방향으로 이동하면서 값을 한 칸씩 당겨주었다.
        - 이 과정에서 answer의 맨 끝 원소와 비교해서 최솟값을 갱신해주었다.
    - 마지막으로 (minRow, minCol + 1)칸에 start 변수의 값을 대입해주었다.
___
## ✍ 피드백
___
## 💻 구현 코드
```c++
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> v(rows + 1, vector<int>(columns + 1));
    for(int i=1;i<=rows;i++)
        for(int j=1;j<=columns;j++)
            v[i][j] = (i - 1) * columns + j;
    
    for(auto query : queries){
        int minRow = query[0];
        int minCol = query[1];
        int maxRow = query[2];
        int maxCol = query[3];

        int start = v[minRow][minCol];
        answer.push_back(start);
        for(int row = minRow; row < maxRow; row++){
            v[row][minCol] = v[row + 1][minCol];
            answer.back() = min(answer.back(), v[row][minCol]);
        }
        for(int col = minCol; col < maxCol; col++){
            v[maxRow][col] = v[maxRow][col + 1];
            answer.back() = min(answer.back(), v[maxRow][col]);
        }
        for(int row = maxRow; row > minRow; row--){
            v[row][maxCol] = v[row - 1][maxCol];
            answer.back() = min(answer.back(), v[row][maxCol]);
        }
        for(int col = maxCol; col > minCol + 1; col--){
            v[minRow][col] = v[minRow][col - 1];
            answer.back() = min(answer.back(), v[minRow][col]);
        }
        v[minRow][minCol + 1] = start;
    }    

    return answer;
}
```