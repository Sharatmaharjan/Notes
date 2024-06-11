#include<stdio.h>
#include<stdlib.h>
	int main(){
		int a[10][10],i,j,M,N,sum=0;
		printf("Enter order of matrix:");
		scanf("%d%d",&M,&N);
		if(M!=N){
			printf("Not square matrix.\n");
			exit(0);
		}
		if(M>10 || N>10){
			printf("The order is out of range.\n");
			exit(0);
		}
		printf("Enter the elements matrix:\n");
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				scanf("%d",&a[i][j]);
				if(i==j){
					sum+=a[i][j]*a[i][j];
				}
			}
		}
		printf("Sum of squares in a diagonal is %d.",sum);
		return 0;
	}
