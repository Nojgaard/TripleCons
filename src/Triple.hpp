#ifndef TRIPLE_HPP
#define TRIPLE_HPP

#include <vector>
#include <iostream>
#include <tuple>

using Triple = std::tuple<int, int, int>;
using TripleList = std::vector<Triple>;

inline std::ostream& operator << (std::ostream& os, const Triple& tr) {
	int a, b, c;
	std::tie(a,b,c) = tr;
	os << a << " " << b << " " << c;
	return os;
}

template<typename T>
inline std::ostream& operator << (std::ostream& os, const std::vector<T>& vs) {
	for (const auto& v : vs) {
		os << v << ", ";
	}
	return os;
}

bool is_consistent(int num_leaves, const TripleList& triple_list);
int read_triples(std::istream& is, TripleList& triple_list);

#endif /* ifndef TRIPLE_HPP */
