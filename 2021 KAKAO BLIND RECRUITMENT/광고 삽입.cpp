#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int convert(const string &time) {
    int hour = stoi(time.substr(0, 2)) * 3600;
    int minute = stoi(time.substr(3, 2)) * 60;
    int second = stoi(time.substr(6, 2));
    return hour + minute + second;
}

string convert(int time) {
    string sec = to_string(time % 60);
    if (stoi(sec) < 10) {
        sec = '0' + sec;
    }
    time /= 60;
    string min = to_string(time % 60);
    if (stoi(min) < 10) {
        min = '0' + min;
    }
    time /= 60;
    string hour = to_string(time);
    if (stoi(hour) < 10) {
        hour = '0' + hour;
    }

    return hour + ":" + min + ":" + sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int playTime = convert(play_time);
    int advTime = convert(adv_time);
    vector<int> seconds(playTime);
    for (const auto &log: logs) {
        int start = convert(log.substr(0, 8));
        int end = convert(log.substr(9));
        for (int i = start; i < end; i++) {
            seconds[i]++;
        }
    }

    long long curTime = 0;
    long long maxTime = 0;
    string startTime = "00:00:00";
    queue<int> q;

    for (int i = 0; i < advTime; i++) {
        int &second = seconds[i];
        q.push(second);
        curTime += second;
    }

    maxTime = curTime;
    for (int i = advTime; i < playTime; i++) {
        curTime -= q.front();
        q.pop();
        int &second = seconds[i];
        curTime += second;
        q.push(second);
        if (maxTime < curTime) {
            maxTime = curTime;
            startTime = convert(i - advTime + 1);
        }
    }
    answer = startTime;

    return answer;
}
