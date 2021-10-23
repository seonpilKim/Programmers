# [수식 최대화](https://programmers.co.kr/learn/courses/30/lessons/67257)
## 🤔접근
- 우선순위 경우의 수는 총 6가지이므로, 하나씩 우선순위를 설정해서 계산한 결과를 비교해보자.
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `Simulation`
- <b>구현</b>
    - 먼저 문자열을 parsing하여 숫자와 연산자로 나누어 각각 배열에 저장하였다.
        - 남은 숫자와 연산자가 없어질 때까지 우선순위에 맞게 연산을 진행하였다.
## ✍ 피드백
## 💻 구현 코드
```c++
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long operate(string expr, string prio) {
    vector<long long> nums;
    vector<char> ops;

    // parsing
    string tmp = "";
    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] != '-' && expr[i] != '+' && expr[i] != '*')
            tmp += expr[i];
        else {
            nums.push_back(stoi(tmp));
            tmp = "";
            ops.push_back(expr[i]);
        }
    }
    nums.push_back(stoi(tmp));

    // 우선순위에 맞게 연산 수행
    for (int i = 0; i < 3; i++) {
        char op = prio[i];

        vector<long long> tmp_nums;
        vector<char> tmp_ops;

        for (int j = 0, k = 0; j < nums.size() - 1; j++, k++) {
            if (ops[k] == op) {
                if (op == '-') {
                    nums[j + 1] = nums[j] - nums[j + 1];
                }
                else if (op == '+') {
                    nums[j + 1] = nums[j] + nums[j + 1];
                }
                else if (op == '*') {
                    nums[j + 1] = nums[j] * nums[j + 1];
                }
            }
            else {
                tmp_nums.push_back(nums[j]);
                tmp_ops.push_back(ops[k]);
            }
        }
        tmp_nums.push_back(nums.back());

        nums.clear();
        ops.clear();
        nums = tmp_nums;
        ops = tmp_ops;
    }

    return abs(nums.front());
}

long long solution(string expression) {
    long long answer = 0;

    vector<string> priority(6);
    priority[0] = "*+-";
    priority[1] = "*-+";
    priority[2] = "+*-";
    priority[3] = "+-*";
    priority[4] = "-*+";
    priority[5] = "-+*";

    for (int i = 0; i < 6; i++) 
        answer = max(answer, operate(expression, priority[i])); 

    return answer;
}
```