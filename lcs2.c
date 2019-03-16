#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}


int lcs2(int *a, int n,  int *b, int m) {
	printf("Here");
	int** arr = malloc(sizeof(int *) * (n + 1));
	for(int i = 0; i < n + 1; i++)
		arr[i] = malloc(sizeof(int) * (m + 1));
	printf("done malloc");	
	//fill 1st rows/cols with 0
	for(int i = 0; i < n + 1; i++)
		arr[i][0] = 0;
	for(int i = 0; i < m + 1; i++)
		arr[0][i] = 0;
	printf("done filling initials");
	
	//fill others
	for(int j = 0; j < n + 1; j++)
		for(int k = 0; k < m + 1; k++){
			//printf("here1");
			/*if(j == 0 || k == 0){
				arr[j][k] = 0;
				break;
			}*/
			printf("here2");
			int val = 0;
			if(a[j] == b[k])
				val = arr[j - 1][k - 1] + 1;
			if(val > arr[j][k - 1] && val > arr[j - 1][k])
				arr[j][k] = val;
			else if(arr[j][k - 1] > val && arr[j][k - 1] > arr[j - 1][k])
				arr[j][k] = arr[j][k - 1];
			else
				arr[j][k] = arr[j - 1][k];
			
		}
	int x = arr[n][m];
	for(int i = 0; i < n + 1; i++)
		free(arr[i]);
	free(arr);
	return x;
}

int main() {
	int n, m;  
  
	printf("Enter value of n: ");
	fflush(stdout);
	scanf("%d", &n);
	
	int * a = malloc(n*sizeof(int));
	printf("Enter %d values for array a, separated by spaces:\n", n);
	fflush(stdout);
	for (int i=0; i < n; i++){
		scanf("%d", &a[i]);
	}	
	
	printf("Enter value of m: ");
	fflush(stdout);
	scanf("%d", &m);

	int * b = malloc(m*sizeof(int));
	printf("Enter %d values for array b:\n", m);
	fflush(stdout);
	for (int i=0; i < m; i++){
		scanf("%d", &b[i]);
	}
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	fflush(stdout);
	printf("here");	
	int lcs = lcs2(a, n, b, m);
	printf("LCS = %d\n",lcs);
	
	return 0;
}
