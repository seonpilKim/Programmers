#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string ANYTHING = "-";
const int LANGUAGE = 0;
const int ROLE = 1;
const int EXPERIENCE = 2;
const int SOUL_FOOD = 3;
const int SCORE = 4;
const int CPP = 0;
const int BACKEND = 0;
const int JUNIOR = 0;
const int CHICKEN = 0;
const int JAVA = 1;
const int FRONTEND = 1;
const int SENIOR = 1;
const int PIZZA = 1;
const int PYTHON = 2;

string getSubstring(const string& str, int& idx) {
    int nextIdx = str.find(' ', idx);
    const string &res = str.substr(idx, nextIdx - idx);
    idx = nextIdx + 1;
    return res == "and" ? getSubstring(str, idx) : res;
}

int getIndex(const string& str) {
    if (str == "cpp" || str == "backend" || str == "junior" || str == "chicken") {
        return 0;
    } else if (str == "java" || str == "frontend" || str == "senior" || str == "pizza") {
        return 1;
    } else if (str == "python") {
        return 2;
    } else {
        return 3;
    }
}

int count(vector<int> scores[3][2][2][2], string language, string role, string experience, string soulFood, int score, int depth) {
    int res = 0;

    switch (depth) {
        case LANGUAGE:
            switch (getIndex(language)) {
                case CPP:
                case JAVA:
                case PYTHON:
                    res = count(scores, language, role, experience, soulFood, score, ROLE);
                    break;
                default:
                    res += count(scores, "cpp", role, experience, soulFood, score, ROLE);
                    res += count(scores, "java", role, experience, soulFood, score, ROLE);
                    res += count(scores, "python", role, experience, soulFood, score, ROLE);
                    break;
            }
            break;
        case ROLE:
            switch (getIndex(role)) {
                case BACKEND:
                case FRONTEND:
                    res = count(scores, language, role, experience, soulFood, score, EXPERIENCE);
                    break;
                default:
                    res += count(scores, language, "backend", experience, soulFood, score, EXPERIENCE);
                    res += count(scores, language, "frontend", experience, soulFood, score, EXPERIENCE);
                    break;
            }
            break;
        case EXPERIENCE:
            switch (getIndex(experience)) {
                case JUNIOR:
                case SENIOR:
                    res = count(scores, language, role, experience, soulFood, score, SOUL_FOOD);
                    break;
                default:
                    res += count(scores, language, role, "junior", soulFood, score, SOUL_FOOD);
                    res += count(scores, language, role, "senior", soulFood, score, SOUL_FOOD);
                    break;
            }
            break;
        case SOUL_FOOD:
            switch (getIndex(soulFood)) {
                case CHICKEN:
                case PIZZA:
                    res = count(scores, language, role, experience, soulFood, score, SCORE);
                    break;
                default:
                    res += count(scores, language, role, experience, "chicken", score, SCORE);
                    res += count(scores, language, role, experience, "pizza", score, SCORE);
                    break;
            }
            break;
        default:
            const vector<int>& list = scores[getIndex(language)][getIndex(role)][getIndex(experience)][getIndex(soulFood)];
            res += list.end() - lower_bound(list.begin(), list.end(), score);
            break;
    }

    return res;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size());

    const int& n = info.size();
    vector<int> scores[3][2][2][2];

    for (int i = 0; i < info.size(); i++) { // 50,000
        const string& item = info[i];
        int idx = 0;

        string language = getSubstring(item, idx);
        string role = getSubstring(item, idx);
        string experience = getSubstring(item, idx);
        string soulFood = getSubstring(item, idx);
        int score = stoi(getSubstring(item, idx));

        scores[getIndex(language)][getIndex(role)][getIndex(experience)][getIndex(soulFood)].push_back(score);
    }

    for (auto & score : scores) {
        for (auto & j : score) {
            for (auto & k : j) {
                for (auto & l : k) {
                    sort(l.begin(), l.end());
                }
            }
        }
    }

    for (int i = 0; i < query.size(); i++) { // 100,000
        const string& item = query[i];
        int idx = 0;

        string language = getSubstring(item, idx);
        string role = getSubstring(item, idx);
        string experience = getSubstring(item, idx);
        string soulFood = getSubstring(item, idx);
        int score = stoi(getSubstring(item, idx));
        answer[i] = count(scores, language, role, experience, soulFood, score, LANGUAGE);
    }

    return answer;
}
