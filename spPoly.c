#include <stdio.h>
#include <string.h>
#include <math.h>
 
#define ARRAY_SIZE	100
 
void shiftArrayBackByOne(int a[]){
	for(int i = 1; i <= ARRAY_SIZE; i++){
		a[i - 1] = a[i];
	}
}

void printPoly(int a[], int n) {
	for(int i = 0; i < n; i++) {
	if(i < n - 1) {
		printf("%dx^%d + ", a[i], i);
	}
	else {
		printf("%dx^%d \n", a[i], i);
	}
	}
}
 
void printArray(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	putchar('\n');
}
 
void fillArrayWithZeroes(int a[], int n){
	for(int i = 0; i < n; i++){
		a[i] = 0;
	}
}

void fillArrayWithCoefficients(int a[], int n){
	for(int i = 1; i <= n; i++){
		a[i - 1] = i;
	}
}

int fofx(int a[], int n, int x) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int value = x;
		value = a[i] * pow(value, i);
		sum = sum + value;
	}
	return sum;
}

int main(){
	int inputNum;
	int num1;
	int num2;
	int array1[ARRAY_SIZE];
	int array2[ARRAY_SIZE];
	int results[2 * ARRAY_SIZE];
 
	fillArrayWithZeroes(array1, ARRAY_SIZE);
	fillArrayWithZeroes(array2, ARRAY_SIZE);
	fillArrayWithZeroes(results, (2 * ARRAY_SIZE));
 
	char ch;
 	scanf("%d%c%d", &num1, &ch, &num2);
 	
	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
	
	//Check for bad stdin inputs
	if ((num1 >= 100) || (num1 <= -100))
    {
        printf("num1 not in the range [-100, 100]!\n");
        return -1;
    }
    else if ((num2 >= 100) || (num2 <= -100))
    {
        printf("num2 not in the range [-100, 100]!\n");
        return -1;
    }
    else if ((num1 < 1) || (num1 < 1)){
    	printf("Input for n cannot be smaller than one!");
        return -1;
    }
    else if ((num2 < 1) || (num2 < 1)){
    	printf("Input for n cannot be smaller than one!");
        return -1;
    }
    else if (ch != ' '){
		printf("Found a char that isn't space in stdin!");
		return -1;
    }
    
    fillArrayWithCoefficients(array1, num1);
    fillArrayWithCoefficients(array2, num2);
	printArray(array1, num1);
	printArray(array2, num2);
 
 	printf("f(x) = ");
	printPoly(array1, num1);
	printf("g(x) = ");
	printPoly(array2, num2);
	
	for(int i = 0; i < num2; i++) {
		for(int j = 0; j < num1; j++) {
			results[i + j] = results[i + j] + (array2[i] * array1[j]);
		}
	}
	printf("f(x)g(x) = ");
	printPoly(results, (num1 + num2 - 1));
	printf("f(1)g(1) = %d\n", fofx(results, (num1 + num2 - 1), 1));
}