//https://open.kattis.com/problems/airconditioned

#include <iostream>
#include <vector>
#include <algorithm>
#include <istream>
#include <string>
#include <unordered_map>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;

const ll inf = 1e9+7;

struct minion {
    int upper, lower, covered;
};

bool comp(minion i, minion j) {
    return i.upper > j.upper;
}

int helper(int t, vector<minion>& minions, int minionIndex) {
    int minimumNeeded = inf;
    int newT = minions[minionIndex].lower;
    bool found = false;
    for (int i = minionIndex+1; i < minions.size(); i++) {
        minion m = minions[i];
        if (t>=m.lower && m.upper>=newT) {
            // minions[i].covered = true;
            found = true;
            minimumNeeded = min(minimumNeeded, helper(minions[i].upper, minions, i));
        }
    }
    if (found)
        return minimumNeeded+1;
    else {
        if (minionIndex > 0) {
            return helper(minions[minionIndex-1].upper, minions, minionIndex-1);
        } else {
            return 1;
        }
    }
        
}

int main(){
    int N;
    cin >> N;
    vector<minion> minions(N);
    for(int i = 0 ; i < N; i++){
        cin >> minions[i].lower >> minions[i].upper;
        minions[i].covered = false;
    }

    sort(minions.begin(), minions.end(), comp);

    cout << helper(minions[0].upper, minions, 0);
}