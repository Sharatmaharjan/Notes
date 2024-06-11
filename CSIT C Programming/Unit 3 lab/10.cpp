#include<stdio.h>
int main(){
	char str[10]="MY NEPAL";	//8letters
	printf("%s",str);
	printf("\n%10s",str);	//right alignment
	printf("\n%-10s",str);
	printf("\n%.4s",str);
	printf("\n%4s",str);
	printf("\n%10.6s",str);
	printf("\n%-10.6s",str);
	return 0;
}
