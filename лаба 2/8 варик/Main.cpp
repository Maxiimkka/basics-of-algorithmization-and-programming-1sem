#include <iostream>
void main()
{
	double s, t, j = 12, y = 5e-6, x = 0.1;
	s = 0.4*x-1/j*tan(y);
	t = s-sin(s);
	std::cout << "s=" << s << ' ';
	std::cout << "t=" << t;
	
}
