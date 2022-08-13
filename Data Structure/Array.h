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
		temp = NULL;
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
		arr[current] = value;
		current++;
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
	int Find(int value) {
		for (int i = 0; i < current; i++) {
			if (arr[i] == value) { return i; }
		}
		return -1;
	}
};

