#include <iostream>
using namespace std;

bool break_process(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] > 1 || arr[i] < 0) {
			return false;
		}
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	string begin_data;
	cin >> begin_data;

	int sz = size(begin_data);
	int* situation = new int[sz];
	int* temp = new int[sz];

	for (int i = 0; i < sz; i++) {
		if (begin_data[i] == '0') {
			situation[i] = 0;
		}
		else if (begin_data[i] == '1') {
			situation[i] = 1;
		}
		else {
			situation[i] = 2;
		}
	}

	while (!break_process(situation, sz)) {
		for (int i = 0; i < sz; i++) {
			temp[i] = 0;
		}
		for (int i = 0; i < sz; i++) {
			if (situation[i] > 1) {
				temp[i] -= 2;
				if (i == 0) {
					temp[i + 1]++;
				}
				else if (i == (sz - 1)) {
					temp[i - 1] += 1;
				}
				else {
					temp[i - 1] += 1;
					temp[i + 1] += 1;
				}
			}
		}
		for (int i = 0; i < sz; i++) {
			situation[i] += temp[i];
		}
	}

	for (int i = 0; i < sz; i++) {
		cout << situation[i];
	}
    cout << '\n';
}