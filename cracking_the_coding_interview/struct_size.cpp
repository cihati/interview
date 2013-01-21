#include <cstdio>
using namespace std;

struct s
{
	char a;
	char* b;
};

int main()
{
	printf("%d\n",sizeof(s));
	return 0;
}
