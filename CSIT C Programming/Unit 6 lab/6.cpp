#include<stdio.h>
int main(){
	int a[3][3],b[3][3],s[3][3];
	int i,j,k;
	
	printf("Enter the elements of 1st matrix:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Enter the elements of 2nd matrix:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			s[i][j]=0;
			for(k=0;k<3;k++){
				s[i][j]=s[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	printf("The multiplication of matrices is:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d\t",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
