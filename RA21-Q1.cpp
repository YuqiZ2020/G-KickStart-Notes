#include <bits/stdc++.h>
using namespace std;

/**
	RA21-Q1 K-Goodness String
	All tests passed
	Solution: Loop over the char array, be careful with the 1-based index in prompt. 
*/

void solve(int caseNum) 
{
	int len = 0; int score = 0;
	cin >> len >> score;
	char arr[len];
	for (int i = 0; i < len; ++i) 
		cin >> arr[i];
	
	int halfLen = len / 2;
	int curScore = 0;
	for (int i = 0; i < halfLen; ++i) 
	{
		if (arr[i] != arr[len - i - 1])
			curScore++;
	}
	int ans = abs(curScore - score);
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

