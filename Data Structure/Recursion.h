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

	int Sum(int n) {
		if (n == 0) return 0;
		return Sum(n - 1) + n;
	}
	/*int Sum(int n) {
		return (n * (n - 1)) / 2;
		Time ---> O(1)
	}*/

	int Fact(int n) {
		if (n <= 1) return 1;
		return Fact(n - 1) * n;
	}

	/*int Pow(int m, int n) {
		if (n == 0) return 1;
		return Pow(m, n - 1) * m;
	}*/
	int Pow(int m, int n) {
		if (n == 0) return 1;
		if (n % 2 == 0) return Pow(m * m, n/2);
		return m * Pow(m * m, (n - 1) / 2);
	}
	// Taylor Series
	//float e(int m, int n) {
	//	static float p = 1, f = 1;
	//	float x;
	//	if (n == 0) return 1;
	//	x = e(m, n - 1);
	//	p = p * m;
	//	f = f * n;
	//	return x + (p / f);
	//	// O(N^2)
	//}

	// Taylor Series with Horner's Rule
	float e(float x, float n) {
		static float s = 1;
		if (n == 0) return s;
		s = 1 + (x / n) * s;
		return e(x, n - 1);
	}
};

