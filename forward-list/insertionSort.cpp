#include <iostream>
#include <forward_list>

void printList(std::forward_list<int>& fl) {
	for (auto x : fl) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}

void insertionSort(std::forward_list<int>& fl) {
	if (fl.empty() || fl.begin() == fl.end()) { return; }
	
	std::forward_list<int> sl;

	for (auto x : fl) {
		auto prev = sl.before_begin();
		auto curr = sl.begin();

		while (curr != sl.end() && *curr < x) {
			++prev;
			++curr;
		}

		sl.insert_after(prev, x);
		printList(sl);
	}

	fl = std::move(sl);
}

int main() {
	std::forward_list<int> fl = { 5, 2, 8, 1, 9 };
	insertionSort(fl);
	// fl содержит: {1, 2, 5, 8, 9}
	std::cout << "sorted list: ";
	printList(fl);
}