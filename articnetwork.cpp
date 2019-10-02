
#include <vector>
#include <iostream>
#include <queue>
#include <limits>
#include <set>
#include <math.h>
#include <algorithm>


using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int N;
    cin >> N;
    for (int _ = 0; _ < N; _ ++) {
        int S, P;
        cin >> S >> P;
        set<pair<int, int>> outposts; 
        set<pair<int, int>> outpostsInNetwork; 
        pair<int, int> lastNode;
        for (int i = 0; i < P; i ++) {
            int a, b;
            cin >> a >> b;
            outposts.insert({a, b});
            lastNode = {a, b};
        }
        outpostsInNetwork.insert(lastNode);
        outposts.erase(lastNode);

        // Prims
        vector<double> edgesSpanning(P-1);
        for (int i = 0; i < P-1; i ++) {
            double mn = INF;
            pair<int, int> emNode;
            for (pair<int, int> const &nodeS : outpostsInNetwork) {
                for (pair<int, int> const &nodeE : outposts) {
                    double dist = hypot(nodeE.first-nodeS.first, nodeE.second-nodeS.second);
                    if (dist != 0) {
                        if (dist < mn) {
                            mn = dist;
                            emNode = nodeE;
                        }
                    }
                }
            }
            edgesSpanning[i] = mn;
            outpostsInNetwork.insert(emNode);
            outposts.erase(emNode);
        }
        sort(edgesSpanning.begin(), edgesSpanning.end());
        printf("%.2f\n", edgesSpanning[P-S-1]);
    }
    return 0;
}