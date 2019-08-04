#include <iostream>
using namespace std;
const int MAX = 1000010;
int a[2*MAX];

int main() {
	int N;
	cin >> N;
	for(int i = 1;i <= N;++i)
		a[i] = i;
	int start=0, left, right;
	for(int k = 2;k <= N;++k,++start) {
		//The last group
		if(N%k!=0) {
			left = N/k*k+1;
			right = N+1;
			swap(a[start+left], a[start+right]);
		}
		//And the previous groups
		for(int i = N/k;i >= 1;--i) {
			left = (i-1)*k+1;
			right = i*k+1;
			swap(a[start+left], a[start+right]);
		}
	}
	for(int i = start+1;i <= start+N;++i)
		cout << a[i] << ' ';
	return 0;
}
