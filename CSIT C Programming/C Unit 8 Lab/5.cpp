#include<stdio.h>
struct employee{
	char name[20];
	int id;
	float salary;
};
void display(struct employee []);
int main(){
	struct employee e[5],*ptr;//*ptr is pointer to structure
	ptr=e;
	printf("Enter details of 5 employee:\n");
	for(int i=0;i<5;i++){
		printf("Name:");
		scanf("%s",(ptr+i)->name);
		printf("ID:");
		scanf("%d",&(ptr+i)->id);
		printf("Salary:");
		scanf("%f",&(ptr+i)->salary);
	}
	display(e);
	return 0;
}
void display(struct employee *ptr){//ptr=e
	printf("The details of 5 employees:\n");
	for(int i=0;i<5;i++){
		printf("\nName:%s",(ptr+i)->name);
		printf("\nID:%d",(ptr+i)->id);
		printf("\nSalary:%f",(ptr+i)->salary);
	}
}