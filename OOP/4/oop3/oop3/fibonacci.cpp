#include "fibonacci.h"
Fibonacci::Fibonacci() {
	f1 = 1;
	f2 = 1;
}
int Fibonacci::Get() {
	int c;

	c = f1 + f2;
	f1 = f2;
	f2 = c;

	return f2;
}

int Fibonacci::Set(int parameter) {

	while (Get() <= parameter);
	return Get();
}

