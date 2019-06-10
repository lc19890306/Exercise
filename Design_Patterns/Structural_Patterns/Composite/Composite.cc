#include <vector>
#include <iostream>		// cout
#include <memory>		// shared_ptr
#include <algorithm>		// for_each

using namespace std;

class Graphic {
public:
  virtual ~Graphic() {}
  virtual void print() const = 0;
};

class Ellipse : public Graphic {
public:
  void print() const {
    cout << "Ellipse \n";
  }
};

class CompositeGraphic : public Graphic {
public:
  void print() const {
    // for each element in graphicList_, call the print member function
    for_each(graphicList_.begin(), graphicList_.end(), [](Graphic *g){g->print();});
  }

  void add(Graphic *g) {
    graphicList_.push_back(g);
  }

private:
  vector<Graphic *> graphicList_;
};

int main() {
  // Initialize four ellipses
  const shared_ptr<Ellipse> ellipse1(new Ellipse);
  const shared_ptr<Ellipse> ellipse2(new Ellipse);
  const shared_ptr<Ellipse> ellipse3(new Ellipse);
  const shared_ptr<Ellipse> ellipse4(new Ellipse);

  // Initialize three composite graphics
  const shared_ptr<CompositeGraphic> graphic(new CompositeGraphic);
  const shared_ptr<CompositeGraphic> graphic1(new CompositeGraphic);
  const shared_ptr<CompositeGraphic> graphic2(new CompositeGraphic);

  // Composes the graphics
  graphic1->add(ellipse1.get());
  graphic1->add(ellipse2.get());
  graphic1->add(ellipse3.get());

  graphic2->add(ellipse4.get());

  graphic->add(graphic1.get());
  graphic->add(graphic2.get());

  // Prints the complete graphic (four times the string "Ellipse")
  graphic->print();

  return EXIT_SUCCESS;
}
