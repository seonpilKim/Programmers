# [[1차] 뉴스 클러스터링](https://programmers.co.kr/learn/courses/30/lessons/17677)
___
## 🤔접근
- 연속되는 두 개의 알파벳씩 끊어서 다중집합을 만들자.
	- 대소문자 구별이 없어야 하므로, 대문자인 경우 아스키코드로 32만큼 더해서 소문자로 만들어주는 전처리가 필요하다.
- 각 문자열에서 만들 수 있는 원소들로 이루어진 집합을 A, B라고 해보자.
	- 먼저, 첫 번째 문자열을 차례대로 탐색하면서, 합집합 개수를 1 증가시키고, 집합 A에 해당 문자열을 추가하자.
	- 다음으로, 두 번째 문자열을 차례대로 탐색하면서 다음의 작업을 수행하자.
		- 집합 A에 존재한다면, 집합 A에서의 해당 문자열을 하나 제거하고, 교집합 개수를 1 증가시키자.
		- 그렇지 않다면, 합집합 개수를 1 증가시키자.
___
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `Simulation`
	- `map`
- <B>구현</B>
    - 공통으로 대문자 -> 소문자 전처리를 해준다.
	- 먼저, 첫 번쨰 문자열에서 차례대로 두 개의 연속되는 문자가 알파벳 소문자인 경우만 map(`tmp`)에서 key가 해당 두 문자인 value를 1 증가시키고, 합집합 개수(`total`)도 1 증가시키는 작업을 수행한다.
	- 다음으로, 두 번째 문자열에서 차례대로 두 개의 연속되는 문자가 알파벳 소문자인 경우만 다음 작업을 수행한다.
		- map(`tmp`)에서 해당 두 문자가 key인 value가 존재하는 경우, 해당 value를 1 감소시키고, 교집합 개수(`common`)을 1 증가시킨다.
		- 만약, 해당 key의 value가 존재하지 않으면, 합집합 개수(`total`)를 1 증가시킨다.
	- 최종적으로 total이 0인 경우는 65536, 이 외에는 나눗셈 연산 결과에 65536을 곱한 정수 값을 반환한다.
___
## ✍ 피드백
___
## 💻 구현 코드
```c++
#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int total = 0, common = 0;
    map<string, int> tmp;
    
    for (int i = 0; i < str1.size() - 1; i++) {
        char left = str1[i];
        char right = str1[i + 1];
        bool flag = true;

        if (left >= 'A' && left <= 'Z')
            left += 32;
        if (right >= 'A' && right <= 'Z')
            right += 32;

        if ((left >= 'a' && left <= 'z') && (right >= 'a' && right <= 'z')) {
            string str = "";
            str += left;
            str += right;
            
            tmp[str]++;
            total++;
        }
    }

    for (int i = 0; i < str2.size() - 1; i++) {
        char left = str2[i];
        char right = str2[i + 1];
        bool flag = true;

        if (left >= 'A' && left <= 'Z')
            left += 32;
        if (right >= 'A' && right <= 'Z')
            right += 32;

        if ((left >= 'a' && left <= 'z') && (right >= 'a' && right <= 'z')) {
            string str = "";
            str += left;
            str += right;
            
            if (tmp[str]) {
                tmp[str]--;
                common++;
            }
            else
                total++;
        }
    }

    if (total == 0)
        answer = 65536;
    else
        answer = (double)common / total * 65536;

    return answer;
}
```