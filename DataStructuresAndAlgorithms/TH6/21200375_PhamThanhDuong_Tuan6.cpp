#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
const int N = 20;


char s[N];
int t = 0;


char isEmpty() {
	if(t == 0) return 1;
	else return 0;
}

char isFull() {
	if(t >= N) return 1;
	else return 0;	
}

void push(char x) {
	if(t < N) {
		s[t] = x; t++;
	}
	else puts("Stack day\n");
}

char pop() {
	char x;
	if(t > 0) {
		t--;
		// cout << "t=" << s[t] << "\n";
		x = s[t];
		// cout << "x: " << x << "\n";
		return x;
	}
	else puts("Rong\n");
}

char top() {
	char x;
	if(t > 0) {
		x = s[t-1];
		return x;
	} else puts("Stack rong\n");
	return NULL;
}

int main() {
   cout << "Nhap chuoi: ";
	char x[20];
	cin >> x;
	for(int i = 0; i < 6; i++) {
		push(x[i]);
	}
	

	int n = t;
	for(int i = 0; i < n/2; i++) {
		char xp = pop();
		// cout << "xp: " << int(xp);
		if(x[i] == 40) {
			if(x[i] != xp - 1) {
				cout << "Chuoi sai!\n";
				break;
			}
		}else{
			if(x[i] != xp - 2) {
				cout << "Chuoi sai!\n";
				break;
			}	
		}
	}

	return 0;
}