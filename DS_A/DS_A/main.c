#include <stdio.h>


/*int hello() {
	printf("Hello");
	return 0;
}*/
int sum(int arr[], int n) {
	int s = 0;
	int i;
	for (i = 0; i < n; i++) {
		s += arr[i];
	}
	return s;
}


int factorial(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++) {
		 fact = fact * i;
	}
	return fact;
}


struct animal {
	int legs;
	char color;
};

void main() {
	/*int a = 077;
	printf("base of 8 : %d\n", a);
	int b = 0x1A;
	printf("base of 16: %d\n", b);
	return 0;*/


	/*int a = 5 > 2 ? 1 : 2;
	printf("%d", a);*/


	/*switch (4 > 3 ? 2 : 1) {
	case 1: printf("Venus gave me blowjob");
			break;
	case 2: printf("Venus and i had intercourse");
			break;
	case 3: printf("Venus likes doggy style");
			break;
	case 4: printf("Venus left me :(");
	}*/


	/*for (int i = 0; i < 10; i++) {
		printf("%d", i);
	}*/


	/*int i= 10;
	do {
		printf("Hi!!\n");
		i--;
	} while (i > 1);*/
	/*printf("%d\n",factorial(5));*/

	/*hello();*/

	/*struct animal human, dog;
	human.legs = 2;
	human.color = "light pink";
	dog.legs = 4;
	dog.color = "yellow";
	printf("%c", human.color);*/
	int n;
	printf("Enter the length of the arr:");
	scanf_s("%d", &n);
	int arr[15];
	for (int i = 0; i < n; i++) {
		printf("Enter the %dth number", i+1);
		scanf_s("%d", &arr[i]);
	}
	int sum1 = sum(arr, n);
	printf("%d",sum1);

	
}