// #include <iostream>

// using namespace std;

// class Singleton {
// public:
//   static Singleton * getInstance() {
//     static Singleton *instance = new Singleton(1);
//     return instance;
//   }

//   Singleton(const Singleton &) = delete;
//   Singleton & operator=(const Singleton &) = delete;

//   int x;

// private:
//   Singleton(int x) : x(x) {}
//   ~Singleton() {}
// };

// int main() {
//   Singleton *instance = Singleton::getInstance();
//   cout << instance->x << endl;
//   return EXIT_SUCCESS; 
// }


// #include <iostream>

// using namespace std;

// class Singleton {
// public:
//   static Singleton & getInstance() {
//     static Singleton *instance = new Singleton(1);
//     return *instance;
//   }

//   Singleton(const Singleton &) = delete;
//   Singleton & operator=(const Singleton &) = delete;

//   int x;

// private:
//   Singleton(int x) : x(x) {}
//   ~Singleton() {}
// };

// int main() {
//   cout << Singleton::getInstance().x << endl;
//   return EXIT_SUCCESS; 
// }


// #include <iostream>

// using namespace std;

// class Singleton {
// public:
//   static Singleton * getInstance() {
//     static Singleton instance(1);
//     return &instance;
//   }

//   Singleton(const Singleton &) = delete;
//   Singleton & operator=(const Singleton &) = delete;

//   int x;

// private:
//   Singleton(int x) : x(x) {}
//   ~Singleton() {}
// };

// int main() {
//   Singleton *instance = Singleton::getInstance();
//   cout << instance->x << endl;
//   return EXIT_SUCCESS; 
// }

#include <iostream>

using namespace std;

class Singleton {
public:
  static Singleton & getInstance() {
    static Singleton instance(0);
    return instance;
  }

  int getValue() {
    return i;
  }

  void setValue(int x) {
    i = x;
  }

  Singleton(const Singleton &other) = delete;
  Singleton & operator=(const Singleton &other) = delete;

private:
  Singleton(int x) : i(x) {}
  int i;
};

int main() {
  Singleton &instance = Singleton::getInstance();
  cout << instance.getValue() << endl;
  instance.setValue(1);
  cout << instance.getValue() << endl;

  return EXIT_SUCCESS;
}
