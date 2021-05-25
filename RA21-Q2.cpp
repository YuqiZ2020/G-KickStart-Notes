#include <bits/stdc++.h>
using namespace std;

/**
	RA21-Q2 L Shaped Plots
	All tests passed
	Solution: Use dynamic programming to find the consecutive grids on top, left, bottom, right of the cell, 
	then by pairing up vertical and horizontal sides' lengths, we can calculate the possible L-shapes
	that can be formed. 
	Complexity: O(RC)
*/

void buildTopLeft(int r, int c, vector<vector<int> >& grid, vector<vector<int> >& top, vector<vector<int> >& left)
{
	for (int i = 0; i < r; ++i)
		top.push_back(vector<int>(c, 0));
	for (int i = 0; i < r; ++i)
		left.push_back(vector<int>(c, 0));
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (grid[i][j] != 0)
			{
				if (i > 0)
					top[i][j] = top[i - 1][j] + 1;
				else
					top[i][j] = grid[i][j];
				if (j > 0)
					left[i][j] = left[i][j - 1] + 1;
				else
					left[i][j] = grid[i][j];
			}
		} 
	}
}

void buildBottomRight(int r, int c, vector<vector<int> >& grid, vector<vector<int> >& bottom, vector<vector<int> >& right)
{
	for (int i = 0; i < r; ++i)
		bottom.push_back(vector<int>(c, 0));
	for (int i = 0; i < r; ++i)
		right.push_back(vector<int>(c, 0));
	for (int i = r - 1; i >= 0; --i)
	{
		for (int j = c - 1; j >= 0; --j)
		{
			if (grid[i][j] != 0)
			{
				if (i < r - 1)
					bottom[i][j] = bottom[i + 1][j] + 1;
				else
					bottom[i][j] = grid[i][j];
				if (j < c - 1)
					right[i][j] = right[i][j + 1] + 1;
				else
					right[i][j] = grid[i][j];
			}
		} 
	}
}

int countLShape(int hor, int vert)
{
	int ret = max(0, min(hor / 2, vert) - 1);
	ret += max(0, min(vert / 2, hor) - 1);
	return ret;
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
	// Build top, left, bottom, right
	vector<vector<int> > top, left, bottom, right;
	buildTopLeft(r, c, grid, top, left);
	buildBottomRight(r, c, grid, bottom, right);
	// Process
	int ans = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (grid[i][j] != 0)
			{
				ans = ans + countLShape(left[i][j], top[i][j]) + countLShape(right[i][j], top[i][j]) + 
					countLShape(right[i][j], bottom[i][j]) + countLShape(left[i][j], bottom[i][j]);
			}
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

