#include "pch.h"
#include <iostream>
#include <thread>
#include <mutex>

std::mutex one;
std::mutex two;

void functionOne(int* variable) {
	two.lock();
	Sleep(1);
	one.lock();
	*variable += 1;
	printf("%i", *variable);
	Sleep(1);
	two.unlock();
	one.unlock();
}

void functionTwo(int* variable) {
	
	one.lock();
	Sleep(1);
	two.lock();
	*variable += 5;
	printf("%i", *variable);
	Sleep(1);
	one.unlock();
	two.unlock();

}

int main(int argc, LPTSTR argv[]) {
	setlocale(LC_ALL, "Russian");
	int parametr = 15;
	std::thread one(functionOne, &parametr);
	std::thread two(functionTwo, &parametr);
	one.join();
	two.join();
	return 0;
}