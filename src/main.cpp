#include "Triple.hpp"
#include <fstream>
#include <iostream>

int main(int argc, const char *argv[]) {
	if (argc  < 2) {
		std::cout << "must specify a file path" << std::endl;
		return 0;
	}
	std::ifstream ifile(argv[1]);
	TripleList tl;
	int num_leaves = read_triples(ifile, tl);
	/* for (auto t : tl) { */
	/* 	std::cout << t << std::endl; */
	/* } */
	bool is_const = is_consistent(num_leaves, tl);
	if (is_const) {
		std::cout << "triple set IS consistent\n";
	} else {
		std::cout << "triple set is NOT consistent\n";
	}

	return 0;
}
