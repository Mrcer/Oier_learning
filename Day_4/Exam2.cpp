#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 100001;
int his_atk[MAX], his_def[MAX], my_card[MAX];
int atk_len, def_len, myc_len;
long long ans1, ans2;

void read() {
	int n, m, power;
	string type;
	cin >> n >> m;
	for(int i = 0;i < n;++i) { 
		cin >> type >> power;
		if(type.compare("ATK")==0)
			his_atk[atk_len++] = power;
		else
			his_def[def_len++] = power;
	}
	for(int i = 0;i < m;++i) {
		cin >> power;
		my_card[myc_len++] = power;
	}
	sort(his_atk, his_atk+atk_len);
	sort(his_def, his_def+def_len);
}

//Attack the poorest with the greatest
void solution1() {
	sort(my_card, my_card+myc_len, greater<int>());
	int len = min(atk_len, myc_len);
	for(int i = 0;i < len;++i) {
		if(his_atk[i] >= my_card[i])
			break;
		else
			ans1 += my_card[i] - his_atk[i];
	}
}

//Try to kill all and attack the hero directly
void solution2() {
	if(myc_len <= atk_len + def_len) return;
	int j = myc_len;
	for(int i = 0;i < def_len;++i) {
		while(j >= 0 && my_card[j] <= his_def[i]) --j;
		if(j >= 0) my_card[j] = 0;
		else return;
	}
	j = myc_len;
	for(int i = 0;i < atk_len;++i) {
		while(j >= 0 && my_card[j] < his_atk[i]) --j;
		if(j >= 0) {
			ans2 += my_card[j] - his_atk[i];
		       	my_card[j] = 0;
		} else return;
	}
	for(int i = 0;i < myc_len;++i)
		ans2 += my_card[i];
}

int main() {
	read();
	solution1();
	solution2();
	cout << max(ans1, ans2) << endl;
}
