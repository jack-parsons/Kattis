
//https://open.kattis.com/problems/backspace

#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

int main() {
  string s;
  cin >> s;

  stack<char> r;
  for (char x : s) {
    if (x == '<') {
        r.pop();
    } else {
        r.push(x);
    }
  }
  stack<char> r2;
  while (!r.empty()) {
      r2.push(r.top());
      r.pop();
  }
  while (!r2.empty()) {
      cout << r2.top();
      r2.pop();
  }
}