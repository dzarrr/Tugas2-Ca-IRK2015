#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <iostream>
#include <vector>
using namespace std;

class bigNumber{
public:
	bigNumber(char* number);
	bigNumber(const bigNumber& n1);
	printbigNum();
	int bigNumberIndex(int index); //Untuk mendapatkan digit ke-index dari suatu bigNumber
	addbigNum(bigNumber n2);
	subtractbigNum(bigNumber n2);
	dividebigNum(bigNumber n2);
	multiplybigNum(bigNumber n2);
	bool isGreaterThan(bigNumber n2);
	bool isSmallerThan(bigNumber n2);

private:
	vector<long long int> data;
	int digit;
	bool positif;
};

#endif
