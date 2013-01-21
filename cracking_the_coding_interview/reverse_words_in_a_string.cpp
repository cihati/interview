#include <iostream>
#include <string>
using namespace std;

void rev(string& str,int l, int r)
{
	while (l < r)
	{
		char c = str[l];
		str[l] = str[r];
		str[r] = c;
		l++; r--;
	}
}

void rev_words(string& str)
{
	int l, r=0,t;
	while (t < str.size())
	{
		t = r;
		while (str[t] != ' ') t++;
		l =  r;
		r = t - 1;
		rev(str,l,r);
		while (str[t] == ' ') t++;
		r = t;
	}
	rev(str,0,str.length() - 1);
}

int main()
{
	string s("   ");
	rev_words(s);
	cout << s << endl;
	return 0;
}
