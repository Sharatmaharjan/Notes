#include<stdio.h>
int main(){
	int a,b,c;
	printf("Enter three numbers:");
	scanf("%d%*d%d",&a,&b,&c); // Note: * indicates that the field is to be read but ignored
	printf("a=%d \t b=%d \t c=%d",a,b,c);
	return 0;
}