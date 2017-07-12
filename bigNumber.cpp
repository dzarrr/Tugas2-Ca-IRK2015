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

int bigNumber::bigNumberIndex(int index){
	return data[index];
}

bigNumber::addbigNum(bigNumber n2){
	char temp[25];
	int length = 0;
	int i = 0;
	int result = 0;
	bool carry = false;

	while ((i < digit) || (i < n2.digit)){
		if ((i < digit) && (i < n2.digit)){
			result = bigNumberIndex(i) + n2.bigNumberIndex(i);
			if (carry){
				result++;
			}
			if (result >= 10){
				carry = true;
				result %= 10;
			} else {
				carry = false;
			}
		} else if ((i < digit) && (i >= n2.digit)){
			result = bigNumberIndex(i);
		} else if ((i >= digit) && ( i < n2.digit)){
			result = n2.bigNumberIndex(i);
		} temp[i] = result + '0';
		  i++;
		  length++;
	}
	char reversed[25];
	int indeks = 0;
	for (int i = length-1; i >= 0; i--){
		reversed[indeks] = temp[i];
		indeks++;
	}
	reversed[indeks] = '\0';

	delete [] data;
	data = new int [25];

	i = 0;
	int tempint[25];
	while (reversed[i]!='\0'){
		tempint[i] = reversed[i] - '0';
		i++;
	}
	int tempdigit = i;

	indeks = 0;

	for (int i = tempdigit-1; i >= 0; i--){
		data[indeks] = tempint[i] ;
		indeks++;
	}
	digit = tempdigit;
	cout << digit << endl;
}


bigNumber::subtractbigNum(bigNumber n2){
	char temp[25];
	int length = 0;
	int i = 0;
	int result = 0;
	bool carry = false;

	while ((i < digit) || (i < n2.digit)){
		if ((i < digit) && (i < n2.digit)){
			if (bigNumberIndex(i) < n2.bigNumberIndex(i)){
				result = (bigNumberIndex(i)+10) - n2.bigNumberIndex(i);
				if (carry) result --;
				carry = true;
			} else {
				result = bigNumberIndex(i) - n2.bigNumberIndex(i);
				if (carry) result--;
				carry = false;
			} 
		} else if ((i < digit) && (i >= n2.digit)){
			result = bigNumberIndex(i);
		} else if ((i >= digit) && ( i < n2.digit)){
			result = n2.bigNumberIndex(i);
		} 
		  temp[i] = result + '0';
		  i++;	
		  length++;
	}
	char reversed[25];
	int indeks = 0;
	for (int i = length-1; i >= 0; i--){
		reversed[indeks] = temp[i];
		indeks++;
	}
	reversed[indeks] = '\0';
	
	delete [] data;
	data = new int [25];

	i = 0;
	int tempint[25];
	while (reversed[i]!='\0'){
		tempint[i] = reversed[i] - '0';
		i++;
	}
	int tempdigit = i;

	indeks = 0;

	for (int i = tempdigit-1; i >= 0; i--){
		data[indeks] = tempint[i] ;
		indeks++;
	}
	digit = tempdigit;
}

bool bigNumber :: isGreaterThan (bigNumber n2){
	if (digit > n2.digit){
		return (true);
	} else if (digit < n2.digit){
		return (false);
	} else {
		int i = digit-1;
		bool cek = false;
		bool found = false;
		while ((i >= 0) && (!found)){
			if (bigNumberIndex(i) > n2.bigNumberIndex(i)){
				cek = true;
				found = true;
			} else if (bigNumberIndex(i) < n2.bigNumberIndex(i)){
				cek = false;
				found = true;
			} else{
				i--;
			}
		}
		return (cek);
	}
}

bool bigNumber::isSmallerThan (bigNumber n2){
	if (digit < n2.digit){
		return (true);
	} else if (digit > n2.digit){
		return (false);
	} else {
		int i = digit-1;
		bool cek = false;
		bool found = false;
		while ((i >= 0) && (!found)){
			if (bigNumberIndex(i) < n2.bigNumberIndex(i)){
				cek = true;
				found = true;
			} else if (bigNumberIndex(i) > n2.bigNumberIndex(i)){
				cek = false;
				found = true;
			} else{
				i--;
			}
		}
		return (cek);
	}
}
