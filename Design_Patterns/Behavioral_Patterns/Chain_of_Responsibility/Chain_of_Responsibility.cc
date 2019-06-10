// The approach of the five-year-old
#include <iostream>
#include <vector>

using namespace std;

typedef enum {NO, YES} Answer;

class GimmeStrategy {
public:
  virtual ~GimmeStrategy() {}
  virtual Answer canIHave() = 0;
};

class AskMom : public GimmeStrategy {
public:
  Answer canIHave() {
    cout << "Mooom? Can I have this?" << endl;
    return NO;
  }
};

class AskDad : public GimmeStrategy {
public:
  Answer canIHave() {
    cout << "Dad, I really need this!" << endl;
    return NO;
  }
};

class AskGrandpa : public GimmeStrategy {
public:
  Answer canIHave() {
    cout << "Grandpa, is it my birthday yet?" << endl;
    return NO;
  }
};

class AskGrandma : public GimmeStrategy {
public:
  Answer canIHave() {
    cout << "Grandma, I really love you!" << endl;
    return YES;
  }
};

class Gimme : public GimmeStrategy {
public:
  Gimme() {
    chain.push_back(new AskMom);
    chain.push_back(new AskDad);
    chain.push_back(new AskGrandpa);
    chain.push_back(new AskGrandma);
  }

  ~Gimme() {
    // purge chain
  }

  Answer canIHave() {
    for (auto it(chain.begin()); it != chain.end(); ++it)
      if ((*it)->canIHave() == YES)
	return YES;
    // Reached end without success...
    cout << "Whiiiiinnne!" << endl;
    return NO;
  }

private:
  vector<GimmeStrategy *> chain;
};

int main() {
  Gimme chain;
  chain.canIHave();

  return EXIT_SUCCESS;
}
