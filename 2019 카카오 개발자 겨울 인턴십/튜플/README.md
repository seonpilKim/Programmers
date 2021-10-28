# [튜플](https://programmers.co.kr/learn/courses/30/lessons/64065)
## 🤔접근
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `Simulation`
    - `unordered_map`
    - `unordered_set`
- <b>구현</b>
    - 먼저, 각 부분 집합의 원소 개수에 따라 unordered_map에 `{원소 개수, 부분 집합}` 형태로 저장하였다.
        > ex) m[1] = "2", m[2] = "2,1", m[3] = "2,1,3", m[4] = "2,1,3,4"
    - 다음으로, 원소 개수가 1개일 때 부터, 최대 개수까지 차례대로 탐색하며 아래의 작업을 수행하였다.
        - 콤마(,) 단위로 원소를 파싱하여 unordered_set에 존재하지 않는 원소라면, 해당 원소를 answer와 unordered_set에 저장하였다.
        - 이 때, 반환 타입이 int이므로, answer에 저장할 때는 `stoi` 함수를 사용해서 정수형으로 변환해주고 저장하였다.
## ✍ 피드백
## 💻 구현 코드
```c++
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(string str) {
    vector<int> answer;

    unordered_set<string> s;
    unordered_map<int, string> m;

    bool flag = false;
    int cnt = 0;
    string tmp = "";
    for (int i = 1; i < str.size() - 1; i++) {
        if (str[i] == '{') {
            tmp = "";
            cnt = 0;
            flag = true;
        }
        else if (str[i] == '}') {
            m[cnt + 1] = tmp;
            flag = false;
        }
        else if (flag) {
            if (str[i] == ',')
                cnt++;
            tmp += str[i];
        }
    }

    string cur = "";
    for (int i = 1; i <= m.size(); i++) {
        string tmp = "";
        for (char c : m[i]) {
            if (c == ',') {
                if (s.find(tmp) == s.end()) {
                    s.insert(tmp);
                    cur = tmp;
                }
                tmp = "";
            }
            else
                tmp += c;
        }
        if (s.find(tmp) == s.end()) {
            s.insert(tmp);
            cur = tmp;
        }
        answer.push_back(stoi(cur));
    }

    return answer;
}
```