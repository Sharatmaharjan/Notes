#include<stdio.h>
int main(){
	int n;
	char c;
	printf("Enter a number:");
	scanf("%d",&n);
	printf("\nEnter a character:");
	scanf(" %c",&c); //Note a space before %c
	printf("\nNumber=%d \t Character=%c",n,c);
	return 0;
}