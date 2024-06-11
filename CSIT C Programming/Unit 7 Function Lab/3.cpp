#include<stdio.h>
void swap(int*, int*);
int main(){
	int a=10,b=20;
	printf("Before swapping: \na=%d \t b=%d",a,b);
	swap(&a,&b);//passing memory addresses of a and b to swap function.
	printf("\nAfter swapping: \na=%d \t b=%d",a,b);
	return 0;
}
void swap(int *x, int *y){//*x=&a	* is dereference operator which gives value stored in that memory address.
	int temp;
	temp=*x;	//x=memory address *x=value pointed by that MA. We are swapping values not addresses.
	*x=*y;
	*y=temp;
}
