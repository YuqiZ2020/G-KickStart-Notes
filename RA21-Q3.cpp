#include <bits/stdc++.h>
using namespace std;

/**
	RA21-Q3 Rabbit House
	All tests passed
	Solution: Find the grid with biggest height and update the grid around it. Keep doing it
	until all the grids are visited. Use priority queue to implement it to achevie the desired
	time complexity. Use long long to store the answer because it could be very large. 
	Complexity: O(RC*log(RC)) 
*/

void readInGrid(int r, int c, vector<vector<int> >& grid)
{
	int t;
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

struct CompareIntArr {
    bool operator()(const vector<int>& o1, const vector<int>& o2)
    {
        return o1[0] < o2[0];
    }
};

void solve(int caseNum) 
{
	// Read in grids 
	int r = 0; int c = 0; int t = 0;
	cin >> r >> c;
	vector<vector<int>> grid;
	readInGrid(r, c, grid);
	priority_queue<vector<int>, vector<vector<int> >, CompareIntArr> pq;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			vector<int> v = {grid[i][j], i, j};
			pq.push(v);
		}
			
	}
	bool visited[r][c];
	memset(visited, false, sizeof(visited[0][0]) * r * c);
	
	int DIRS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	
	long long ans = 0;
	while (!pq.empty())
	{
		vector<int> cur = pq.top();
		pq.pop();
		int num = cur[0];
		int i = cur[1];
		int j = cur[2];
		if (grid[i][j] != num)
			continue;
		for (int k = 0; k < 4; ++k)
		{
			int newI = i + DIRS[k][0];
			int newJ = j + DIRS[k][1];
			if (newI < 0 || newI >= r || newJ >= c || newJ < 0) continue;
			long long delta = grid[i][j] - grid[newI][newJ];
			if (delta > 1)
			{
				grid[newI][newJ] = grid[newI][newJ] + delta - 1;
				ans = ans + delta - 1;
				vector<int> v = {grid[newI][newJ], newI, newJ};
				pq.push(v);
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
