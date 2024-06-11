#include<stdio.h>
#include<string.h>
struct student{
	int roll;
	char name[20];
	char faculty[20];
	struct{
		int day;
		int month;
		int year;
	}birthdate;
};
int main(){
	struct student s[100];
	int i;
	printf("Enter student details:\n");
	for(i=0;i<100;i++){
		printf("Roll:");
		scanf("%d",&s[i].roll);
		printf("Name:");
		scanf("%s",s[i].name);
		printf("Faculty:");
		scanf("%s",s[i].faculty);
		printf("Enter day of birth:");
		scanf("%d",&s[i].birthdate.day);
		printf("Enter month of birth:");
		scanf("%d",&s[i].birthdate.month);
		printf("Enter year of birth:");
		scanf("%d",&s[i].birthdate.year);
	}
	for(i=0;i<100;i++){
		if(strcmp(s[i].faculty,"BCA")==0){
			printf("Roll = %d \t Name = %s \t Faculty = %s \t Day = %d \t Month = %d \t Year = %d\n",s[i].roll,s[i].name,s[i].faculty,s[i].birthdate.day,s[i].birthdate.month,s[i].birthdate.year);
		}	
	}
	return 0;
}