struct DSU {
	vector<int> parent;
	vector<int> size;
 
	DSU(int range) {
		parent.resize(range);
		size.resize(range);
		for (int i = 0; i < range; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}
	int find(int node) {
		if (parent[node] == node) return node;
		return parent[node] = find(parent[node]);
	}
	bool join(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		// make a < b to join smaller set into larger set
		if (size[a] < size[b]) {
			int temp = a;
			a = b;
			b = temp;
		}
		parent[b] = a;
		size[a] += size[b];
		size[b] = size[a];
		return true;
	}
};
