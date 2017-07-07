#include <iostream>
#include <numeric>

using namespace std;

int inverse(int a, int n){
	int t = 0, r = n, newt = 1, newr = a;
	int quotient;
	while (newr != 0) {
		quotient = r / newr;

		int oldt = newt;
		newt = t - (quotient * newt);
		t = oldt;

		int oldr = newr;
		newr = r - (quotient * newr);
		r = oldr;
	}
	if (t < 0) {
		t += n;
	}
	return t;
}

int gcd(int a, int b){
	if (a < b)
		return gcd(b,a);
	else{
		int oldb = b;
		b = a % b;
		a = oldb;
		if (b == 0)
			return a;
		else return (gcd(a,b));
	}
}

int lcm(int a, int b){
	return ((a * b)/(gcd(a,b)));
}

int main (){
	int p,q,n,totiN,e,d;

	cout << "Silahkan masukkan dua angka prima yang ingin anda gunakan" << endl;
	cout << "Prima pertama : " ;
	cin >> p;
	cout << "Prima kedua : ";
	cin >> q;
		
	n = p * q;
	//totiN = lcm(p - 1, q - 1);
	totiN = (p - 1) * (q - 1);

	cout <<"n,totiN adalah : "<< n << " , " << totiN << endl;

	int i = 2;
	bool eFound = false;
	while ((i < totiN) && (eFound == false)){
		if (gcd(totiN, i) == 1){
			eFound = true;
			e = i;
		} else i++;
	}

	e = 25;

	cout <<"e adalah : " << e << endl;

	d = inverse(e, totiN);
	cout << "Inversenya adalah : " << d << endl;


}