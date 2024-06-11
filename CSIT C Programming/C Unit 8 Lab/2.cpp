#include<stdio.h>
struct student{
	char name[20];
	int roll;
	float marks;
	char remarks;
};
int main(){
	struct student s[5];//s[0] s[1] s[2]... s[4]
	int i;
	printf("Enter details of 5 students:\n");
	for(i=0;i<100;i++){//read
		printf("Name:");
		scanf("%s",s[i].name);
		printf("Roll:");
		scanf("%d",&s[i].roll);
		printf("Marks:");
		scanf("%f",&s[i].marks);
		printf("Remarks:");
		scanf(" %c",&s[i].remarks);
	}
	printf("Details of 5 students:\n");
	for(i=0;i<100;i++){//write
		if(s[i].marks>80){
			printf("Name = %s \t Roll = %d \t Marks =%f \t Remarks = %c \n",s[i].name,s[i].roll,s[i].marks,s[i].remarks);
		}
	}
	
	return 0;
}