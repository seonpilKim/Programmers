#include <string>

using namespace std;

string solution(string new_id) {
    string answer = "";
    const int size = new_id.size();
    bool isContinuous = false;

    for (int i = 0; i < size; i++) {
        char &character = new_id[i];
        int ascii = character;

        if (ascii >= 65 && ascii <= 90) { // phase 1
            answer += char(ascii + 32);
            isContinuous = false;
        } else if ((ascii >= 97 && ascii <= 122) || // phase 2
                   (ascii >= 48 && ascii <= 57) ||
                   ascii == 45 ||
                   ascii == 95 ) {
            answer += character;
            isContinuous = false;
        } else if (ascii == 46) { // phase 3
            if (!isContinuous) {
                isContinuous = true;
                answer += character;
            }
        }
    }

    // phase 4
    if (answer.front() == '.') {
        answer.erase(answer.begin());
    }
    if (answer.back() == '.') {
        answer.pop_back();
    }

    // phase 5
    if (answer.empty()) {
        answer += 'a';
    }

    // phase 6
    if (answer.size() > 15) {
        answer = answer.substr(0, 15);
        if (answer.back() == '.') {
            answer.pop_back();
        }
    }

    // phase 7
    while (answer.size() < 3) {
        answer += answer.back();
    }

    return answer;
}
