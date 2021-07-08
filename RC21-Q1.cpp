#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/**
	RA21-Q1
	All tests
	Solution: 
	Complexity:  
*/

ll modVal = 1000000007;

ll modpow(ll num, ll exp) 
{
	ll ret = 1;
    while (exp)
    {
        if (exp & 1)
            ret = (num * ret) % modVal;
        exp >>= 1;
        num = (num * num) % modVal;
    }
    return ret;
}

void solve(int caseNum) 
{
	int len = 0; int k = 0;
	cin >> len >> k;
	char str[len];
	for (int i = 0; i < len; ++i)
		cin >> str[i];
	
	int halfLen = ceil(len / 2.0);
	ll ans = 0;
	for (int i = 0; i < halfLen; ++i)
	{
		long long cur = str[i] - 'a';
		ans = (ans + (cur * modpow(k, halfLen - i - 1)) % modVal) % modVal;
	}
	
	for (int i = halfLen - 1; i >= 0; --i)
	{
		if (str[i] < str[len - i - 1])
		{
			ans = (ans + 1) % modVal;
			break;
		} 
		else if (str[i] > str[len - i - 1])
			break;
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
