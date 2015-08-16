#ifndef INFIXTOPOSTFIX_HH
#define INFIXTOPOSTFIX_HH

#include <string>
#include <iostream>
#include <stack>

using std::string;
using std::stack;

void InfixToPostfix(const string &str) {
  string res;
  stack<unsigned char> operators;

  for (auto &&c : str) {
    switch (c) {
    case ' ':
      break;
    case '+':
    case '-':
    case '*':
    case '/': {
      // if stack is empty or
      // stack's top is ( or
      // c's priority is greater than that of stack's top
      // just push c into the stack
      // otherwise pop and add stack's top into the result
      // then push c into the stack
      if (operators.empty()
	  || (operators.top() == '(')
	  || (((c == '*') || (c == '/'))
	      && ((operators.top() == '+') || (operators.top() == '-'))))
	operators.push(c);
      else {
	res += operators.top();
	operators.pop();
	operators.push(c);
      }
    }
      break;
    case '(':
      operators.push(c);
      break;
    case ')': {
      while (operators.top() != '(') {
	res += operators.top();
	operators.pop();
      }
      operators.pop();
    }
      break;
    default: {
      res += c;
    }
      break;
    }
  }

  while (!operators.empty()) {
    res += operators.top();
    operators.pop();
  }

  std::cout << res << std::endl;
  // for (auto &&c : res)
  //   std::cout << c << std::endl;
  // std::endl;
}

#endif	// INFIXTOPOSTFIX_HH
