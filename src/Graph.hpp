#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/connected_components.hpp>
#include <vector>

struct VertexB { 
	VertexB() {}
	VertexB(size_t idx): idx(idx) {}
	size_t idx; 
};
using Graph = typename boost::adjacency_list < boost::vecS
	                                          , boost::vecS
															, boost::undirectedS
															, VertexB
															>;
using Vertex = typename boost::graph_traits<Graph>::vertex_descriptor;

std::pair<int, std::vector<int>> connected_components(const Graph& g) {
	std::vector<int> components(num_vertices(g));
	int num = boost::connected_components(g, &components[0]);
	return std::make_pair(num, std::move(components));
}
	
#endif /* ifndef G2S_GRAPH_HPP */
