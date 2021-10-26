#pragma once

#include "iostream"

using namespace std;

template<class T>
class TDStack {
protected:
	T* pMem;
	int size;
	int	pos1;//
	int pos2;//pointers as half-intervals

public:
	TDStack(int _size = 100) :size(_size), pos1(0),pos2(_size-1){
		if (size <= 0)
			throw "NS";
		pMem = new T[size];
	}
	~TDStack() {
		delete[] pMem;
	}
	TDStack(const TDStack& a) {
		size = a.size;
		pMem = new T[size];
		pos1 = a.pos1;
		pos2 = a.pos2;
		for (int i = 0; i < pos1; i++)
			pMem[i] = a.pMem[i];
		for (int i = size-1; i > pos2; i--)
			pMem[i] = a.pMem[i];
	}
	TDStack& operator=(const TDStack& a) {
		if (a == *this)
			return*this;
		if (a.size != size) {
			delete[] pMem;
			size = a.size;
			pMem = new T[size];
		}
		pos1 = a.pos1;
		pos2 = a.pos2;
		for (int i = 0; i < pos1; i++)
			pMem[i] = a.pMem[i];
		for (int i = size - 1; i > pos2; i--)
			pMem[i] = a.pMem[i];
		return *this;
	}
	bool full() {
		return pos1-1 == pos2;
	}
	bool empty1() {
		return pos1 == 0;
	}
	bool empty2() {
		return pos2 == size-1;
	}
	void push1(T val) {
		if (this->full())
			throw "FS";
		pMem[pos1++] = val;
	}
	void push2(T val) {
		if (this->full())
			throw "FS";
		pMem[pos2--] = val;
	}
	T pop1() {
		if (this->empty1())
			throw "ES";
		return pMem[--pos1];
	}
	T pop2() {
		if (this->empty2())
			throw "ES";
		return pMem[++pos2];
	}
	T top1() {
		if (this->empty1())
			throw "ES";
		return pMem[pos1 - 1];
	}
	T top2() {
		if (this->empty2())
			throw "ES";
		return pMem[pos2 + 1];
	}
	void clear() {
		pos1 = 0;
		pos2 = 0;
	}


};
