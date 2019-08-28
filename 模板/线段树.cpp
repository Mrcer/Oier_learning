#include <iostream>
#define ls (ls)
#define rs (rs)
#define mid ((l+r)>>1)
using namespace std;
const int MAX = 100010;
int a[MAX];
strcut Node {
	long long sum, flag;
}tree[4*MAX];

inline void push_up(int root) {
	tree[root].sum = tree[ls].sum + tree[rs].sum;
}

void build(int root, int l, int r) {
	if(l==r) {
		tree[root].sum = a[l];
	} else {
		build(ls, l, mid);
		build(rs, mid+1, r);
		push_up(root);
	}
}

void push_down(int root, int l, int r) {
	tree[ls].sum += tree[root].flag * (mid-l+1);
	tree[rs].sum += tree[root].flag * (r-mid);
	tree[ls].flag += tree[root].flag;
	tree[rs].flag += tree[root].flag;
	tree[root].flag = 0;
}

void update(int root, int l, int r, int L, int R, int C) {
	if(L<=l && r<=R) {
		tree[root].sum += C * (r-l+1);
		tree[root].flag += C;
	}
	if(tree.flag != 0) push_down(root, l, r);
	if(L<=mid) update(ls, l, mid, L, R, C);
	if(mid<R)
}

void query(int root, int l, int r, int L, int R) {
	
}

