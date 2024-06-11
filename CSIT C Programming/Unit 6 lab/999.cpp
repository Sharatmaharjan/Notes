#include<stdio.h>
#include<string.h>
int main(){
char s1[10]="Happy ";
char s2[]="New Year";
printf("s1 = %s\ns2 = %s",s1,s2);
printf("\nAfter concatenating = %s",strcat(s1,s2));
return 0;
}