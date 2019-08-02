#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX = 100000;
pair<int, int> a[MAX];
int f[MAX];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if(a.first < b.first) return true;
	else if(a.first == b.first) return a.second > b.second;
	return false;
}

int main() {
	int N;
	cin >> N;
	for(int i = 0;i < N;++i)
		cin >> a[i].first >> a[i].second;
	sort(a, a+N, cmp);
	int ans = 0;
	for(int i = 0;i < N;++i) {
		f[i] = 1;
		for(int j = i-1;j >= 0;--j)
			if(a[j].second >= a[i].second && f[j] >= f[i])
				f[i] = f[j] + 1;
		ans = max(ans, f[i]);
	}
	cout << ans;
	return 0;
}
