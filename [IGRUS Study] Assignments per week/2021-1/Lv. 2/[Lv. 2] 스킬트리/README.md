## [[Lv. 2] μ€ν¬νΈλ¦¬](https://programmers.co.kr/learn/courses/30/lessons/49993)
![](imgs/1.PNG)
___

## π‘ νμ΄
- μ£Όμ΄μ§ skill_treesμμ κ°κ° μ€ν¬νΈλ¦¬μ μ€ν¬μ μ°¨λ‘λλ‘ νμνλ©΄μ, λ€μμ λ κ°μ§ μμμ ν΄μΌ νλ€.
    1. ν΄λΉ μ€ν¬μ΄ μ ν μ€ν¬μ μνλμ§ νλ³
        - νμ μ°μ°μ΄ O(1)μΈ `unordered_map`μ μ ν μ€ν¬μ μ μ₯ν¨μΌλ‘μ¨ νμ μ°μ° μ΅μ ν
    2. μ ν μ€ν¬μ΄λΌλ©΄, μμμ λ§κ² λ°°μ°λ κ²μΈμ§ νλ³
        - μΈλ±μ€ λ³μλ₯Ό μ΄μ©νμ¬ μμ νλ³ - O(1)
___
## β νΌλλ°±
___
```c++
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int> m;
    
    int idx = 0;
    for(auto& s : skill)
        m.emplace(s, idx++);
    
    for(auto& skill_tree : skill_trees){
        bool flag = true;
        idx = 0;
        
        for(auto& sk : skill_tree){
            if(m.find(sk) != m.end()){
                if(m[sk] != idx++){
                    flag = false;
                    break;
                }
            }       
        }
        
        if(flag)
            answer++;
    }
    
    return answer;
}
```