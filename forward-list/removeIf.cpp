#include <iostream>
#include <forward_list>

void mergeSortedLists(std::forward_list<int>& fl1, std::forward_list<int>& fl2) {
	std::forward_list<int> ml;
	auto curr1 = fl1.begin();
	auto curr2 = fl2.begin();
	auto prev = ml.before_begin();

	while (curr1 != fl1.(end) && curr2 != fl2.(end)) {
		if (*curr1 <= *curr2) {
			ml.insert_after(prev, *curr1);
			++curr1;
		}
		else {
			ml.insert_after(prev, *curr2);
			++curr2;
		}
		++prev;
	}

	while (curr1 != fl1.end()) {
		ml.insert_after(prev, *curr1);
		++curr1;
		++prev;
	}

	while (curr2 != fl2.end()) {
		ml.insert_after(prev, *curr2);
		++curr2;
		++prev;
	}

	fl1 = std::move(ml);
	fl2.clear();
}

void printList(std::forward_list<int>& fl) {
	for (auto x : fl) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}

int main() {
	std::forward_list<int> fl1 = { 1, 3, 5 };
	std::forward_list<int> fl2 = { 2, 4, 6 };
	mergeSortedLists(fl1, fl2);
	// fl1 содержит: {1, 2, 3, 4, 5, 6}
	// fl2 пуст

	std::cout << "Merged list: ";
	printList(fl1);

	std::cout << "Second list after merge: ";
	printList(fl2);
}