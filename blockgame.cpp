
//https://open.kattis.com/problems/blockgame2

#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>   
using namespace std;

typedef unsigned long long ll;

bool helper(ll N, ll M) {
    ll smaller = min(N, M);
    ll bigger = max(N, M);
    if (bigger >= 2*smaller || bigger % smaller == 0) {
        return true;
    }
    return !helper(smaller, bigger%smaller);
}

int main() {
    ll N, M;
    cin >> N >> M;

    if (helper(N, M))
        cout << "win";
    else
        cout << "lose";

    return 0;
}
