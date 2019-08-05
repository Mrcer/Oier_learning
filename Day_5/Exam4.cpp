#include <iostream>
using namespace std;
const int MAX = 1000001;
int N, a[MAX], ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	int left, right;
	for(int i = 0;i < N;++i) {
		cin >> left >> right;
		ans = a[left] + a[right];
		a[left] = a[right] = 0;
		for(int j = left+1;j < right;++j)
			++a[j];
		cout << ans << endl;
	}
}
