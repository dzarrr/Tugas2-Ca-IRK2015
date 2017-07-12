#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <iostream>
using namespace std;

class bigNumber{
public:
	bigNumber(char* number);
	bigNumber(const bigNumber& n1);
	printbigNum();
	int bigNumberIndex(bigNumber n1, int index); //Untuk mendapatkan digit ke-index dari suatu bigNumber
	bigNumber& addbigNum(bigNumber n1, bigNumber n2);
	bigNumber subtractbigNum(bigNumber n1, bigNumber n2);

private:
	int* data;
	int digit;
};

#endif