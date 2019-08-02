#include <iostream>
using namespace std;
const int MAX = 100010;
int a[3][MAX], basket[3][MAX], team[MAX], head, tail, num, N, ans;
bool del_flag[MAX];

struct Number {
	int j;
	int next;
}numbers[MAX];

inline void push(int i) {
	team[++head]=i;
}

inline void push_num(int i, int j) {
	numbers[++num].j = j;
	numbers[num].next = basket[i][a[i][j]];
	basket[i][a[i][j]] = num;
}

inline int pop() {
	return team[++tail];
}

void init() {
	for(int i = 1;i <= N;++i) {
		if(basket[1][i]==0 || basket[2][i]==0)
		       	push(i);
	}
}

void del(int n) {
	for(int i = 0;i < 3;++i) {
		for(int j = basket[i][n];j;j=numbers[basket[i][n]].next) {
			int c = numbers[basket[i][n]].j;
			for(int k = 0;k < 3;++k) {
				if(k==i) continue;
				if(numbers[basket[k][a[k][c]]].j == c) {
					basket[k][a[k][c]] = numbers[basket[k][a[k][c]]].next;
					if(basket[k][a[k][c]]==0) push(a[k][c]);
				} else {
					int pre = basket[k][a[k][c]];
					for(int l = 0;l;l=numbers[basket[k][a[k][c]]].next) {
						if(numbers[basket[k][a[k][c]]].j == c) {
							numbers[pre].next = numbers[basket[k][a[k][c]]].next;
							break;
						}
						pre=numbers[pre].next;
					}
				}
			}
		}
		basket[i][n]=0;
	}
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
	while(tail != head) {
		del(pop());
		ans++;
	}
	cout << ans;
}

int main() {
	read();
	init();
	solve();
}
