//������ʽ������ת�ַ�����Ӧ�� ��
//��֧��c++11���� �� 
#include<iostream> 
#include<string>
#include<algorithm>
#include <sstream>
#include<regex>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	
	long a,b,c;
	cin >> a >> b ;
	c = a + b;
	
	string s = to_string(c);
	
	regex pattern("(\\d)(?=(\\d{3})+(?!\\d))");

	cout << regex_replace(s,pattern,"$1,");
	
	return 0; 
	
}
