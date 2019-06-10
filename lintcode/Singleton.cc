<<<<<<< HEAD
// Version 4
=======
// Version3 - best
>>>>>>> cfe3afa1b929804c8800262a07f35ba08aa3136c
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
<<<<<<< HEAD
    static shared_ptr<Solution> getInstance() {
        // write your code here
        static shared_ptr<Solution> instance(new Solution());
        return instance;
    }
    
    Solution(const Solution &) = delete;
    Solution & operator=(const Solution &) = delete;
    ~Solution() {}
    
private:
    Solution() {}
};

// Version 3
class Singleton {
private:
    Singleton() {}                        // 构造函数是私有的
    // ~Singleton() {}                    // 在这里不可以声明为private。因为我们在函数GetInstance声明定义了位于栈上的变量，
                                         // 这样程序结束时会自动调用析构函数（为private则调用不了，编译不通过）.

public:
  ~Singleton() {}
    static Singleton* GetInstance() {
        static Singleton instance;       // 局部静态变量，自动析构
        return &instance;
    }
};

// Version2 - best
=======
    static Solution* getInstance() {
        // write your code here
      // C++11 thread-safe local-static-initialization
        static Solution instance;
        return &instance;
    }
    
  // C++11 noncopyable
    Solution(const Solution &) = delete;
    Solution & operator=(const Solution &) = delete;
    
private:
    Solution() {}
    ~Solution() {}
};

// Version2
>>>>>>> cfe3afa1b929804c8800262a07f35ba08aa3136c
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
      // C++11 thread-safe local-static-initialization
      // C++0X以后，要求编译器保证内部静态变量的线程安全性，可以不加锁。但C++ 0X以前，仍需要加锁
        static Solution *instance = new Solution();
        return instance;
    }
    
  // C++11 noncopyable
    Solution(const Solution &) = delete;
    Solution & operator=(const Solution &) = delete;
    
private:
    Solution() {}
    ~Solution() {}
};

// Version1
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
      // C++11 thread-safe local-static-initialization
        static Solution *instance = new Solution();
        return instance;
    }
        
private:
    Solution() {}
    ~Solution() {}
  // C++03 noncopyable by making copy constructor and copy assignment private without definition
    Solution(const Solution &);
    Solution & operator=(const Solution &);
};
