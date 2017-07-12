#include "bigNumber.h"

using namespace std;

bigNumber::bigNumber(char* number){
	int i=0;
	data = new int [25];
	int temp[25];
	while (number[i]!='\0'){
		temp[i] = number[i] - 48;
		i++;
	}
	digit = i;

	int indeks = 0;

	for (int i = digit-1; i >= 0; i--){
		data[indeks] = temp[i];
		indeks++;
	}
}

bigNumber::bigNumber(const bigNumber& n1){
	data = new int[25];
	digit = n1.digit;
	for (int i = 0; i < digit; i++){
		data[i] = n1.data[i];
	}
}

bigNumber::printbigNum(){
	int i=0;
	for (int i = digit-1; i >=0; i--){
		cout << data[i];
	}
	cout << endl;
}

int bigNumber::bigNumberIndex(bigNumber n1, int index){
	return n1.data[index];
}

bigNumber& bigNumber::addbigNum(bigNumber n1, bigNumber n2){
	char temp[25];
	int length = 0;
	int i = 0;
	int result = 0;
	bool carry = false;

	while ((i < n1.digit) || (i < n2.digit)){
		if ((i < n1.digit) && (i < n2.digit)){
			result = bigNumberIndex(n1,i) + bigNumberIndex(n2,i);
			if (carry){
				result++;
			}
			if (result >= 10){
				carry = true;
				result %= 10;
			} else {
				carry = false;
			}
		} else if ((i < n1.digit) && (i >= n2.digit)){
			result = bigNumberIndex(n1,i);
		} else if ((i >= n1.digit) && ( i < n2.digit)){
			result = bigNumberIndex(n2,i);
		} temp[i] = result + '0';
		  i++;
		  length++;
	}

	char reversed[25];
	int indeks = 0;
	for (int i = length-1; i >= 0; i--){
		reversed[indeks] = temp[i];
		cout << reversed[indeks];
		indeks++;
	}
	cout << endl;
	bigNumber res(reversed);
	return res;
}