//https://open.kattis.com/problems/airconditioned

#include <iostream>
#include <vector>
#include <algorithm>
#include <istream>
#include <sstream>
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

bool check(int temp, pair<int,int> range){
    //cout << "Lower: "<<range.first << " Upper: " << range.second << " Temp: " << temp << endl;
    if(temp >= range.first && temp < range.second){
        return true;
    }
    return false;

}

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> ranges(N);
    int maximum = 0;
    for(int i = 0 ; i < N; i++){
        int l;
        int u;
        cin >> l >> u;
        maximum = max(maximum, u);
        ranges[i] = {l,u};
    }