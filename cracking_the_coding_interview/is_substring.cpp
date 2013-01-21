#include <iostream>
#include <string>
using namespace std;

bool find_substring(const string &a, const string& b)
{
	int n = a.length(), m = b.length();
	if (n > m)
		return false;
	if (n == 0)
		return true;
	for (int i = 0; i <= m - n; ++i)
	{
		bool found = true;
		int j = 0;
		while (j < n)
		{
			if (a[j] != b[i+j])
			{
				found = false;
				break;
			}
			++j;
		}
		if (found)
			return true;
	}
	return false;
}

int main()
{
	string x,y;
	cin >> x >> y;
	cout << find_substring(x,y) << endl;
	return 0;
}
