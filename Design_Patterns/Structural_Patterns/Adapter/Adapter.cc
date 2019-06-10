#include <iostream>

using namespace std;

class Muslim {			// Abstract Target
public:
  virtual ~Muslim() = default;
  virtual void performsMuslimRitual() = 0;
};

class MuslimFemale : public Muslim { // Concrete Target
public:
  virtual void performsMuslimRitual() override {
    cout << "Muslim girl performs Muslim ritual." << endl;
  }
};

class Hindu {			// Abstract Adaptee
public:
  virtual ~Hindu() = default;
  virtual void performsHinduRitual() = 0;
};

class HinduFemale : public Hindu { // Concrete Adaptee
public:
  virtual void performsHinduRitual() override {
    cout << "Hindu girl performs Hindu ritual." << endl;
  }
};

class MuslimRitual {
public:
  void carryOutRitual(Muslim *muslim) {
    cout << "On with the Muslim rituals!" << endl;
    muslim->performsMuslimRitual();
  }
};

class MuslimAdapter : public Muslim { // Adapter
public:
  MuslimAdapter(Hindu *h) : hindu(h) {}
  virtual void performsMuslimRitual() override {
    hindu->performsHinduRitual();
  }

private:
  Hindu *hindu;
};

int main() {
  HinduFemale *hinduGirl = new HinduFemale;
  MuslimFemale *muslimGirl = new MuslimFemale;
  MuslimRitual muslimRitual;

  MuslimAdapter *adaptedHindu = new MuslimAdapter(hinduGirl);

  muslimRitual.carryOutRitual(muslimGirl);
  // muslimRitual.carryOutRitual(hinduGirl); // Will not compile of course since the parameter must be of type Muslim *.
  muslimRitual.carryOutRitual(adaptedHindu);

  delete adaptedHindu;

  return EXIT_SUCCESS;
}
