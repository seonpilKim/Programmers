# [[Lv. 2] νκ² λλ²](https://programmers.co.kr/learn/courses/30/lessons/43165)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
1. <b>nκ°μ μ μμ κ°κ° nκ°μ + νΉμ - λΆνΈλ₯Ό λΆμ¬νμ λ νκ² λλ²λ₯Ό κ΅¬ν  μ μλ κ²½μ°μ μλ₯Ό μ°ΎμμΌ νλ€.</b>
	- DFSμΌλ‘ λͺ¨λ  κ²½μ°μ μλ₯Ό νμνμ.
	- μ΅λ 2Β²β°λ² μ°μ°μ΄λ―λ‘ μΆ©λΆν λΉ λ₯΄κ² νμμ΄ κ°λ₯νλ€.
___
## π‘νμ΄
- <b>κΉμ΄ μ°μ  νμ(DFS) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
__
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
#include <string>
#include <vector>

using namespace std;

int cnt = 0;
vector<int> seq;
int targetNum;

void DFS(int idx, int res){
    if (idx == seq.size()){
        if (res == targetNum)
            cnt++;
        return;
    }
    
    DFS(idx + 1, res + seq[idx]);
    DFS(idx + 1, res - seq[idx]);
}

int solution(vector<int> numbers, int target) {
    seq = numbers;
    targetNum = target;
    DFS(0, 0);
    
    return cnt;
}
```