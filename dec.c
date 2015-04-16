#include <stdio.h>
#include <stdlib.h>

void decomposition(int a) {
	if (a==0 || a==1) {
		printf("le nombre %d n'est pas premier\n", a);
	}
	else {
		printf("les facteurs premiers de %d sont :\n", a);
		int b=sqrt(a);
		int i=2;
		while (i<b) {
			if ((a%i) ==0) {
				printf("%d,", i);
				a=a/i;
			}
			if ((a % i) !=0) {
			i++;
			}
		}
		printf("\n");
	}
	return;
}

// ECRIRE IsPrime()

void main(int argc, const char *argv[]) {
	decomposition(1);
	decomposition(527);
	decomposition(869);
	decomposition(1341);
	decomposition(2247);
	decomposition(2359);
	decomposition(3771);
	decomposition(1678);
	decomposition(236);
	decomposition(2578);
	decomposition(5480);
	decomposition(415);
	decomposition(16);
	decomposition(13);
	decomposition(12);
	decomposition(28);
}
