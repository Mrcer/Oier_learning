#include <iostream>
using namespace std;
const int pipe[8][5] = {{0, 0, 0, 0, 0}, 
{0, 2, 1, 0, 0}, 
{0, 0, 0, 4, 3}, 
{0, 2, 1, 4, 3}, 
{0, 0, 4, 0, 2}, 
{0, 4, 0, 0, 1}, 
{0, 3, 0, 1, 0}, 
{0, 0, 3, 2, 0}
};
const int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int oppo_dir[5] = {0, 2, 1, 4, 3};
const char pipe_name[8] = {'.', '|', '-', '+', '1', '2', '3', '4'};
const int MAX = 27;
int map[MAX][MAX], max_r, max_c, s_r, s_c, e_r, e_c;

inline bool checkRC(int r, int c) {
	return r>=1 && r<=max_r && c>=1 && c<=max_c;
}

void check(int r, int c) {
	cout << r << ' ' << c << ' ';
	bool can_run[5] = {0, 0, 0, 0, 0};
	for(int i = 1;i <= 4;++i) {
		int now_r = r + dir[i][0];
		int now_c = c + dir[i][1];
		if(pipe[map[now_r][now_c]][oppo_dir[i]]!=0)
			can_run[i] = true;
	}
	//CROSSING PIPE FIRST
	if(can_run[1] && can_run[2] && can_run[3] && can_run[4]) {
		cout << '+';
		return;
	}
	for(int i = 1;i <= 7;++i) {
		bool find = true;
		for(int j = 1;j <= 4;++j) {
			if(pipe[i][j]!=0 ^ can_run[j])
				find = false;
		}
		if(find) {
			cout << pipe_name[i] << endl;
			return;
		}
	}
}

void search(int r, int c, int dir_in) {
	int dir_out = pipe[map[r][c]][dir_in];
	int next_r = r + dir[dir_out][0];
	int next_c = c + dir[dir_out][1];
	if(map[next_r][next_c]!=0)
		search(next_r, next_c, oppo_dir[dir_out]);
	else
		check(next_r, next_c);
}

void read() {
	cin >> max_r >> max_c;
	char c;
	for(int i = 1;i <= max_r;++i) {
		for(int j = 1;j <= max_c;++j) {
			cin >> c;
			switch(c) {
				case '.': map[i][j]=0;break;
				case '|': map[i][j]=1;break;
				case '-': map[i][j]=2;break;
				case '+': map[i][j]=3;break;
				case '1': map[i][j]=4;break;
				case '2': map[i][j]=5;break;
				case '3': map[i][j]=6;break;
				case '4': map[i][j]=7;break;
				case 'M': s_r=i;s_c=j;break;
				case 'Z': e_r=i;e_c=j;break;
			}
		}
	}	
}

int main() {
	read();
	for(int i = 1;i <= 4;++i) {
		int now_r = s_r + dir[i][0];
		int now_c = s_c + dir[i][1];
		if(checkRC(now_r, now_c) && pipe[map[now_r][now_c]][oppo_dir[i]]!=0) {
			search(now_r, now_c, oppo_dir[i]);
			return 0;
		}
	}
	return 1;
}
