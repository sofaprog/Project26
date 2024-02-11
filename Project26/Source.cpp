#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
long long a[350][350];
long long s[350][350];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<long long> g;
	string st;
	long long t, maxi = -10000000;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> st;
		for (int j = 1; j <= m; j++) {
			a[i][j]=int(st[j-1]);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if(s[i-1][j]!=48 && s[i][j]!=48)
				s[i][j] = s[i - 1][j] + s[i][j];
	for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				cout << s[i][j] << " ";
				t = 0;
				for (int k = 1; k <= m; k++) {
					if (s[j][k] != 48 && s[i - 1][k] != 48) {
						t += s[j][k] - s[i - 1][k];
						if (t > maxi && t%49==0)maxi = t;
						if (t < 0)t = 0;
					}
				}
			}
	}
	cout << maxi/49;
}