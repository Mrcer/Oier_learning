#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 10001;
int a[MAX], cnt[6];
bool touched[6];

int get_num() {
	int res = 0;
	for(int i = 1;i <= 5;++i)
		if(!touched[i] && (res==0 || cnt[i]<cnt[res]))
			res=i;
	cnt[res]++;
	return res;
}

void init() {
	a[1] = 1;
	cnt[1] = 1;
	int inner_start=0, inner_max=0, outer_max=1, inner, outer=2, edge_len=0;
	for(int i = 2;i <= MAX;++i) {
		//init
		memset(touched, 0, 6);
		//switch to outer Hex
		if(outer > outer_max) {
			inner = 1;
			outer = 1;
			inner_start += inner_max;
			inner_max = outer_max;
			outer_max = inner_max+6;
			if(outer_max == 7) outer_max--;
			edge_len++;
		}
		//To the previous one
		touched[a[i-1]] = true;
		//On the Vector or the Edge
		if(outer % edge_len == 0 || outer==1) {
			//To the inner Vector
			touched[a[inner_start+inner]] = true;
			if(outer == outer_max) touched[a[inner_start+inner_max+1]] = true;
		} else {
			//To the inner ones
			touched[a[inner_start+inner]] = true;
			touched[a[inner_start+inner+1]] = true;
			inner++;
		}
		a[i] = get_num();
		outer++;
	}
}

int main() {
	init();
	int T, t;
	cin >> T;
	for(int i = 0;i < T;++i) {
		cin >> t;
		cout << a[t] << endl;
	}
	return 0;
}
