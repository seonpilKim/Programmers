# [거리두기 확인하기](https://programmers.co.kr/learn/courses/30/lessons/81302)
___
## 🤔접근
- P와 O는 가중치 1, X는 가중치 2인 그래프 형식으로 발상을 전환하여 접근하였다.
___
## 💡풀이
- <b>알고리즘 & 자료구조</b>
    - `BFS`
- <B>구현</B>
    - 먼저 P인 위치를 모두 찾고, 각 P마다 BFS을 수행하여 다른 P까지의 거리를 구한다.
        - 여기서 거리의 차가 2이하라면, 0을 반환한다.
        - 모든 거리의 차가 3이상이라면, 1을 반환한다.
___
## ✍ 피드백
___
## 💻 구현 코드
```c++
#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

const int INF = 1e9;
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

void BFS(const vector<string>& place, vector<int>& dist, const int& start) {
	dist[start] = 0;

	queue<pair<int, int>> q;
	q.emplace(0, start);

	while (!q.empty()) {
		int curCost = q.front().first;
		int cur = q.front().second;
		int row = cur / 5;
		int col = cur % 5;
		q.pop();

		if (dist[cur] < curCost)
			continue;

		for (int i = 0; i < 4; i++) {
			int next = (row + dr[i]) * 5 + col + dc[i];
			int nextRow = row + dr[i];
			int nextCol = col + dc[i];
			
			if (nextRow < 0 || nextCol < 0 || nextRow >= 5 || nextCol >= 5)
				continue;
			
			int cost = 1;
			if (place[nextRow][nextCol] == 'X')
				cost = 2;
				
			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				q.emplace(dist[next], next);
			}
		}
	}
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (auto place : places) {
		bool flag = true;
		for (int i = 0; i < 5; i++) {
			vector<int> pos;
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (place[j][k] == 'P') {
						pos.push_back(j * 5 + k);
					}
				}
			}

			for (int u : pos) {
				vector<int> dist(25, INF);
				BFS(place, dist, u);

				for (int v : pos) {
					if (u == v)
						continue;

					if (abs(dist[u] - dist[v]) <= 2) {
						flag = false;
						break;
					}
				}

				if (!flag)
					break;
			}

			if (!flag)
				break;
		}

		answer.push_back((flag ? 1 : 0));
	}

	return answer;
}
```