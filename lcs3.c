#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

int lcs3(int *a, int n,  int *b, int m, int *c, int l) {
	int*** arr = calloc(1, sizeof(int **) * (n + 1));
	for(int i = 0; i < n + 1; i++){
                arr[i] = calloc(1, sizeof(int*) * (m + 1));
		for(int j = 0; j < m + 1; j++)
			arr[i][j] = calloc(1, sizeof(int) * (l + 1));
	} 
		
        for(int i = 0; i < n + 1; i++)
                arr[i][0][0] = 0;
        for(int i = 0; i < m + 1; i++)
                arr[0][i][0] = 0;
	for(int i = 0; i < l + 1; i++)
		arr[0][0][i] = 0;

        for(int j = 1; j < n + 1; j++)
                for(int k = 1; k < m + 1; k++)
			for(int i = 1; i < l + 1; i++){ 
                        	int val = 0;
                        	if(a[j - 1] == b[k - 1] && a[j - 1] == c[i - 1]){
                                	val = arr[j - 1][k - 1][i - 1] + 1;
                        	}
                        	if(val >= arr[j][k - 1][i] && val >= arr[j - 1][k][i] && val >= arr[j][k][i - 1]){
                                	arr[j][k][i] = val;
					//printf("EQUAL TO, VAL CHOSEN\n");
				}
                        	else if(arr[j][k - 1][i] >= val && arr[j][k - 1][i] >= arr[j - 1][k][i] && arr[j][k - 1][i] >= arr[j][k][i - 1]){
                                	arr[j][k][i] = arr[j][k - 1][i];
					//printf("K CHOSEN\n");
				}
                        	else if(arr[j - 1][k][i] >= val && arr[j - 1][k][i] >= arr[j][k - 1][i] && arr[j - 1][k][i] >= arr[j][k][i - 1]){
                                	arr[j][k][i] = arr[j - 1][k][i];
					//printf("J CHOSEN\n");
				}
				else{
					arr[j][k][i] = arr[j][k][i - 1];
					//printf("I CHOSEN\n");
				}
				//printf("j: %d k: %d i:%d arr val:%d \n", j, k, i, arr[j][k][i]);

                	}
        int x = arr[n][m][l];
        for(int i = 0; i < n + 1; i++){
		for(int j = 0; j < m + 1; j++)
                	free(arr[i][j]);
		free(arr[i]);
	}
        free(arr);
        free(a);
        free(b);
	free(c);
	return x;
}

int main() {
	int n, m, l;  
  
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
	
	printf("Enter value of l: ");
	fflush(stdout);
	scanf("%d", &l);

	int * c = malloc(l*sizeof(int));
	printf("Enter %d values for array b:\n", l);
	fflush(stdout);
	for (int i=0; i < l; i++){
		scanf("%d", &c[i]);
	}
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	print_array(c, l);
	fflush(stdout);
	
	int lcs = lcs3(a, n, b, m, c, l);
	printf("LCS = %d\n",lcs);
	
	return 0;
}
