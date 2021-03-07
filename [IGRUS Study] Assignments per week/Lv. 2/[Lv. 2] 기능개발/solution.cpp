#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;

    for (int i = 0; i < progresses.size(); i++) {
        day = ceil((double)(100 - progresses[i]) / speeds[i]);
        
        if (answer.empty() || max_day < day) 
            answer.push_back(1);
        else 
            ++answer.back();
        
        if (day > max_day) 
            max_day = day;           
    }
   
    return answer;
}