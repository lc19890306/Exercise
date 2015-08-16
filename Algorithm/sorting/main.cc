#include "main.hh"

int
main(int argc, char **argv) {
  switch (argc) {
  case 1: {
    int n(10000);
    rand_num_generator generator;
    generator.generate(n, 10000);
  }
    break;
  case 2: {
    std::vector<int> data;
    int num;

    std::ifstream infile(argv[1]);
    if (infile) {
      while (infile >> num)
	data.push_back(num);
    }

    // SortFunc sort(selection_sort);
    // SortFunc sort(bubble_sort);
    // SortFunc sort(insertion_sort);
    // SortFunc sort(cocktail_sort);
    // SortFunc sort(minmax_sort);
    SortFunc sort(rank_sort);
    // SortFunc sort(shell_sort);
    sort(data.begin(), data.end());

    std::cout << Algo::is_sorted(data.begin(), data.end()) << std::endl;

    std::ofstream outfile("out.txt");
    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(outfile, " "));
  }
    break;
  default:
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
