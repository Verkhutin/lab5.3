#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(double x) {
	double s = 1, R, a = 1;
	for (int i = 1; i <= 6; i++) {
		R = x * x / 2 * i;
		a *= R;
		s += a;
	}
	return s;
}

double h(double x) {
	if (abs(x) >= 1)
		return (cos(x) + 1) / (cos(x) * cos(x) + 1);
	else
		return 1. / cos(x) * S(x);
}

int main() {
	double q, q2;
	int n;

	cout << "q = "; cin >> q;
	cout << "q2 = "; cin >> q2;
	cout << "n = "; cin >> n;
	cout << endl;

	cout << "----------------------" << endl;
	cout << "|" << setw(10) << setprecision(2) << "q"
		<< "|" << setw(10) << setprecision(2) << "h(x)" << "|" << endl;
	cout << "----------------------" << endl;

	for (q; q <= q2; q += n) {
		double hx = h(q + 1) + h(q * q + 1) + h(q*q);
		cout << "|" << setw(10) << setprecision(2) << q
			<< "|" << setw(10) << setprecision(2) << hx << "|" << endl;
		cout << "----------------------" << endl;
	}
		
	return 0;
}

