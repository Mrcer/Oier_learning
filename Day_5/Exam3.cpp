#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 21;
const int MAX_LOOP = 100000000;
bool a[MAX][MAX], water_1[MAX], water_2[MAX], *water_old, *water_new;
bool find_loop;
int sum[MAX], N, H, f[MAX_LOOP];
long long ans, loop_cnt=1;

inline void switch_water_array() {
	if(water_1[0]) {
		//Use water_2
		memset(water_2, 0, MAX);
		water_1[0] = false;
		water_2[0] = true;
		water_old = water_1;
		water_new = water_2;
	}else{
		//Use water_1
		memset(water_1, 0, MAX);
		water_1[0] = true;
		water_2[0] = false;
		water_old = water_2;
		water_new = water_1;
	}
}

void cut_the_loop() {
	//Everything start again...
	ans = (H-1)/loop_cnt*f[loop_cnt]+f[(H-1)%loop_cnt];
}

void pull_water() {
	//Failed
	switch_water_array();
	f[loop_cnt] = f[loop_cnt-1];
	for(int i = 1;i <= N;++i) {
		if(water_old[i]&1) {
			f[loop_cnt] += sum[i];
			for(int j = 1;j <= N;++j)
				if(a[i][j])
					water_new[j] = !water_new[j];
		}else{
			f[loop_cnt] += sum[i]*2;
			continue;
		}
	}
	find_loop = true;
	//Look for a loop
        for(int i = 1;i <= N;++i)
                if(water_new[i]!=a[1][i])
                        find_loop = false;
        if(find_loop)
                cut_the_loop();
        else
	       	find_loop = false;
	++loop_cnt;
}

void read() {
	cin >> N >> H;
	char str[MAX];
	for(int i = 1;i <= N;++i) {
		cin >> str;
		for(int j = 1;j <= N;++j) {
			a[i][j] = str[j-1] - '0';
			sum[i] += a[i][j];
		}
	}
}

int main() {
	read();
	switch_water_array();
	for(int i = 1;i <= N;++i)
		water_new[i] = a[1][i];
	for(int i = 2;i <= H && !find_loop;++i)
		pull_water();
	if(!find_loop) ans += f[loop_cnt-1];
	ans += sum[1]; //The first she did appear to be here
	cout << ans << endl;
	return 0;
}
