#include <iostream>
#include <forward_list>

void moveElementsToFront(std::forward_list<int>& fl, int value) {
	std::forward_list<int> fl1;
	auto prev = fl1.before_begin();

	for (int x : fl) {
		if (x == value) {
			prev = fl1.insert_after(prev, x);
		}
	}

	for (int x : fl) {
		if (x != value) {
			prev = fl1.insert_after(prev, x);
		}
	}

	fl = std::move(fl1);
}

void printList(const std::forward_list<int>& fl) {
	for (int x : fl) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}

int main() {
	std::forward_list<int> fl = { 1, 3, 2, 3, 4, 3 };
	std::cout << "Before: ";
	printList(fl);
	moveElementsToFront(fl, 3);
	// fl содержит: {3, 3, 3, 1, 2, 4}
	std::cout << "After: ";
	printList(fl);
}