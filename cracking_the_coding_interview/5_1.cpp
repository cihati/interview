#include <cstdio>
using namespace std;

int main()
{
	int n,m,i,j,mask=1;
	scanf("%d%d%d%d",&n,&m,&i,&j);
	//error checks
	for (int k=i; k<=j; ++k,mask<<=1)
	{
		if (m & mask) n |= 1 << k;
		else n &= ~(1<<k);
	}
	printf("%d\n",n);
	return 0;
}
