#include <bits/stdc++.h>
using namespace std;

void littleJhoolAndHisAddiction(int n, int k, int a[])
{
	sort(a, a + n);
	int min1 = INT_MAX, max1 = INT_MIN;
	int i = 0, j = n - 1;
	while (i < j)
	{
		max1 = max(a[i] + a[j], max1);
		min1 = min(a[i] + a[j], min1);
		i++;
		j--;
	}
	int ans = max1 - min1;
	if (ans < k)
		cout << ans << "\n"
			 << "Chick magnet Jhool!\n";
	else if (ans == k)
		cout << ans << "\n"
			 << "Lucky chap!\n";
	else
		cout << ans << "\n"
			 << "No more girlfriends!\n";
}
int main()
{

	int n = 6, k = 4;

	int a[n] = {1, 6, 6, 7, 1, 8};

	littleJhoolAndHisAddiction(n,k,a);

	return 0;
}