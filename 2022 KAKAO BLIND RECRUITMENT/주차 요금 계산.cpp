#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

int convert(const string &time) {
    int hour = stoi(time.substr(0, 2)) * 60;
    int minute = stoi(time.substr(3, 2));
    return hour + minute;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int basic_time = fees[0];
    int basic_pay = fees[1];
    int unit_time = fees[2];
    int unit_pay = fees[3];

    map<string, int> total_time;
    unordered_map<string, int> entrance;
    for (const auto &record: records) {
        int cur_time = convert(record.substr(0, 5));
        string car_num = record.substr(6, 4);
        string type = record.substr(11);

        if (type == "IN") {
            entrance[car_num] = cur_time;
        } else {
            total_time[car_num] += cur_time - entrance[car_num];
            entrance.erase(car_num);
        }
    }

    const int last_time = 1439;
    for (const auto &item: entrance) {
        int entrance_time = item.second;
        string car_num = item.first;
        total_time[car_num] += last_time - entrance_time;
    }

    for (const auto &item: total_time) {
        string car_num = item.first;
        int time = item.second;
        if (basic_time < time) {
            time -= basic_time;
            answer.push_back(basic_pay + (int) ceil((double) time / unit_time) * unit_pay);
        } else {
            answer.push_back(basic_pay);
        }
    }

    return answer;
}
