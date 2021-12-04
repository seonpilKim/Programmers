# [2개 이하로 다른 비트](https://programmers.co.kr/learn/courses/30/lessons/77885)
## 🤔접근
- 처음으로 0인 비트가 나온 위치를 찾고, 이를 적절하게 조정해보자.
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `bitmasking`
- <b>구현</b>
    - 먼저 숫자를 2진수 형태로 변환한 뒤, 오른쪽부터 탐색하여 가장 먼저 비트가 0인 인덱스를 찾는다.
        1. 0인 비트가 없는 경우
            - 맨 왼쪽 비트를 0으로 바꾸고, 1을 맨 왼쪽에 추가.
        2. 0인 비트가 맨 오른쪽에 있는 경우
            - 해당 비트를 1로 변경
        3. 그 외
            - 0인 비트와 오른쪽 비트를 swap
    - 다음으로 변겯왼 비트를 10진수로 변환해주었다.
## ✍ 피드백
## 💻 구현 코드
```c++
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (auto number : numbers) {
        vector<int> bits;
        
        // 현재 숫자를 2진수 형태로 저장
        while (number >= 2) {
            bits.push_back(number % 2);
            number /= 2;
        }
        bits.push_back(number);
        
        // 처음으로 0인 비트가 나오는 인덱스 찾기
        int idx = -1; // 0인 비트가 없는 경우를 위한 초기값
        for (int i = 0; i < bits.size(); i++) {
            if (bits[i] == 0) {
               idx = i;
                break;
            }
        }
        
        if (idx == -1) { // 0인 비트가 없는 경우, 맨 왼쪽 비트를 0으로 바꾸고, 1을 맨 왼쪽에 추가.
            bits[bits.size() - 1] = 0;
            bits.push_back(1);
        }
        else if (idx == 0)  // 0인 비트가 맨 오른쪽에 나오는 경우, 1로 변경
            bits[0] = 1;
        else // 0인 비트와 오른쪽의 1인 비트 위치를 변경
            swap(bits[idx], bits[idx - 1]);
        
        // 변경된 비트를 10진수로 변환하여 answer에 저장
        long long n = 0;
        for (int i = 0; i < bits.size(); i++) {
            if (bits[i] == 0)
                continue;
            
            n += pow(2, i);
        }
        
        answer.push_back(n);
    }
    
    return answer;
}
```