#include <cstdio>
using namespace std;

int* ad1;

void f()
{
	int b;
	printf("defined before:%u\ndefined after:%u\n",ad1,&b);
}

int main()
{
	int a;
	ad1 = &a;
	f();
	return 0;
}
