#pragma once
#ifndef _HEAP_H
#define _HEAP_H
#include<iostream>
using namespace std;

class Heap
{
private:
	int *arr;
	int size;
	int noOfElements;
public:
	Heap(int=-1);
	void insert(int);
	int Delete();
	//void reheapify(int,int);
	void heapify(int, int);
	void heapsort();
	void swap(int&, int&);
	void display();
};
#endif
