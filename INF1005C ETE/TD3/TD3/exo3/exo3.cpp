#include <iostream>
using namespace std;

int main() {
	cout << "Les nombres parfaits entre 1 et 10 000 sont : " << endl;
	for (int i = 1; i <= 10000; i++) {
		int j = 1, sommeDiviseur = 0;
		while (j < i) {
			if (i%j == 0) {
				sommeDiviseur += j;
				j++;
			}
			else {
				j++;
			}
		}
			if (sommeDiviseur == i) {
				cout << i << endl;
			}

		

	}
}