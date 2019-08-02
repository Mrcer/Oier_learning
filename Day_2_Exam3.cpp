#include <iostream>
using namespace std;
const int MAX = 100010;
int a[3][MAX], basket[3][MAX], team[MAX], head, tail, num, N, ans;
bool del_flag[MAX];

struct Number {
	int i;
	int j;
	int next;
}numbers[MAX];

inline void push(int i) {
	team[++head]=i;
}

inline void push_num(int i, int j) {
	numbers[++num].i = i;
	numbers[num].j = j;
	numbers[num].next = basket[i][a[i][j]];
	basket[i][a[i][j]] = num;
}

inline int pop() {
	return team[++tail];
}

void init() {
	bool find;
	for(int i = 1;i <= N;++i) {
		find = false;
		for(int j = 0;j < 3;++j) {
			if(basket[j][i]==0)
				find = true;
		}
		if(find) push(i);
	}
}

void update(int n) {
	
}

void del(int n) {
	
}

void read() {
	cin >> N;
	for(int i = 0;i < 3;++i) {
		for(int j = 1;j <= N;++j) {
			cin >> a[i][j];
			push_num(i, j);
		}
	}
}

void solve() {
	while(tail != head)
		del();
	cout << ans;
}

int main() {
	
}
