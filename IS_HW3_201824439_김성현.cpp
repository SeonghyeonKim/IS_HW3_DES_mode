#include <iostream>
#include "DES.h"
#include <string>
#define BLOCK_MODE 1	/* 1: CBC, 2: CFB, 3: OFB, 4: CTR */

using namespace std;

int main(void) {
	string c_text, p_text, IV, d_text, key;
	unsigned int ctr;
	int msg_len;
	
	cout << "Input plain text : ";
	cin >> p_text;
	
	cout << "Input Key : ";
	cin >> key; 
	
	#if(BLOCK_MODE!=4)
	cout << "Input initial vector : ";
	cin >> IV;	
	#else
	cout << "Input counter : ";
	cin >> ctr; 
	#endif
	
	msg_len = (p_text.size() % BLOCK_SIZE) ?
		(p_text.size() / BLOCK_SIZE + 1) * 8 :
			p_text.size();
	
	#if(BLOCK_MODE==1)
    c_text = DES_CBC_Enc(p_text, c_text, IV, key, msg_len);//DES-CBC 암호화
    #elif(BLOCK_MODE==2)
    c_text = DES_CFB_Enc(p_text, c_text, IV, key, msg_len);//DES-CFB 암호화
    #elif(BLOCK_MODE==3)
    c_text = DES_OFB_Enc(p_text, c_text, IV, key, msg_len);//DES-OFB 암호화
    #else
    c_text = DES_CTR_Enc(p_text, c_text, key, ctr, msg_len);//DES-CTR 암호화
    #endif

	cout << "\nCipher Text : ";
	for(int i=0; i<msg_len; i++)
		cout << c_text[i];
	cout << "\n";
	

    #if(BLOCK_MODE==1)
    d_text = DES_CBC_Dec(c_text, d_text, IV, key, msg_len);//DES-CBC 복호화
    #elif(BLOCK_MODE==2)
    d_text = DES_CFB_Dec(c_text, d_text, IV, key, msg_len);//DES-CFB 복호화
    #elif(BLOCK_MODE==3)
    d_text = DES_OFB_Dec(c_text, d_text, IV, key, msg_len);//DES-CFB 복호화
    #else
    d_text = DES_CTR_Dec(c_text, d_text, key, ctr, msg_len);//DES-CTR 복호화
    #endif

	cout << "\nPlain Text : ";
	for(int i=0; i<msg_len; i++)
		cout << d_text[i];
	cout << "\n";

	return 0;
} 


