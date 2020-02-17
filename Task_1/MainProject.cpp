#include <iostream>
#include <math.h>
#include <string>

#define long long int int
using namespace std;

signed main()
{
	int n, sum = 0, isum = 0, msum = -1;
	cin >> n;
	string s[100];
	int p, m, a, b, c, d, e;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> p >> m >> a >> b >> c >> d >> e;
		sum = p * 100 - m * 50 + a + b + c + d + e;
		if (sum > msum)
		{
			isum = i;
			msum = sum;
		}
	}
	cout << s[isum];
	return 0;
}