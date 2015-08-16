#include "String.hh"

void foo(String x) {}
void bar(const String& x) {}
String baz()
{
  String ret("world");
  return ret; }
int main() {
  String s0;
  auto len(s0.size());
  String s1("hello");
  String s2 = "hello";
  String s3(s0);
  String s4 = s1;
  s3 = s1;
  s3 = s3;
  s1 = "aewsome";
  foo(s1);
  foo("temporary");
  bar(s1);
  bar("temporary");
  String s5 = baz();
  s5 = baz();
  std::vector<String> svec;
  svec.push_back(s0);
  svec.push_back(s1);
  svec.push_back("good job");
  
  return 0;
}
