// https://open.kattis.com/problems/showroom

#include <stdio.h>
#include <iostream>
#include <string>
#include <bitset>
#include <math.h>
#include <vector>
#include <limits>
#include <queue>
#include <functional>
using namespace std;

void printMatrix(vector<vector<char> > &vals, int N, int Ntwo){

    for(int i = 0; i < N; i++) {
        for(int j =0; j< Ntwo; j++) {
                cout << vals[i][j]<<" ";
        }
        cout << endl;
    }
}

struct path {
    float cost;
    vector<pair<int, int>> nodes;
};

bool compare(path i, path j) {
    return i.cost < j.cost;
}

bool inBounds(int x, int y, int minX, int maxX, int minY, int maxY) {
    return !(minX <= x && x < maxX && minY <= y && y < maxY);
}

int astar(vector<vector<char>>& matrix, int w, int h, int sx, int sy, int ex, int ey) {
    priority_queue<path, vector<path>, function<bool(path,path)>> paths (compare);
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    paths.push({0, {{sx, sy}}}); // Put start on queue
    while (!paths.empty()) {
        path cur = paths.top();
        paths.pop();
        for (pair<int, int> dir : dirs) {
            int nx = cur.nodes[cur.nodes.size()].first+dir.first;
            int ny = cur.nodes[cur.nodes.size()].second+dir.second;
            if (inBounds(nx, ny, 0, w, 0, h) && matrix[ny][nx] == c) {
                
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    int Ntwo;
    cin >> Ntwo;
    vector<vector<char>> matrix (N,vector<char>(Ntwo,-1)); //Matrix that contains map
    for(int i = 0; i < N; i++) {
        for(int j =0; j< Ntwo; j++) {
            char v;
            cin >> v;
            matrix[i][j] = v;
        }
    }
    int sI, sJ;
    cin >> sI >> sJ;
    pair<int, int> start = {sI-1,sJ-1}; //The INDEX of the starting position

    printMatrix(matrix, N,Ntwo);

    return 0;
}