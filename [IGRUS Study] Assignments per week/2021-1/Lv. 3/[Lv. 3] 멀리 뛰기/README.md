## [[Lv. 3] ๋ฉ๋ฆฌ ๋ฐ๊ธฐ](https://programmers.co.kr/learn/courses/30/lessons/12914)
<br>![](imgs/1.PNG)
<br>
___

## ๐ก ํ์ด
- ๊ท์น์ฑ์ ๋จผ์  ํ์ํ ๋ค, `์ฌ๊ทํจ์` ํน์ `๋์ ๊ณํ๋ฒ`์ผ๋ก ํด๊ฒฐํ๋ ์ ํ์ ์ธ ๋ฌธ์ ์ด๋ค.
- ๊ท์น์ฑ์ ๋ค์๊ณผ ๊ฐ์๋ค.
    > 1์นธ ๊ฒฝ์ฐ์ ์ : 1<br>
    > 2์นธ ๊ฒฝ์ฐ์ ์ : 2<br>
    > 3์นธ ๊ฒฝ์ฐ์ ์ : 3<br>
    > 4์นธ ๊ฒฝ์ฐ์ ์ : 5<br>
    > 5์นธ ๊ฒฝ์ฐ์ ์ : 8<br>
    > ...
- ์ฆ, n > 2 ์ผ ๋, `dp[n] = dp[n - 1] + dp[n - 2]` ์ ๋ง์กฑํ๋ค.
___
```c++
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long dp[2001] = {0, };
    dp[1] = 1;
    dp[2] = 2;
    
    int idx = 3;
    while(idx <= n){
        dp[idx] = (dp[idx - 1] + dp[idx - 2]) % 1234567;
        idx++;
    }
    
    answer = dp[n];
    return answer;
}
```