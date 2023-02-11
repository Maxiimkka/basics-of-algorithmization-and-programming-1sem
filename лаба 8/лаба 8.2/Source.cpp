#include<iostream>
#include<math.h>
using namespace std;
//1.1(трапеции)
int main() {
	setlocale(LC_ALL, "Rus");
	double a=8, y,b=12,  h, x, s;
	int n = 200;
	x = a;
	s = 0;
	h = (b - a) / n;

	while(x < (b - h)) {


	s = s + h * ((5-pow(x,2)) + (5 - pow((x+h), 2))) / 2;
	x = x + h;


}



cout << "s=" << s<<endl;

}