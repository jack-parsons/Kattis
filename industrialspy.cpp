
// https://open.kattis.com/problems/industrialspy
// Not working currently

#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int canConstruct(unordered_map<char, int>& nCount, unordered_map<char, int>& count) {
    int r = 1;
    for (auto &c : nCount) {
        if (nCount[c.first] != count[c.first]) {
            return 0;
        } else if (nCount[c.first] > 1) {
            r *= nCount[c.first];
        }
    }
    return r;
}

int main() {
    int R;
    cin >> R;
    
    int upper = 10000000;
    //Sieve
    bool* isPrime = new bool[upper];
    for (int i = 0; i < upper; i ++) {
        isPrime[i] = true;
    }
    for (int i = 2; i < upper; i++) {
        if (!isPrime[i]) continue;
        for (int x = i*2; x <= upper; x += i) {
            isPrime[x] = false;
        }
    }
    vector<int> primes;
    vector<unordered_map<char, int>> primeCount(upper);
    // primes.push_back(2);
    for (int i = 3; i < upper; i+=2) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (char c : to_string(i)) {
                primeCount[i][c]++;
            }
        }
    }
    
    for (int j = 0; j < R; j ++){
        int N;
        cin >> N;
    
        upper = pow(10, to_string(N).size());

        unordered_map<char, int> nCount;
        for (char c : to_string(N)) {
            nCount[c]++;
        }
    
        int count = 0;
        if (canConstruct(primeCount[2], nCount)) {
            count += canConstruct(primeCount[2], nCount);
        }
        for (int i : primes) {
            if (isPrime[i]) {
                int k = canConstruct(primeCount[i], nCount);
                if (k)
                    count += k;
            }
        }
        cout << count << endl;
    }

    return 0;
}