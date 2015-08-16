#ifndef POSTFIXTOINFIX_HH
#define POSTFIXTOINFIX_HH

#include <iostream>
#include <stack>
#include <string>
using namespace std;

void PostfixToInfix(const string &str) {
  stack<unsigned char> I,
    M,
    R;
  for (auto &&c : str)
    I.push(c);
  while (!I.empty() || !M.empty()) {
    char c;
    if (!I.empty()) {
      c = I.top();
      I.pop();
    }
    else if (!M.empty()) {
      c = M.top();
      M.pop();
    }
    switch (c) {
    case ' ':
      break;
    case '@': {
      R.push('(');
      M.pop();
    }
      break;
    case '+':
    case '-':
    case '*':
    case '/': {
      M.push('@');
      M.push(c);
      R.push(')');
    }
      break;
    default: {
      R.push(c);
      if (M.top() != '@') {
	R.push(M.top());
	M.pop();
      }
      else {
	while (!M.empty() && M.top() == '@') {
	  R.push('(');
	  M.pop();
	}
	if (!M.empty()) {
	  R.push(M.top());
	  M.pop();
	}
      }
    }
      break;
    }
  }
	
  while (!R.empty()) {
    cout << R.top();
    R.pop();
  }
  cout << endl;
}

#endif	// POSTFIXTOINFIX_HH
