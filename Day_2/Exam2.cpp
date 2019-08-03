#include<iostream>
#include<cmath>
using namespace std;
const int MAX = 101;
int a[MAX], f[MAX][MAX], N, ans;

inline int trans(int i) {
	return (N+i)%N;
}

void read() {
	cin >> N;
	for(int i = 0;i < N;++i) {
		cin >> a[i];
		a[i] = a[i]&1;
		f[i][i] = a[i];
	}
}

void dp() {
	for(int len = N-1;len > 0;--len)
		for(int i = 0;i < N;++i)
			f[i][trans(i+len)] = max(-f[trans(i-1)][trans(i+len)] + a[i], -f[i][trans(i+len+1)] + a[trans(i+len)]);
}

int main() {
	read();
	dp();
	for(int i = 0;i < N;++i)
		if(-f[trans(i-1)][trans(i+1)]+a[i]>0) ans++;
	cout << ans << endl;
}
