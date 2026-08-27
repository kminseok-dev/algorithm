#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 0));  // 지역 변수로 매 호출마다 새로 생성
    queue<pair<int, int>> q;                          // 지역 변수, vector 대신 pair로 오버헤드도 줄임

    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) return dist[x][y];  // 큐가 빈 뒤가 아니라 여기서 return해도
                                                             // dist, q가 지역 변수라 다음 호출에 영향 없음

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny]) continue;
            if (maps[nx][ny]) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}