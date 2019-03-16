#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

void print_2d(int ** arr, int a, int b){
	for(int j = 0; j < a; j++){
		for (int i=0; i<b; i++){
                	printf("%d ",arr[j][i]);
        	}
        	printf("\n");
	}
}

int lcs2(int *a, int n,  int *b, int m) {
	int** arr = malloc(sizeof(int *) * (n + 1));
	for(int i = 0; i < n + 1; i++)
		arr[i] = malloc(sizeof(int) * (m + 1));
	for(int i = 0; i < n + 1; i++)
		arr[i][0] = 0;
	for(int i = 0; i < m + 1; i++)
		arr[0][i] = 0;
	
	//fill others
	for(int j = 1; j < n + 1; j++)
		for(int k = 1; k < m + 1; k++){
			/*if(j == 0 || k == 0){
				arr[j][k] = 0;
				break;
			}*/
			int val = 0;
			if(a[j - 1] == b[k - 1]){
				val = arr[j - 1][k - 1] + 1;
			//	printf("j = %d k = %d val = %d\n", j, k, val);
			}
			if(val > arr[j][k - 1] && val > arr[j - 1][k])
				arr[j][k] = val;
			else if(arr[j][k - 1] > val && arr[j][k - 1] > arr[j - 1][k])
				arr[j][k] = arr[j][k - 1];
			else
				arr[j][k] = arr[j - 1][k];
			
		}
	//print_2d(arr, n + 1, m + 1);
	int x = arr[n][m];
	for(int i = 0; i < n + 1; i++)
		free(arr[i]);
	free(arr);
	free(a);
	free(b);
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
	
	int lcs = lcs2(a, n, b, m);
	printf("LCS = %d\n",lcs);
	
	return 0;
}
