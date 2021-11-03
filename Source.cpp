#include <iostream>
using namespace std;
int main() {
	int N, M;
	do {
		cout << "Number of rows" << '\n';
		cin >> N;
		cout << "Number of cols" << '\n';
		cin >> M;
		while ((cin.fail()) || (N <= 0) || (M <= 0)) {
			cout << "Error!" << '\n';
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Number of rows" << '\n';
			cin >> N;
			cout << "Number of cols" << '\n';
			cin >> M;
		}
	} while (cin.fail());
	float** arr = new float* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new float[M];
	}
	cout << "Input matrix" << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			while (cin.fail()) {
				cout << "Error!" << '\n';
				cin.clear();
				cin.ignore(32767, '\n');
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	int sum1, sum2, flag, t;
	do {
		flag = 0;
		for (int i = 0; i < N-1; i++) {
			sum1 = 0;
			sum2 = 0;
			for (int j = 0; j < M; j++) {
				sum1 += arr[i][j];
				sum2 += arr[i + 1][j];
			}
			if (sum1 > sum2) {
				flag++;
				for (int j = 0; j < M; j++) {
					t = arr[i][j];
					arr[i][j] = arr[i + 1][j];
					arr[i + 1][j] = t;
				}
			}
		}
	} while (flag != 0);
	cout << "Output matrix"<<'\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 0; i < N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}