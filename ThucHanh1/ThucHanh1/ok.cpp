#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

int main() {


	for (int i = 750; i < 10000; i++) {
		Beep(750, 1000);
		if (i == 765) {
			Beep(750, 30000);
		}
	}

	return 0;
}