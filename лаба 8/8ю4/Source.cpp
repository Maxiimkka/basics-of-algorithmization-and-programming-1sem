#include<iostream>
#include<math.h>
using namespace std;
//метод касательных 
int main() {
	setlocale(LC_CTYPE, "rus");
	double a=-1, b=2, e=0.0001, x , x1;

	if (((2-pow(a,2)+a)*(-2*a+1))>0){
		x1=a ;
	}
	else{
		x1=b ;
	}
	do {
		x = x1;


			x1 = x - ((2 - pow(x, 2) + x) / (-2*x + 1));
	} while (abs(x1 - x) > e);

	cout << "вывод = " << x1;
}