# [교점에 별 만들기](https://programmers.co.kr/learn/courses/30/lessons/87377)
___
## 🤔접근
- 먼저 각각 직선끼리 두 개씩 골라서 이원 일차 연립방정식의 교점을 찾아야 한다.
    - 두 직선을 Ax + By = P, Cx + Dy = Q라 할 때, 2x2 행렬로 표현할 수 있다.
    - 위 행렬의 `역행렬`을 구함으로써, 교점(x, y)를 찾을 수 있다.
        - 문제에서 공식이 주어졌으므로 쓰면 된다.
- 가장 바깥쪽에 위치한 별까지만 그려야 하므로, 각 교점을 찾을 때 마다 `최소/최대 x, y 좌표를 갱신`해주어야 한다.
- 교점 중에서도 정수 교점만 찾아야 하므로, 공식을 적용하기 전에 `MOD로 나눴을 때의 나머지가 0인지 체크`해주어야 한다.
- 입력으로 주어지는 A, B, C가 최대 `1e6`이므로, 공식에 적용할 때 int 범위를 초과할 수 있으므로 `long long`을 사용하자.
___
## 💡풀이
- 코드 참고
___
## ✍ 피드백
___
## 💻 구현 코드
```c++
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    // 최소/최대값을 적당히 크게 설정해주지 않으면 메모리 초과 발생할 수 있음
    long long minX = 1e10, maxX = -1e10, minY = 1e10, maxY = -1e10; 
    vector<pair<int, int>> pos;

    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) {
            long long a = line[i][0], b = line[i][1], p = line[i][2];
            long long c = line[j][0], d = line[j][1], q = line[j][2];
            
            long long MOD = a * d - b * c;
            long long X = -p * d + b * q;
            long long Y = c * p - a * q;
    
            if(MOD == 0 || X % MOD != 0 || Y % MOD != 0)
                continue;
            X /= MOD;
            Y /= MOD;

            minX = min(minX, X);
            maxX = max(maxX, X);
            minY = min(minY, Y);
            maxY = max(maxY, Y);
            pos.emplace_back(X, Y);
        }
    }
    
    string row = string(maxX - minX + 1, '.');
    answer.assign(maxY - minY + 1, row);
    for (int i = 0; i < pos.size(); i++)
        answer[maxY - pos[i].second][pos[i].first - minX] = '*';
    
    return answer;
}
```