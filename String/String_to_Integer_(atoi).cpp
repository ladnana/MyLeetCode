#include <iostream>

using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int i = 0, symbol = 1, res = 0;
		while (i < str.length() && str[i] == ' ') {
			i++;
		}	
		if(str[i] == '-'){
			symbol = 0;
			i++;
		}else if (str[i] == '+') {
			i++;
		}
		
		
		while(i < str.length()){
			if(str[i] < '0' || str[i] > '9'){
				break;
			}
			if (symbol) {//正数溢出
				if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)){
					return INT_MAX;
				}
			}else {//负数溢出
				if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10 + 1)) {
					return INT_MIN;
				}
			}
			res = res * 10 + (str[i] - '0');
			i++;
		}
		return symbol ? res : -res;
	}
};
int main(int argc, char *argv[]) {
	cout << atoi("1") << endl;
	Solution s;
	cout<<s.myAtoi("1")<<endl;
	cout << INT_MAX << endl;
	cout << INT_MIN << endl;
	
	return 0;
}
/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and
ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible
to gather all the input requirements up front.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace
character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by
as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored
and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such
sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the
range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

实现atoi函数
注意三点:
	1.去掉前缀空格
	2.正负号判断
	3.溢出判断(大于2147483647的,都为2147483647,小于-2147483648的,都为-2147483648)
*/