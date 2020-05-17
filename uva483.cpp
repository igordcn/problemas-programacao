#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void emptyStack(stack<char> &stk, string &result) {
  while(!stk.empty()) {
    result.push_back(stk.top());
    stk.pop();
  }
}

int main() {
  string linha, result;
  stack<char> stk;
  while (getline(cin, linha))
  {
    for(string::iterator it = linha.begin(); it != linha.end(); it++){
      if(*it != ' ') {
        stk.push(*it);
      } else {
        emptyStack(stk, result);
        result.push_back(' ');
      }
    }
    emptyStack(stk, result);
    printf("%s\n", result.c_str());
    result.erase();
  }
  
  return 0;
}