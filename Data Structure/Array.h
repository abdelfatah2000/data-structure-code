#pragma once
#include <iostream>
class Array
{
	int* arr;
	int current, capacity;
	void resize(int newCapacity) {
		int* temp = new int[newCapacity];
		for (int i = 0; i < current; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		capacity = newCapacity;
	}
public:
	Array() {
		capacity = 16;
		current = 0;
		arr = new int[capacity];
	}
	Array(int size) {
		this->capacity = size;
		current = 0;
		arr = new int[size];
	}
	~Array() {
		delete[] arr;
	}
	void Display() {
		for (int i = 0; i < capacity; i++) {
			std::cout << arr[i] << std::endl;
		}
	}
	int Size() {
		return capacity;
	}
	int Length() {
		return current;
	}
	void Push(int value) {
		if (current == capacity) {
			resize(2*capacity);
		}
		/*arr[current] = value;
		current++;*/

		// push item in sorted array
		int i = current - 1;
		while (arr[i] > value) {
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i+1] = value;
	}
	void Inset(int i, int value) {
		if (current == capacity) {
			resize(2 * capacity);
		}
		for (int j = current - 1; j > i; j--) {
			arr[j + 1] = arr[j];
		}
		arr[i] = value;
		current++;
	}
	bool isEmpty() {
		if (current > 0) {
			return true;
		}
		return false;
	}
	int At(int i) {
		return arr[i];
	}
	void Prepend(int value) {
		if (current == capacity) resize(2 * capacity);;
		for (int i = current - 1; i >= 0; i--) {
			arr[i + 1] = arr[i];
		}
		arr[0] = value;
		current++;
	}
	int Pop() {
		int value;
		value = arr[current - 1];
		arr[current - 1] = NULL;
		if (current == (0.25 * capacity)) resize((0.5 * capacity));
		current--;
		return value;
	}
	void Delete(int index) {
		for (int i = index; i < current ; i++) {
			arr[i] = arr[i + 1];
		}
		arr[current - 1] = NULL;
		current--;
	}
	void Remove(int value) {
		for (int i = 0; i < current; i++) {
			if (arr[i] == value) {
				arr[i] = NULL;
				current--;
			}
		}
	}
	void Swap(int *first, int *second) {
		int temp = *first;
		*first = *second;
		*second = temp;
	}
	int linearSearch(int value) {
		for (int i = 0; i < current; i++) {
			if (arr[i] == value) {
				// Transposition
				Swap(&arr[i], &arr[i - 1]);
				return i - 1;

				// Move to Front
				/*Swap(&arr[i], &arr[0]);
				return 0;*/
			}
		}
		return -1;
	}
	int binearySearch(int start, int end, int value) {
		if (start <= end) {
			int mid = ceil((start + end) / 2);
			if (value == arr[mid])	return mid;
			if (value > arr[mid]) binearySearch(mid + 1, end, value);
			else binearySearch(start, mid - 1, value);
		}
		else return -1;
	}
	int Max() {
		int max = arr[0];
		for (int i = 0; i < current; i++) {
			if (max < arr[i]) max = arr[i];
		}
		return max;
	}
	int Min() {
		int min = arr[0];
		for (int i = 0; i < current; i++) {
			if (min > arr[i]) min = arr[i];
		}
		return min;
	}
	void Reverse() {

		/*int* tempArr = new int[current];
		for (int i = current - 1; i > 0; i--) {
			tempArr[i] = arr[current - i - 1];
		}
		for (int i = 0; i < current; i++) {
			arr[i] = tempArr[i];
		}
		delete[] tempArr;*/

		for (int i = 0; i < current; i++) {
			int temp = arr[i];
			arr[i] = arr[current - i - 1];
			arr[current - i - 1] = temp;
		}
	}
	bool isSorted() {
		for (int i = 0; i < current - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
			return true;
		}
	}
};

