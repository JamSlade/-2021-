#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
double exp() {
	char s[20];
	cin >> s;
	switch(s[0]) {
		case '+':
			return exp() + exp(); //�ݹ���ã������������Ĳ���ʽ
		case '-':
			return exp() - exp();
		case '*':
			return exp() * exp();
		case '/':
			return exp() / exp();
		default:
			return atof(s); //��charת���ɶ�Ӧ�ĸ�����
			break;
	}
}
int main() {
	printf("%lf",exp());
	return 0;
}