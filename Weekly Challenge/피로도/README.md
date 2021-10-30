# [피로도](https://programmers.co.kr/learn/courses/30/lessons/87946)
## 🤔접근
- 던전의 개수가 8개이므로, 모든 경우의 수를 구해봐야 8!이다.
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `next_permutation(순열)`
- <b>구현</b>
    - next_permutation을 이용하여 모든 경우의 수를 구하면서 최댓값을 구하였다.
## ✍ 피드백
## 💻 구현 코드
```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> v(dungeons.size());
    for (int i = 0; i < v.size(); i++)
        v[i] = i;

    do {
        int cur = k;
        int cnt = 0;

        for (int i = 0; i < dungeons.size(); i++) {
            if (dungeons[v[i]][0] > cur)
                continue;
            
            cur -= dungeons[v[i]][1];
            cnt++;
        }

        answer = max(answer, cnt);
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}
```