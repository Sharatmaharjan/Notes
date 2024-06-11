#include<stdio.h>
int main(){
	int day,month,year;
	printf("Enter your date of birth in sequence day, month and year separated by / character:");
	scanf("%d/%d/%d",&day,&month,&year);
	printf("Your date of birth is: %d day %d month %d year.",day,month,year);
	return 0;
}
