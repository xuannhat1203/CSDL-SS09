#include<stdio.h>
#include<stdlib.h>
#define V 4
void addEdge(int matrix[V][V],int i,int j){
	matrix[i][j] = 1;
	matrix[j][i] = 1;
}
void printMatrix(int matrix[V][V]){
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
int checkMatrix(int matrix[V][V]){
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(matrix[i][j] != matrix[j][i]){
				return 0;
			}
		}
	}
	return 1;
	
}
int main(){
	int matrix[V][V] = {0};
	addEdge(matrix,0,1);
	addEdge(matrix,1,0);
	addEdge(matrix,1,2);
	addEdge(matrix,2,3);
	printMatrix(matrix); 
	if(checkMatrix(matrix) == 1){
		printf("Do thi doi xung");
	}else{
		printf("Do thi khong doi xung");
	}
}

