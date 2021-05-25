#include <bits/stdc++.h>
using namespace std;

/**
	RA21-Q2 L Shaped Plots
	Test 1 passed
	Solution: Calculate the prefix sum of the grid, then for each pair
	of two cells, query the prefix sum to find the valid segments, 
	and see if any two vertical and horizontal segments can pair up.
	Complexity: O(R^2C^2)
*/

int query(int a, int b, int c, int d, vector<vector<int> >& grid)
{
	if (b > d)
	{
		swap(a, c);
		swap(b, d);
	} 
	int ans = grid[c][d];
	if (a > 0)
		ans -= grid[a - 1][d];
	if (b > 0)
		ans -= grid[c][b - 1];
	if (a > 0 && b > 0)
		ans += grid[a - 1][b - 1];
	return ans;
}

void buildPrefixSum(int r, int c, vector<vector<int> >& grid)
{
	for (int i = 1; i < r; ++i)
		grid[i][0] += grid[i - 1][0];
	for (int j = 1; j < c; ++j)
		grid[0][j] += grid[0][j - 1];
	for (int i = 1; i < r; ++i) 
	{
		for (int j = 1; j < c; ++j)
			grid[i][j] = grid[i][j] + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
	}
}

void solve(int caseNum) 
{
	// Read in data
	int r = 0; int c = 0; int t = 0;
	cin >> r >> c;
	vector<vector<int> > grid;
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
	// Calculate prefix sum
	buildPrefixSum(r, c, grid);
	// Process
	int num = r * c;
	int ans = 0;
	for (int i = 0; i < num; ++i)
	{
		int iX = i / c; int iY = i - iX * c;
		for (int j = i + 1; j < num; ++j)
		{
			int jX = j / c; int jY = j - jX * c;
			if (iX == jX || iY == jY)
				continue;
			int segL = query(iX, iY, jX, iY, grid);
			int segR = query(iX, jY, jX, jY, grid);
			int segT = query(iX, iY, iX, jY, grid);
			int segB = query(jX, iY, jX, jY, grid);
			if (segL != jX - iX + 1)
				segL = -1;
			if (segR != jX - iX + 1)
				segR = -1;
			if (segT != jY - iY + 1)
				segT = -1;
			if (segB != jY - iY + 1)
				segB = -1;
				
			if (segL == segT * 2 || segT == segL * 2)
				ans++;
			if (segR == segT * 2 || segT == segR * 2)
				ans++;
			if (segL == segB * 2 || segB == segL * 2)
				ans++;
			if (segR == segB * 2 || segB == segR * 2)
				ans++;
		}	
	}
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

