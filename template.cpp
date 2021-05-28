#include <bits/stdc++.h>
using namespace std;

/**
	RA21-Q1
	All tests
	Solution: 
	Complexity:  
*/

void readInGrid(int r, int c, vector<vector<int> >& grid)
{
	for (int i = 0; i < r; ++i)
	{
		vector<int> v;
		for (int j = 0; j < c; ++j)
		{
			cin >> t;
			v.push_back(t);
		}
		grid.push_back(v);
	}
} 

void solve(int caseNum) 
{
	// Read in grids 
	int r = 0; int c = 0; int t = 0;
	cin >> r >> c;
	vector<vector<int> > grid;
	readInGrid(r, c, grid);
	int ans = 0;
	cout << "Case #" << caseNum << ": ";
	cout << ans << endl;
} 

int main()
{
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; ++i) 
		solve(i);	
}
