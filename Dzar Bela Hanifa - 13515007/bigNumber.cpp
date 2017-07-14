#include "bigNumber.h"
#define size 50
using namespace std;

bigNumber::bigNumber(char* number){
	int i=0;
	data.clear();
	int temp[size];
	while (number[i]!='\0'){
		if (i == 0){
			if (number[i] == '-') positif = false;
			else temp[i] = number[i] - '0';
		} else temp[i] = number[i] - '0';
		i++;
	}
	digit = i;

	for (int i = digit-1; i >= 0; i--){
		data.push_back(temp[i]);
	}
}

bigNumber::bigNumber(const bigNumber& n1){
	data.clear();
	digit = n1.digit;
	for (int i = 0; i < digit; i++){
		data.push_back(n1.data[i]);
	}
	positif = n1.positif;
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
	char temp[size];
	int length = 0;
	int i = 0;
	int result = 0;
	bool carry = false;

	while ((i < digit) || (i < n2.digit)){
		if ((i < digit) && (i < n2.digit)){
			result = this->data[i] + n2.data[i];
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
			result = data[i];
		} else if ((i >= digit) && ( i < n2.digit)){
			result = n2.data[i];
		} temp[i] = result + '0';
		  i++;
		  length++;
	}
	if (carry) {
		temp[length] = '1';
		length++;
	}

	char reversed[size];
	int indeks = 0;
	for (int i = length-1; i >= 0; i--){
		reversed[indeks] = temp[i];
		indeks++;
	}
	reversed[indeks] = '\0';

	data.clear();

	i = 0;
	int tempint[size];
	while (reversed[i]!='\0'){
		tempint[i] = reversed[i] - '0';
		i++;
	}
	int tempdigit = i;

	for (int i = tempdigit-1; i >= 0; i--){
		data.push_back(tempint[i]);
	}
	digit = tempdigit;
}


bigNumber::subtractbigNum(bigNumber n2){
	char temp[size];
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
	while(temp[length-1] == '0'){
		length--;
	}
	char reversed[size];
	int indeks = 0;
	for (int i = length-1; i >= 0; i--){
		reversed[indeks] = temp[i];
		indeks++;
	}
	reversed[indeks] = '\0';
	
	data.clear();

	i = 0;
	int tempint[size];
	while (reversed[i]!='\0'){
		tempint[i] = reversed[i] - '0';
		i++;
	}
	int tempdigit = i;

	for (int i = tempdigit-1; i >= 0; i--){
		data.push_back(tempint[i]);
	}
	digit = tempdigit;
}

bigNumber::multiplybigNum(bigNumber n2){
	int temp[size*2];
	char tempstring[size*2];
	int templength = digit + n2.digit - 1;
	int carry = 0;
	for (int i = 0; i < size*2; i++) temp[i] = 0;
	int plus = 0;

	for (int i = 0; i < n2.digit; i++){
		for (int j = 0; j < digit; j++){
			temp[plus+j] += bigNumberIndex(j) * n2.bigNumberIndex(i);
		}
		plus++;
	}

	for (int i = 0; i < templength; i++){
		temp[i] += carry;
		tempstring[i] = (temp[i]%10) + '0';
		carry = temp[i] / 10;
	}
	int i = 0;
	while (carry != 0){
		tempstring[templength + i] = carry%10 +'0';
		carry /= 10;
		i++;
	}
	templength = templength + i ;


	char reversed[size];
	int indeks = 0;
	for (int i = templength-1; i >= 0; i--){
		reversed[indeks] = tempstring[i];
		indeks++;
	}
	reversed[indeks] = '\0';
	
	data.clear();

	i = 0;
	int tempint[size];
	while (reversed[i]!='\0'){
		tempint[i] = reversed[i] - '0';
		i++;
	}
	int tempdigit = i;

	indeks = 0;

	for (int i = tempdigit-1; i >= 0; i--){
		data.push_back(tempint[i]) ;
		indeks++;
	}
	digit = tempdigit;
}

bigNumber::dividebigNum (bigNumber n2){

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

