//传统私钥系统
#include<iostream>
#include<cstdlib>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
const string encrypt(const string&);
const string decrypt(const string&);
int main()
{
	string input;
	cin >> input;
	cout<<encrypt(input)<<endl;
	cout << decrypt(encrypt(input))<<endl;
	system("pause");
	return 0;
}
const string encrypt(const string& input)
{
	string encryptS=input;
	for (auto& charI : encryptS)
		charI += 24;
	return encryptS;
}
const string decrypt(const string& output)
{
	string decryptS = output;
	for (auto& charI : decryptS)
		charI -= 24;
	return decryptS;
}