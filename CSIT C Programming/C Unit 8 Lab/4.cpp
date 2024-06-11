#include<stdio.h>
struct employee{
	char name[20];
	int id;
	float salary;
};

void display(struct employee []);
int main(){
	struct employee e[5];
	printf("Enter details of 5 employee:\n");
	for(int i=0;i<5;i++){
		printf("Name:");
		scanf("%s",e[i].name);
		printf("ID:");
		scanf("%d",&e[i].id);
		printf("Salary:");
		scanf("%f",&e[i].salary);
	}
	display(e);
	return 0;
}
void display(struct employee e[]){
	printf("The details of 5 students:\n");
	for(int i=0;i<5;i++){
		printf("\nName:%s",e[i].name);
		printf("\nID:%d",e[i].id);
		printf("\nSalary:%f",e[i].salary);
	}
}