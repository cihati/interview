#include <iostream>
using namespace std;

//eger virtualsa D, virtual degilse B yazdiriyor!!!
class B
{
	public:
		virtual void f()
		{
			cout << "B\n" ;
		}
};

class D : public B
{
	public:
		void f()
		{
			cout << "D\n" ;
		}
};

int main()
{
	B *a = new D;;
	a->f();
	return 0;
}
