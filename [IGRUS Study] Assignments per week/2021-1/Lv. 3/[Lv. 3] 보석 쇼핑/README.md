## [[Lv. 3] ๋ณด์ ์ผํ](https://programmers.co.kr/learn/courses/30/lessons/67258#)
![](imgs/1.PNG)
![](imgs/2.PNG)
___

## ๐ก ํ์ด
- Two Pointer ๋ฐฉ์์ ์ด์ฉํ์ฌ ํด๊ฒฐํ  ์ ์๋ค.
    - STL set์ ์ด์ฉํ์ฌ, ์ค๋ณตx์ธ ๋ณด์์ ์ด ๊ฐ์๋ฅผ ๊ตฌํ๋ค.
    - ๋ค์์ผ๋ก, ๋ ๊ฐ์ ํฌ์ธํฐ(left, right)๊ฐ ์ฒซ ๋ฒ์งธ ์ธ๋ฑ์ค๋ฅผ ๊ฐ๋ฆฌํค๋๋ก ์ค์ ํ๋ค.
    - ๋ณด์์ ํ๋์ฉ ์ง์ ๋ ๋ง๋ค, unordered_map์ ์ ์ฅํ๋ค.
        - ๋ง์ฝ, map์ ์์ ๊ฐ์๊ฐ ์๋ก ๋ค๋ฅธ ๋ณด์์ ์ด ๊ฐ์์ ๊ฐ๋ค๋ฉด
            - right - left๊ฐ answer์ ์ ์ฅ๋ ๊ฒ ๋ณด๋ค ๋ ์งง์ ๊ตฌ๊ฐ์ด๋ผ๋ฉด, ๊ฐฑ์ ํ๋ค.
            - ๊ฐ์ฅ ๋จผ์  ์ง์ ๋ณด์(left)์ map์์ ์ ๊ฑฐํ๊ณ , left pointer๋ฅผ 1 ์ฆ๊ฐ์ํจ๋ค.
        - ๋ง์ฝ, map์ ์์ ๊ฐ์๊ฐ ์๋ก๋ค๋ฅธ ๋ณด์์ ์ด ๊ฐ์๋ณด๋ค ์ ๋ค๋ฉด
            - right pointer๊ฐ ์ธ๋ฑ์ค ๋ฒ์๋ฅผ ๋ฒ์ด๋ ๊ฒฝ์ฐ, ๋ฐ๋ณต๋ฌธ ํ์ถ
            - right pointer๋ฅผ 1 ์ฆ๊ฐ์ํค๊ณ , ํด๋น ์์น์ ์๋ ๋ณด์์ map์ ์ ์ฅํ๋ค.
___
```c++
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> gems_list;
    // ํ์ฌ ๋ค๊ณ ์๋ ๋ณด์๋ค์ ์ ์ฅํ๋ ์๋ฃ๊ตฌ์กฐ
    // <๋ณด์ ์ด๋ฆ, ๋ณด์ ๊ฐ์>
    unordered_map<string, int> m;
    
    int left = 0, right = 0, gems_cnt;
    int len = gems.size();
    
    answer[0] = 0;
    answer[1] = len - 1;
    
    for(int i=0; i<len; i++)
        gems_list.insert(gems[i]);
    gems_cnt = gems_list.size();
    
    m[gems[0]]++;
    while(true){
        if(m.size() == gems_cnt){
            if(answer[1] - answer[0] > right - left){
                answer[0] = left;
                answer[1] = right;
            }

            m[gems[left]]--;
            if(m[gems[left]] == 0)
                m.erase(gems[left]);
            left++;       
        }
        else if(m.size() < gems_cnt){
            if(right + 1 >= len)
                break;
            else
                m[gems[++right]]++;
        }
    }
    
    answer[0]++;
    answer[1]++;
    
    return answer;
}
```