#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 210;
int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}}, max_r, max_c, s_r, s_c;
bool a[MAX][MAX];
int b[MAX][2],f[MAX][MAX][MAX], k;

void read() {
	char t;
	cin >> max_r >> max_c >> s_r >> s_c >> k;
	for(int i = 1;i <= max_r;++i){
		for(int j = 1;j <= max_c;++j) {
			cin >> t;
			if(t=='x') a[i][j] = true;
		}
	}
	int t1, t2;
	for(int i = 1;i <= k;++i) {
		cin >> t1 >> t2 >> b[i][1];
		b[i][0] = t2 - t1 + 1;
	}
}

int DFS(int now, int r, int c) {
	if(f[now][r][c]!=0) return f[now][r][c];
	if(now <= k) {
		int maxn = 0;
		for(int i = 0;i <= b[now][0];++i) {
			int now_r = r+i*dir[b[now][1]][0];
			int now_c = c+i*dir[b[now][1]][1];
			if(now_r < 1 || now_c < 1 || now_r > max_r || now_c > max_c || a[now_r][now_c])
				break;
			maxn = max(abs(now_r-r)+abs(now_c-c)+DFS(now+1, now_r, now_c), maxn);
		}
		f[now][r][c] = maxn;
		return f[now][r][c];
	} else {
		return 0;
	}
}

int main() {
	read();
	DFS(1, s_r, s_c);
	cout << f[1][s_r][s_c] << endl;
}
