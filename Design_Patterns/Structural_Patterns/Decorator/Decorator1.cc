#include <string>
#include <iostream>

using namespace std;

class Car {			// Our Abstract base class
public:
  Car() : _str("Unknown Car") {}

  virtual ~Car() {
    cout << "~Car()" << endl;
  }

  virtual string getDescription() {
    return _str;
  }

  virtual double getCost() = 0;

protected:
  string _str;
};

class OptionsDecorator : public Car { // Decorator Base class
public:
  virtual string getDescription() = 0;

  virtual ~OptionsDecorator() {
    cout << "~OptionsDecorator()" << endl;
  }
};

class CarModel1 : public Car {
public:
  // CarModel1() : _str("CarModel1") {} // Compilation error: class CarModel1 does not have any field named _str
  CarModel1() {
    _str = "CarModel1";
  }

  ~CarModel1() {
    cout << "~CarModel()" << endl;
  }

  virtual double getCost() {
    return 31000.23;
  }
};

class Navigation : public OptionsDecorator {
public:
  Navigation(Car *b) : _b(b) {}

  ~Navigation() {
    cout << "~Navigation()" << endl;
  }

  string getDescription() {
    return _b->getDescription() + ", Navigation";
  }

  double getCost() {
    return 300.56 + _b->getCost();
  }

private:
  Car *_b;
};

class PremiumSoundSystem : public OptionsDecorator {
public:
  PremiumSoundSystem(Car *b) : _b(b) {}

  ~PremiumSoundSystem() {
    cout << "~PremiumSoundSystem()" << endl;
  }

  string getDescription() {
    return _b->getDescription() + ", PremiumSoundSystem";
  }

  double getCost() {
    return 0.30 + _b->getCost();
  }

private:
  Car *_b;
};

class ManualTransmission : public OptionsDecorator {
public:
  ManualTransmission(Car *b) : _b(b) {}

  ~ManualTransmission() {
    cout << "~ManualTransmission()" << endl;
  }

  string getDescription() {
    return _b->getDescription() + ", ManualTransmission";
  }

  double getCost() {
    return 0.30 + _b->getCost();
  }

private:
  Car *_b;
};

int main() {
  // Create our Car that we want to buy
  Car *b = new CarModel1;

  cout << "Base model of " << b->getDescription() << " costs $" << b->getCost() << endl;

  // Who wants base model lets add some more features
  b = new Navigation(b);
  cout << b->getDescription() << " will cost you $" << b->getCost() << endl;
  b = new PremiumSoundSystem(b);
  b = new ManualTransmission(b);
  cout << b->getDescription() << " will cost you $" << b->getCost() << endl;

  // WARNING! Here we leak the CarModel1, Navigation and PremiumSoundSystem objects! either we delete them explicitly or rewrite the Decorators to take ownership and elete their Cars when destroyed.
  delete b;
}
