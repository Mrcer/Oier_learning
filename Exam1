#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1001;
bool f[MAX], a[MAX];
int N;

void solve() {
	cin >> N;
	bool pre;
	bool up;
	int temp;
	for(int i = 1;i <= N;++i) {
		pre = false;
		for(int j = 1;j <= N;++j) {
			cin >> temp;
			up = f[j];
			f[j] = false;
			temp %= 2;
			pre ^= temp;
			a[j] ^= temp;
			if((!up || i==1) && !pre) f[j]=true;
			if(!f[j-1] && !a[j]) f[j]=true; 
		}
	}
	if(f[N])
		cout << 'W' << endl;
	else
		cout << 'L' << endl;
	memset(f+1, 0, N);
	memset(a+1, 0, N);
}

int main() {
	int T;
	cin >> T;
	for(int i = 0;i < T;++i)
		solve();
}
