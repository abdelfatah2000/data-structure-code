#pragma once
#include <iostream>

class Recursion
{	
public:
	// Head Recursion
	void fun(int n) {
		if (n > 0) {
			fun(n - 1);
			std::cout << n;
		}
	}

	// Tail Recursion
	void fun2(int m) {
		if (m > 0) {
			std::cout << m;
			fun2(m - 1);
		}
	}
	// Static Variable in Recursion
	int fun3(int n) {
		static int x = 0;
		if (n > 0) {
			x++;
			return fun3(n - 1) + x;
		}
		return 0;
	}

	// Tree Recursion
	void fun4(int s) {
		if (s > 0) {
			std::cout << s;
			fun4(s - 1);
			fun4(s - 1);
		}
	}
	// Indirect Recursion
	void funA(int n) {
		if (n > 0) {
			std::cout << n;
			funB(n - 1);
		}
	}
	void funB(int n) {
		if (n > 1) {
			std::cout << n;
			funA(n / 2);
		}
	}
};

