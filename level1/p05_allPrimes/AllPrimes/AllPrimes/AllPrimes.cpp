//打印2-1000内的所有素数
#include<iostream>
#include<cstdlib>
#include<string>
const int MAX_PRIME = 997;
const int LENGTH= 999;
using mstring = std::string;
using std::cout;
void textf(mstring &,int);
int main()
{
	mstring text;
	text.assign(LENGTH, '1');
	textf(text, 0);
	for (int i=0;i<LENGTH;i++)
		if (text[i]=='1')
			cout << i+2 << " ";
	cout << std::endl;
	system("pause");
	return 0;
}
void textf(mstring &text,int textnumber)
{
	if (textnumber == MAX_PRIME-1) return;
	else
	{
	    int bak = text.find_first_of("1", textnumber)+2;
		for (int j = bak; (j + bak-2) < LENGTH; j += bak)
			text[j + bak-2] = '0';
		textf(text, bak - 1);
	}
}