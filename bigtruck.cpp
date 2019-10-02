#include <vector>
#include <iostream>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> G[n];
    vector<int> numItems (n);
    for (int i=0; i<n; i++) {
        cin >> numItems[i];
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a-1].push_back({b-1, w});
        G[b-1].push_back({a-1, w});
    }


    vector<int> distance(n);
    vector<int> items(n);
    vector<int> processed(n);
    std::priority_queue<pair<int, int>> q;
    int x = 0;

    for (int i = 0; i < n; i++) distance[i] = INF;
    distance[x] = 0;
    items[x] = numItems[x];
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : G[a]) {
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                items[b] = items[a]+numItems[b];
                q.push({-distance[b],b});
            } else if (distance[a]+w == distance[b] && items[a]+numItems[b] > items[b]) {
                distance[b] = distance[a]+w;
                items[b] = items[a]+numItems[b];
                q.push({-distance[b],b});
            }
        }
    }
    
    if (distance[n-1] == INF) {
        cout << "impossible";
    } else {
        cout << distance[n-1] << " " << items[n-1];
    }
    return 0;
}