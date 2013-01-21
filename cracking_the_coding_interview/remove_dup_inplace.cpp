#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int n;

void remove_dup()
{
	if (n == 1)
		return;
	int next = 1, cur = 1;
	while (cur < n)
	{
		if (v[cur] != v[next-1])
		{
			v[next++] = v[cur];
		}
		cur++;
	}
	
	printf("\n");
	for (int i=0; i<next; ++i)
		printf("%d ",v[i]);
	printf("\n");
}

int main()
{
	scanf("%d",&n);
	for (int i=0; i<n; ++i)
	{
		int a;
		scanf("%d",&a);
		v.push_back(a);
	}

	remove_dup();
	return 0;
}
