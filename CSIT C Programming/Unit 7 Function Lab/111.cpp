#include<stdio.h>
void str(char *a);
int main(){
	char b[20]="hello world";
	str(b);
	return 0;
}
void str(char *a){
	printf("%s",a);
	
}