#ifndef RAND_NUM_GENERATOR
#define RAND_NUM_GENERATOR

#include <fstream>
#include <ctime>
#include <cstdlib>
#include <unordered_set>

class rand_num_generator {
public:
  rand_num_generator(const std::string &filename = "data.dat") noexcept {
    outfile.open(filename// | std::ios::binary
		 );
    if (outfile)
      srand(time(NULL));
    else
      exit(1);
  }

  virtual ~rand_num_generator() noexcept {
    outfile.close();
  }

  void generate(const int &n = 10, const int &modulo = 100);

private:
  std::ofstream outfile;
};

#endif	// RAND_NUM_GENERATOR
