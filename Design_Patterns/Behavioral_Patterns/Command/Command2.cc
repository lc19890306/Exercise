#include <iostream>
#include <vector>

using namespace std;

class Command {
public:
  virtual void execute() = 0;
};

class Hello : public Command {
public:
  void execute() {
    cout << "Hello ";
  }
};

class World : public Command {
public:
  void execute() {
    cout << "World! ";
  }
};

class IAm : public Command {
public:
  void execute() {
    cout << "I'm the command pattern!";
  }
};

// An object that holds commands:
class Macro {
public:
  void add(Command *c) {
    commands.push_back(c);
  }

  void run() {
    for (auto it(commands.begin()); it != commands.end(); ++it)
      (*it)->execute();
  }

private:
  vector<Command *> commands;
};

int main() {
  Macro macro;
  macro.add(new Hello);
  macro.add(new World);
  macro.add(new IAm);
  macro.run();

  return EXIT_SUCCESS;
}
