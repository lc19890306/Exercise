#include <stdexcept>
#include <iostream>

using namespace std;

class Pizza {
public:
  virtual ~Pizza() {}		// without this, no destructor for derived Pizza's will be called
  virtual int getPrice() const = 0;
};

class HamAndMushroomPizza : public Pizza {
public:
  virtual ~HamAndMushroomPizza() {}
  virtual int getPrice() const {
    return 850;
  }
};

class DeluxePizza : public Pizza {
public:
  virtual ~DeluxePizza() {}
  virtual int getPrice() const {
    return 1050;
  }
};

class HawaiianPizza : public Pizza {
public:
  virtual ~HawaiianPizza() {}
  virtual int getPrice() const {
    return 1150;
  }
};

class PizzaFactory {
public:
  typedef enum {
    HamMushroom,
    Deluxe,
    Hawaiian
  } PizzaType;

  static Pizza * createPizza(PizzaType pizzaType) {
    switch (pizzaType) {
    case HamMushroom: return new HamAndMushroomPizza;
    case Deluxe : return new DeluxePizza;
    case Hawaiian : return new HawaiianPizza;
    }
    throw "invalid pizza type.";
  }
};

void pizza_information(PizzaFactory::PizzaType pizzaType) {
  Pizza *pizza = PizzaFactory::createPizza(pizzaType);
  cout << "Price of " << pizzaType << " is " << pizza->getPrice() << endl;
  delete pizza;
}

int main() {
  pizza_information(PizzaFactory::HamMushroom);
  pizza_information(PizzaFactory::Deluxe);
  pizza_information(PizzaFactory::Hawaiian);

  return EXIT_SUCCESS;
}
