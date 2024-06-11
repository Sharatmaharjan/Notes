#include<stdio.h>
int fact(int);//declaring a function
int main(){
	int a;
	printf("Enter a number:");
	scanf("%d",&a);
	printf("The factorial of given number = %d",fact(a));//function call from inside main.
	return 0;
}
int fact(int n){//defining  a function
	if(n==0){
		return 1;	//recursion breaker
	}
	else{
		return n*fact(n-1);//recursion 3*fact(2) 3*2*fact(1) 3*2*1*fact(0) 3*2*1*1=6
	}
}
