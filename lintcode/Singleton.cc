// Version2 - best
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
