// 实验九：函数（续）
// 编写函数get_max，其功能是将字符串s中最大字符的地址返回，再编写一个主函数，调用该函数，
// 将字符串s中从最大字符开始的子串中小写字母转换成大写字母，然后输出新字符串s。
// 例如，假设s的内容为“qwertyou”，则从最大字符’y’开始的子串为“you”，处理后的s为“qwertYOU”。

#include <iostream>

using namespace std;

char  *get_max(char s[]){
	char *imax = s;
	for(char *i = s;*i != '\0';i++){
		if(*i > *imax){
			imax = i;
		}
	}
	return imax;
}

int main(){
	char s[100];
	cin.getline(s,100);
	for(char *i = get_max(s);*i != '\0';i++){
		if('a' <= *i && *i <= 'z'){
			*i += 'A' - 'a';
		}
	}
	cout<< s << endl;
	system("pause");
	return 0;
}