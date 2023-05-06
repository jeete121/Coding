#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(6);
	s.insert(3);
	s.insert(7);
	s.insert(2);

	cout << "Elements of unordered_set: \n";
	for (auto it : s)
		cout << it << " ";

	return 0;
}
