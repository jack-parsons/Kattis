
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c== 'e' || c == 'i' || c == 'o' || c== 'u' || c == 'y';
}

int main() {
    int N;
    cin>>N;
    while (N != 0) {
        vector<string> s(N);
        for (int w = 0; w < N; w++) {
            cin >> s[w];
        }

        int m = 0;
        int mb = 0;
        for (int w = 0; w < N; w++) {
            int c = 0;
            for (int i = 0; i < s[w].size()-1; i++) {
                if (s[w][i] == s[w][i+1] && isVowel(s[w][i])) {
                    c++;
                }
            }
            if (c > m) {
                m = c;
                mb = w;
            }
        }
        cout << s[mb] << endl;

        cin>>N;
    }
}