#include<stdio.h>
int main(){
	int n=12345678;//4<6=6	4>2=4.
	float m=12.31456;
	printf(" n=%d",n);
	printf("\n n=%6d",n);
	printf("\n n=%2d",n);
	printf("\n n=%-6d",n);
	printf("\n n=%06d",n);
	printf("\n m=%.2f",m);
	return 0;
}