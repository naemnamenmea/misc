#pragma once

#include <map>
#include <utility>
#include <vector>
#include <stack>

#include "test_runner.h"

using namespace std;

namespace graph_lib {
	enum class COLOR {
		WHITE,
		BLACK,
		GREY
	};

	using Row = vector<int>;
	using Matrix = vector<Row>;

	template<class Edges>
	Matrix make_adj_smtrx(const Edges& edges, int n) {
		Matrix res(n, Row(n));
		for (const auto& edge : edges) {
			res[edge.first][edge.second] = true;
			res[edge.second][edge.first] = true;
		}
		return res;
	}

	template<class Edges>
	Matrix make_adj_mtrx(const Edges& edges, int n) {
		Matrix res(n, Row(n));
		for (const auto& edge : edges) {
			res[edge.first][edge.second] = true;
		}
		return res;
	}

	template <class FuncBefore, class FuncAfter>
	void dfs(const Matrix& graph, vector<bool>& used, int node,
		FuncBefore func_before, FuncAfter func_after)
	{
		used[node] = true;
		func_before(node);

		for (size_t next = 0; next < graph[node].size(); ++next) {
			if (graph[node][next] && !used[next]) {
				dfs(graph, used, next, func_before, func_after);
			}
		}

		func_after(node);
	}

	vector<int> topological_sort(const Matrix& graph)
	{
		int n = graph.size();
		vector<int> res;
		res.reserve(n);
		vector<bool> used(n, false);
		vector<COLOR> color(n, COLOR::WHITE);

		auto func_before = [&color, &used](int cur_node) {
			used[cur_node] = false;

			if (color[cur_node] == COLOR::BLACK)
				return;

			if (color[cur_node] == COLOR::GREY) {
				throw runtime_error("cycle found");
			}

			color[cur_node] = COLOR::GREY;
		};

		auto func_after = [&color, &res, &used](int cur_node) {
			used[cur_node] = true;
			color[cur_node] = COLOR::BLACK;
			res.push_back(cur_node);
		};

		dfs(graph, used, 0, func_before, func_after);

		reverse(begin(res), end(res));

		return res;
	}

	const vector<pair<int, int>> undirected_cycled_graph_1 = {
		{0,5},
		{1,4},
		{2,3},
		{0,1},
		{3,0}
	};

	const vector<pair<int, int>> undirected_uncycled_graph_2 = {
		{0,1},
		{1,4},
		{0,5},
		{0,3},
		{3,2}
	};

	void test_topological_sort_uncycled()
	{
		auto input = make_adj_mtrx(undirected_uncycled_graph_2, 6);

		vector<int> expected{ 0,5,3,2,1,4 };
		auto actual = topological_sort(input);

		ASSERT_EQUAL(expected, actual);
	}

	void test_topological_sort_cycled()
	{
		auto input = make_adj_smtrx(undirected_cycled_graph_1, 6);

		topological_sort(input);
	}

	void RunTests() {
		TestRunner tr;
		RUN_TEST(tr, test_topological_sort_uncycled);
		RUN_TEST(tr, test_topological_sort_cycled);
	}
}