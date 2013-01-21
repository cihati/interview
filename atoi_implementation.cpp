#include <cstdio>
#include <climits>
#include <cassert>
using namespace std;

template<typename T>
inline int sgn(T num) { return (num > 0) - (num < 0); }

int myAtoi(const char* str) {
	long result = 0, tempResult;
	int start = 0, end = 10, sign = 1;
	if (str[0] == '-') {
		start++; end++; sign = -1;
	}
	for (int i = start; i < end && str[i]; ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			tempResult = result * 10 + str[i] - '0';
		} else break;
	}
	result *= sign;
	if (result > INT_MAX) return INT_MAX;
	else if (result < INT_MIN) return INT_MIN;
	else return (int) result;
}

void testMyAtoi() {
	assert(myAtoi("10") == 10);
	assert(myAtoi("00000") == 0);
	assert(myAtoi("1234") == 1234);
	assert(myAtoi("-a") == 0);
	assert(myAtoi("-") == 0);
	assert(myAtoi("1234567891234") == INT_MAX);
	assert(myAtoi("-999999999999") == INT_MIN);
	assert(myAtoi("abc51") == 0);
}

int main() {
	testMyAtoi();
	return 0;
}
