#include <stdio.h>
char* thousands[] =	{"","M","MM","MMM"};
char* hundreds[] =	{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
char* ten[] =		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
char* one[] =		{"","I","II","III","IV","V","VI","VII","VIII","IX"};
char dig[5];  //储存数字
char ans[100];//储存结果

int main(){
	int num;
	while(~scanf("%d",&num)){
		sprintf(dig,"%4d",num);
		if(dig[0]!=' ')printf("%s",*(thousands+	dig[0]-'0'));
		if(dig[1]!=' ')printf("%s",*(hundreds +	dig[1]-'0'));
		if(dig[2]!=' ')printf("%s",*(ten +		dig[2]-'0'));
		if(dig[3]!=' ')printf("%s",*(one +		dig[3]-'0'));
		puts("");
	}
}