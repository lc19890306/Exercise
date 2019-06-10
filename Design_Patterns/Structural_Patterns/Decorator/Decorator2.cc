#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Interface {
public:
  virtual ~Interface() {}
  virtual void write(string &) = 0;
};

class Core : public Interface {
public:
  ~Core() {
    cout << "Core destructor called." << endl;
  }

  virtual void write(string &text) override {} // Do nothing.
};

class Decorator : public Interface {
public:
  Decorator(unique_ptr<Interface> c) : interface(move(c)) {}

  virtual void write(string &text) override {
    interface->write(text);
  }

private:
  unique_ptr<Interface> interface;
};

class MessengerWithSalutation : public Decorator {
public:
  MessengerWithSalutation(unique_ptr<Interface> c, const string &str)
    : Decorator(move(c)), salutation(str) {}

  ~MessengerWithSalutation() {
    cout << "Messenger destructor called." << endl;
  }

  virtual void write(string &text) override {
    text = salutation + "\n\n" + text;
    Decorator::write(text);
  }

private:
  string salutation;
};

class MessengerWithValediction : public Decorator {
public:
  MessengerWithValediction(unique_ptr<Interface> c, const string &str)
    : Decorator(move(c)), valediction(str) {}

  ~MessengerWithValediction() {
    cout << "MessengerWithValediction destructor called." << endl;
  }

  virtual void write(string &text) override {
    Decorator::write(text);
    text += "\n\n" + valediction;
  }

private:
  string valediction;
};

int main() {
  string salutation("Greetings,"), valediction("Sincerely, Andy"),
    message1("This message is not decorated."),
    message2("This message is decorated with a salutation."),
    message3("This message is decorated with a valediction."),
    message4("This message is decorated with a salutation and a valediction.");

  unique_ptr<Interface> messenger1 = make_unique<Core>();
  unique_ptr<Interface> messenger2 = make_unique<MessengerWithSalutation>(make_unique<Core>(), salutation);
  unique_ptr<Interface> messenger3 = make_unique<MessengerWithValediction>(make_unique<Core>(), valediction);
  unique_ptr<Interface> messenger4 = make_unique<MessengerWithValediction>(make_unique<MessengerWithSalutation>(make_unique<Core>(), salutation), valediction);

  messenger1->write(message1);
  cout << message1 << endl;
  cout << endl << "---------------------" << endl << endl;
  messenger2->write(message2);
  cout << message2 << endl;
  cout << endl << "---------------------" << endl << endl;
  messenger3->write(message3);
  cout << message3 << endl;
  cout << endl << "---------------------" << endl << endl;
  messenger4->write(message4);
  cout << message4 << endl;
  cout << endl << "---------------------" << endl << endl;

  return EXIT_SUCCESS;
}
