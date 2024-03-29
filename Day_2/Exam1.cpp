#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int MAX_INT = 1000000000;
const int MAX = 10;
bool vis[MAX];
int a[MAX][2];
int minn;
int N;

void read() {
	memset(vis, 0, MAX);
	minn = MAX_INT;
	cin >> N;
	for(int i = 0;i < N;++i)
		cin >> a[i][0] >> a[i][1];
}

void DFS(int k, int sour, int bitter) {
	if(sour > MAX_INT || bitter > MAX_INT) return;
	if(k > 0) minn = min(abs(sour-bitter), minn);
	for(int i = 0;i < N;++i) {
		if(vis[i]) continue;
		vis[i] = true;
		DFS(k+1, sour*a[i][0], bitter+a[i][1]);
		vis[i] = false;
	}
}

void solve() {
	DFS(0, 1, 0);
	cout << minn;
}

int main() {
	read();
	solve();
	return 0;
}
