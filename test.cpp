#include <iostream>
#include "DES.h"
using namespace std;

int main(void) {
	BYTE p_text[128] = {0,};
	BYTE d_text[128] = {0,};
	BYTE c_text[128] = {0,};
	BYTE key[9] = {0,};
	
	cin >> p_text;
	cin >> key;
	
	DES_Encryption(p_text, c_text, key);
	DES_Decryption(c_text, d_text, key);
	
	DES_Encryption(p_text+BLOCK_SIZE, c_text+BLOCK_SIZE, key);
	DES_Decryption(c_text+ BLOCK_SIZE, d_text+ BLOCK_SIZE, key);



	cout << "\n c : " << c_text;
	cout << "\n d : " << d_text;
	
	
	return 0;
}
