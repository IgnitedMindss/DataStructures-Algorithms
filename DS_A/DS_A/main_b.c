#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<ctype.h>
//void f(int* x) {
//	*x = 7;
//}

bool compare_strings(char s1[], char s2[]) {
	int l1 = strlen(s1), l2 = strlen(s2);
	if (l1 != l2) {
		return false;
	}
	for (int i = 0; i < l1; i++) {
		if (s1[i] != s2[i]) {
			return false;
		}
	}
	return true;
}

float swap(float a, float b) {
	float c;
	c = a;
	a = b;
	b = c;
	printf("After Swapping: a = %f and b = %f\n", a, b);
	/*printf("%f", a);
	printf("%f", b);*/
}

int power(int base, int expo) {
	int result = 1;
	for (int i = 0; i < expo; i++) {
		result *= base;
	}
	return result;
}

int Arr(int arr[], int N) {
	for (int i = 0; i < N; i++) {
		printf("Enter the %dth element of the array: \n", i + 1);
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++) {
		printf("The %dth element of the array: %d\n",i+1, arr[i]);
	}
	int cmp = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i] > cmp) {
			cmp = arr[i];
		}
	}
	printf("The MAX element of the array: %d", cmp);
}
int Comb(int a, int b){
	int res;
	res = factorial(a)/(factorial(b)*(factorial(a-b)));
	return res;
}

double exp(double x) {
	double ans = 0;
	for (int i = 0; pow(x, i) / factorial(i) > 0.001; i++) {
		ans += pow(x, i) / factorial(i);
	}
	return ans;
}

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		int result = 1;
		for (int i = 1; i <= n; i++) {
			result *= i;
		}
		return result;
	}
}

char BigT(char arr[]) {
	if (strlen(arr) > 10) {
		for (int i = 5; i < 10; i++) {
			printf("%c\t", arr[i]);
		}
	}
}
//int main(){
	//int i;
	//for (i = 0; i < 20; i++) {
	//	if (i % 2 != 0)
	//		continue;
	//	printf("%d\t", i);
	//}

	//return 0;

	/*int a = 5;
	f(&a);
	printf("%d", a);*/



	/*char str1[11] = "Hello";
	char str2[11] = "Hello ";
	if (compare_strings(str1, str2) == true) {
		printf("Equal");
	}
	else {
		printf("Not Equal");
	}*/

	/*int a = 5;
	float b = 7.8;
	printf("Before Swapping: a = %d and b = %f\n", a, b);
	swap(a, b);*/

	/*int b = 3, result, e = 3;
	result = power(b, e);
	printf("%d", result);*/

	/*int N;
	printf("Enter the size of array:");
	scanf_s("%d", &N);
	int arr[50];
	Arr(arr, N);*/

	/*printf("%d",Comb(5, 2));*/

	/*printf("%f", exp(4));*/

	//char arr[] = "asdfghjkjhgf";
	//printf("%c", BigT(arr));


	//char text[] = "I just hate my life cause it is way too boring";
	//int len = strlen(text);
	//for (int i = 0; i < len; i++)
	//{
	//	char c = text[i];
	//	c = tolower(c);
	//	text[i] = c;
	//}
	//int occs[256];
	//for (int i = 0; i < 256; i++)
	//{
	//	occs[i] = 0;
	//}
	//for (int i = 0; i < len; i++)
	//{
	//	char c = text[i];
	//	occs[c]++;
	//}
	//for (int i = 0; i < 256; i++)
	//{
	//	int occ = occs[i];
	//	if(occ > 0)
	//		printf("%c : %d\t", i, occ);
	//}



	//return 0;

//}