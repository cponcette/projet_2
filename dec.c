#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Affiche tous les facteurs premiers du nombre a donné
 */
void decomposition(int a) {
	if (a==0 || a==1) {
		printf("le nombre %d n'est pas décomposable en facteurs premiers\n", a);
	}
	else {
		printf("les facteurs premiers de %d sont :\n", a);
		int b=sqrt(a);
		int i=2;
		while (i<=b) {
			if (isPrime(a)==1) {
				printf("%d \n", a);
				return;
			}
			if (isPrime(i)==1) {
				if ( (a%i) == 0 ) {
					printf("%d, ", i);
					a = a/i;
				}
				else {
					i++;
				}
			}
			else {
				i++;
			}

		}
		printf("\n");
	}
	return;
}

/* 
 * Retourne 1 si l'entier n est premier, 0 sinon
 */
int isPrime(int n) {
	if (n==0 || n==1) {
		return 0;
	}
	else {
		int i;
		int m=sqrt(n);
		for (i=2;i<=m;i++) {
			if ((n%i)==0) {
				return 0;
			}
		}
		return 1;
	}	
}


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
	return;
}
