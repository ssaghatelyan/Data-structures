#include <iostream>

template <typename T>
class Range {
public:
	Range(T s, T e) : start(s), end(e) {}

	bool contains(const T& value) {
		return value >= start && value <= +end;
	}

	T lenght() {
		return end - start;
	}

	void print() {
		std::cout << "[" << start << "," << end << "]\n";
	}

private:
	T start;
	T end;
};

int main() {
	Range<int> r1(3, 10);
	r1.print();

	if (r1.contains(3)) {
		std::cout << "Yes\n";
	} else std::cout << "No\n";

	if (r1.contains(6)) {
		std::cout << "Yes\n";
	} else std::cout << "No\n";

	if (r1.contains(13)) {
		std::cout << "Yes\n";
	} else std::cout << "No\n";

	Range<double> r2(1.5, 4.8);
	r2.print();

	if (r2.contains(1.5)) {
		std::cout << "Yes\n";
	} else std::cout << "No\n";

	if (r2.contains(3.1)) {
		std::cout << "Yes\n";
	} else std::cout << "No\n";

	if (r2.contains(4.85)) {
		std::cout << "Yes\n";
	} else std::cout << "No\n";

	Range<char> r3('c', 'f');
	r3.print();

	if (r3.contains('a')) {
		std::cout << "Yes\n";
	} else std::cout << "No\n";

	if (r3.contains('f')) {
		std::cout << "Yes\n";
	} else std::cout << "No\n";

	if (r3.contains('h')) {
		std::cout << "Yes\n";
	} else std::cout << "No\n";
}