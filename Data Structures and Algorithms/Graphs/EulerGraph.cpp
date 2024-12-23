// find Euler path/cycle in a graph
// time complexity: O(n) space: O(n)
// ... I'm not sure whether it works? :)

// undirected graph:
vector<unordered_multiset<int>> G(n);

auto eulerGraph = [&]() {
	int cnt = 0;
	for (int u = 0; u < n; u++)
		if (G[u].size() % 2 == 1)
			cnt++;
	
	if (cnt == 0) return "The graph has an Euler Cycle";
	if (cnt == 2) return "The graph has an Euler Path";
	else return "This is not an Euler Graph";
};

stack<int> R; // I think it doesn't work, you shouldn't "burn the bridges" :(
function<void(int)> eDFS = [&](int u) {
	while (G[u].size()) {
		auto v = *G[u].begin();
		G[u].erase(G[u].begin());
		G[v].erase(G[v].find(u));
		eDFS(v);
	}
	R.push(u);
};
DFS(src); // src - one of the odd vertices for path or any vertex for cycle


// directed graph:
vector<vector<int>> G(n);

auto eulerGraph = [&]() {
	vector<int> diff(n);
	for (int u = 0; u < n; u++) {
		diff[u] -= G[u].size();
		for (auto& v : G[u]) 
			diff[v]++;
	}

	int a = -1, b = -1;
	for (int u = 0; u < n; u++) {
		if (diff[u] == -1 && a != -1) a = u;
		else if (diff[u] == 1 && b != -1) b = u;
		else if (diff[u] != 0) return "This is not an Euler Graph";
	}

	if (a == -1 && b == -1) return "The graph has an Euler Cycle";
	if (a != -1 && b != -1) return "The graph has an Euler Path";
	return "This is not an Euler Graph";
};

stack<int> R;
function<void(int)> eDFS = [&](int u) {
	while (G[u].size()) {
		auto v = G[u].back();
		G[u].pop_back();
		eDFS(v);
	}
	R.push(u);
};
DFS(src); // src - one of the odd vertices for path or any vertex for cycle