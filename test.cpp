#include <iostream>
#include "DES.h"
using namespace std;

int main(void) {
	BYTE p_text[128] = {0,};
	BYTE c_text[128] = {0,};
	BYTE d_text[128] = {0,};
	BYTE key[9] = {0,};
	
	cout << "PLAIN : ";
	cin >> p_text;
	cout << "KEY : ";
	cin >> key;
	
	DES_Encryption(p_text, c_text, key);
	DES_Decryption(c_text, d_text, key);	
	
	cout << p_text << "\nc : " << c_text << "\n d : " << d_text;
	
	return 0;
}
