#include "Triple.hpp"
#include "Graph.hpp"
#include <vector>
#include <unordered_map>
#include <string>

void triple_graph(const std::vector<int>& leaves, const TripleList& tl,
		std::vector<Vertex>& n2v, Graph& g) {
	for (auto l : leaves) { n2v[l] = add_vertex(g); }
	for (const Triple& t : tl) { 
		int a,b,c;
		std::tie(a,b,c) = t;
		if (!edge(n2v[a], n2v[b], g).second) {
			add_edge(n2v[a], n2v[b], g); 
		}
	}
}

bool build_subtree(const std::vector<int>& leaves, const TripleList& tl,
		std::vector<Vertex>& n2v) {
	Graph tg;
	triple_graph(leaves, tl, n2v, tg);
	size_t ncomp; std::vector<int>  comp;
	std::tie(ncomp, comp) = connected_components(tg);
	if (ncomp == 1) { return false; }

	std::vector<std::vector<int>> leaf_components(ncomp);
	for (size_t i = 0; i < comp.size(); ++i) { leaf_components[comp[i]].push_back(leaves[i]); }

	std::vector<std::vector<Triple>> triple_components(ncomp); 
	for (const Triple& tr : tl) {
		int a,b,c;
		std::tie(a,b,c) = tr;
		int ca = comp[n2v[a]], cb = comp[n2v[b]], cc = comp[n2v[c]];
		if (ca == cb && cb == cc) { triple_components[ca].push_back(tr); }
	}
	for (size_t i = 0; i < leaf_components.size(); ++i) {
		const std::vector<int>& lc = leaf_components[i];
		if (lc.size() == 1) {
		} else {
			bool res;
			res = build_subtree(lc, triple_components[i], n2v);
			if (!res) { return false; }
		}
	}
	return true;
}

bool is_consistent(int num_leaves, const TripleList& triple_list) {
	std::vector<int> leaves;
	for (size_t v = 0; v < num_leaves; ++v) { leaves.push_back(v); }
	std::vector<Vertex> n2v(num_leaves);
	return build_subtree(leaves, triple_list, n2v);
}

int get_triple_id(const std::string& triple, std::unordered_map<std::string, int>& triple_map) {
	if (triple_map.find(triple) == triple_map.end()) {
		triple_map[triple] = triple_map.size();
	}
	return triple_map[triple];
}

int read_triples(std::istream& is, TripleList& triple_list) {
	std::unordered_map<std::string, int> triple_map;
	std::string A, B, C;
	while ((is >> A)) {
		is >> B; is >> C;
		int a = get_triple_id(A, triple_map);
		int b = get_triple_id(B, triple_map);
		int c = get_triple_id(C, triple_map);
		triple_list.push_back(std::make_tuple(a, b, c));
	}
	return triple_map.size();
}
