## [[Lv. 3] λ±κ΅£κΈΈ](https://programmers.co.kr/learn/courses/30/lessons/42898)
![](imgs/1.PNG)
![](imgs/2.PNG)
___

## π‘ νμ΄
- λμ κ³νλ²μΌλ‘ ν΄κ²°νμλ€.
- DFSμΌλ‘λ ν΄κ²°ν  μ μμ§λ§, μ€λ³΅μΌλ‘ λ°©λ¬Ένλ μ§μ­μ΄ λ§€μ° λ§μ λΉν¨μ¨μ μ΄λ€.
- μμ΄λμ΄λ λ€μκ³Ό κ°λ€.
    - μ€λ₯Έμͺ½κ³Ό μλλ‘λ§ μ΄λν  μ μμΌλ―λ‘, μΆλ° μ₯μμμ νμ¬ μ§μ­μ μ μ§μ­κ³Ό μΌμͺ½ μ§μ­κΉμ§ λλ¬ν  μ μλ κ°κ°μ κ²½μ°μ μμ ν©μ΄ νμ¬ μ₯μκΉμ§ λλ¬ν  μ μλ μ΄ κ²½μ°μ μμ΄λ€.
    - λ¬Όμ΄ κ³ μΈ μ§μ­μ λ°©λ¬Ένμ§λ, κ²½μ°μμμ λνμ§λ μμμ μ£Όμνμ.
___
```c++
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    // μ΄μ°¨μ λ²‘ν° ν λΉ
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // μΆλ° μ₯μμ κ²½μ°μ μλ 1λ‘ μ€μ 
    dp[0][0] = 1;
    // λ¬Όμ΄ κ³ μΈ μ§μ­ μ€μ 
    for (int i = 0; i < puddles.size(); i++) {
        int r = puddles[i][1] - 1;
        int c = puddles[i][0] - 1;
       dp[r][c] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // μΆλ°μ₯μλ μλ΅
            if (i == 0 && j == 0)
                continue;
            // νμ¬ μ§μ­μ΄ λ¬Όμ΄ κ³ μΈ μ§μ­μ΄ μλλΌλ©΄
            if (dp[i][j] != -1) {
                int left = 0;
                int top = 0;

                // μ μ§μ­μ΄ κ²©μ μ΄λ΄ & λ¬Όμ΄ κ³ μΈ μ§μ­μ΄ μλλΌλ©΄
                if (i > 0 && dp[i - 1][j] != -1)
                    top = dp[i - 1][j];
                // μΌμͺ½ μ§μ­μ΄ κ²©μ μ΄λ΄ & λ¬Όμ΄ κ³ μΈ μ§μ­μ΄ μλλΌλ©΄
                if (j > 0 && dp[i][j - 1] != -1)
                    left = dp[i][j - 1];

                // νμ¬ μ§μ­κΉμ§ λλ¬νλ κ²½μ°μ μλ left + top
                dp[i][j] = (left + top) % 1000000007;
            }
        }
    }

    answer = dp[n-1][m-1];
    
    return answer;
}
```