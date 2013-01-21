//yanlis
#include <cstdio>
using namespace std;

//int arr[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
int arr[] = {9,9,9,1,2,2,2,4, 7};

int f( int l, int r,int v)
{
	if (l > r) return -1;
	
	int m = l + (r - l) / 2;
	
	if (arr[m] == v) return m;

	if (arr[m] < v && arr[m+1] >= arr[m])
		if (arr[r] >= v) return f(arr,m+1,r,v);
		else return f(arr,l,m-1,v);
	if (arr[m] < v && arr[m+1] < arr[m])
		return f(arr,l,m-1,v);
	if (arr[m] > v && arr[m-1] > arr[m])
		return f(arr,m+1,r,v);
	if (arr[m] > v && arr[m-1] <= arr[m])
		return f(arr,l,m-1,v);
}

int main()
{
	printf("%d\n",f(arr,0,sizeof arr / (sizeof arr[0]),9));
	return 0;
}
