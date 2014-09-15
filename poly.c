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
	int isLineTwo = 0;
	int countOne = 0;
	int countTwo = 0;
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
 
	while(scanf("%d%c", &inputNum, &ch) > 0){
 
		//Puts the input into different arrays depeding
		//on value of isLineTwo
		if (isLineTwo == 0){
			array2[countOne] = inputNum;
			countOne++;
		} 
		else if(isLineTwo == 1) {
			array1[countTwo] = inputNum;
			countTwo++;
		}
 
		//Increment isLineTwo if ch is a 'newline'
		if (ch == '\n')
		{
			isLineTwo++;
		}
 
		//Check for bad stdin inputs
		if (isLineTwo > 1){
			printf("Hey, no more than 2 input lines!\n");
			return -1;
		}
		else if ((inputNum >= 100) || (inputNum <= -100))
        {
            printf("Input not in the range [-100, 100]!\n");
            return -1;
        }
        else if (((countOne > 1) && (countTwo > 1)) && ((array1[0] < 1) || (array2[0] < 1))){
        	printf("Input for n cannot be smaller than one!");
            return -1;
        }
        else if ((ch != ' ') && (ch != '\n')){
    		printf("Found a char that isn't space or newline in stdin!");
    		return -1;
        }
        else if ((countOne > 100) || (countTwo > 100))
        {
        	printf("Please don't put more than 100 numbers in one line");
        	return -1;
        }
 
	}
	printArray(array1, countOne);
	printArray(array2, countTwo);
 
	num1 = array1[0];
	num2 = array2[0];
 
	shiftArrayBackByOne(array1);
	shiftArrayBackByOne(array2);
 
	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
 
	printPoly(array1, countOne - 1);
	printPoly(array2, countTwo - 1);
	
	for(int i = 0; i < num2; i++) {
		for(int j = 0; j < num1; j++) {
			results[i + j] = results[i + j] + (array2[i] * array1[j]);
		}
	}
	
	printPoly(results, (num1 + num2 - 1));
	printf("f(1)g(1) = %d\n", fofx(results, (num1 + num2 - 1), 1));
	
	
}