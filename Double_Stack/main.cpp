

#include "TDSTack.h"

int main() {
	TDStack<int> a(100);
	cout << "Empty stacks?\n";
	cout << a.empty1() << " " << a.empty2() << "\n";
	cout << "Push to stack elements 2(in 1),7(in 2)\n";
	a.push1(2); a.push2(7);
	cout << "Empty stacks?\n";
	cout << a.empty1() << " " << a.empty2() << "\n";
	cout << "Elements on top of stacks:\n";
	cout << a.top1() << " " << a.top2() << "\n";
	cout << "Is stacks full? " << a.full() << "\n";
	a.pop1(); a.pop2();
	for (int i = 0; i < 100; i++) {
		if (i % 2 == 0)
			a.push1(i);
		else
			a.push2(i);
	}
	cout << "Fill stacks.\n";
	cout << "Is stacks full? " << a.full() << "\n";
	cout << "First stack:\n";
	while (!a.empty1()) {
		cout << a.pop1() << " ";
	}
	cout << "\n";
	cout << "Second stack:\n";
	while (!a.empty2()) {
		cout << a.pop2() << " ";
	}
	cout << "\n";
}	