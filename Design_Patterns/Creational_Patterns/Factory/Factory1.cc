#include <string>
#include <cstdlib>

using namespace std;

class Computer {
public:
  virtual ~Computer() {}	// without this, you do not call Laptop or Desktop destructor in this example
  virtual void Run() = 0;
  virtual void Stop() = 0;
};

class Laptop : public Computer {
public:
  virtual ~Laptop() {}
  virtual void Run() {
    mHibernating = false;
  }

  virtual void Stop() {
    mHibernating = true;
  }

private:
  bool mHibernating;
};

class Desktop : public Computer {
public:
  virtual ~Desktop() {}
  virtual void Run() {
    mOn = true;
  }

  virtual void Stop() {
    mOn = false;
  }

private:
  bool mOn;
};

class ComputerFactory {
public:
  static Computer *NewComputer(const string &description) {
    if (description == "laptop")
      return new Laptop;
    if (description == "desktop")
      return new Desktop;
    return nullptr;
  }
};

int main() {
  ComputerFactory computerFactory;
  Computer *computer = computerFactory.NewComputer("laptop");

  return EXIT_SUCCESS;
}
