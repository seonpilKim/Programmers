# [야근 지수](https://programmers.co.kr/learn/courses/30/lessons/12927)
___
## 🤔접근
___
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `우선순위 큐`
- <b>구현</b>
    - 가장 작업량이 많은 작업부터 1시간씩 수행하는 방법이 야근 피로도를 최소화할 수 있는 방법이다.
    - 따라서, 우선순위 큐에 작업들을 넣어 놓고, 하나씩 1시간씩 수행한 다음, 다시 우선순위 큐에 남은 작업 시간을 넣는 방식으로 구현하였다.
___
## ✍ 피드백
___
## 💻 구현 코드
```c++
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for(auto work : works)
        pq.push(work);
    
    while(n-- && !pq.empty()){
        int work = pq.top() - 1;
        pq.pop();
        if(work > 0)
            pq.push(work);
    }
    while(!pq.empty()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}
```