#include <iostream>

template <typename T, int N, int M>
class Matrix {
public:
	Matrix() {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				mat[i][j] = T{};
			}
		}
	}

	void set(int r, int c, T v) {
		if (r >= 0 && r < N && c >= 0 && c < M) {
			mat[r][c] = v;
		}
	}

	T get(int r, int c) {
		if (r >= 0 && r < N && c >= 0 && c < M) {
			return mat[r][c];
		}
		return T{};
	}

	void print() {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				std::cout << mat[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}

	Matrix operator+(const Matrix& other) {
		Matrix result;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				result.mat[i][j] = this->mat[i][j] + other.mat[i][j];
			}
		}
		return result;
	}
private:
	T mat[N][M];
};

int main() {
	Matrix<int, 2, 3> m1, m2;

	m1.set(0, 0, 8);
	m1.set(0, 1, 15);
	m1.set(0, 2, 2);
	m1.set(1, 0, 7);
	m1.set(1, 1, 17);
	m1.set(1, 2, 3);

	m2.set(0, 0, 25);
	m2.set(0, 1, 19);
	m2.set(0, 2, 7);
	m2.set(1, 0, 1);
	m2.set(1, 1, 3);
	m2.set(1, 2, 10);

	m1.print();
	m2.print();

	Matrix<int, 2, 3> m3;
	m3 = m1 + m2;
	m3.print();

	Matrix<double, 3, 2> m4, m5;

	m4.set(0, 0, 1.2);
	m4.set(0, 1, 17.7);
	m4.set(1, 0, 18.6);
	m4.set(1, 1, 2.9);
	m4.set(2, 0, 2.8);
	m4.set(2, 1, 16.2);

	m5.set(0, 0, 3.2);
	m5.set(0, 1, 0.4);
	m5.set(1, 0, 0.7);
	m5.set(1, 1, 4.2);
	m5.set(2, 0, 6.3);
	m5.set(2, 1, 8.4);

	m4.print();
	m5.print();

	Matrix<double, 3, 2> m6;
	m6 = m4 + m5;
	m6.print();
}