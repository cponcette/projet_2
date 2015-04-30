# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <string.h>
# include <sys/mman.h>
#include <time.h>


int maxthreads = 500; // argument -maxthreads n


int i=0, j=0, k=0;
int *buffer2=(int *) malloc(20*sizeof(int)); 
int *buffer1=(int *) malloc(sizeof(int)*maxthreads);
sem_t vide1, plein1, mutex1, vide2, plein2, mutex2; //Déclaration de sémaphores

void *prod_meth(void *arg) {
	// while (isfile)
	sem_wait(&plein1);
	sem_wait(&mutex1);
	//buffer1[i]= // remplir le buffer1 , faire fonction
	i=(i+1)%maxthreads;
	sem_post(&mutex1);
	sem_post(&vide1);
	return NULL; // a changer eventuellement
}

void *cons_meth(void *arg) {
	sem_wait(&vide1);
	sem_wait(&mutex1);
	sem_wait(&plein2);
	sem_wait(&mutex2);
	//buffer=buffer1[j] //vider le buffer1, faire fonction, remplir le buffer2
	j=(j+1)%maxthreads;
	sem_post(&mutex2);
	sem_post(&vide2);
	sem_post(&mutex1);
	sem_post(&plein1);
	return NULL; // a changer eventuellement
}

void *final_meth(void *arg) {
	sem_wait(&vide2);
	sem_wait(&mutex2);
	// = buffer2[k]  vider le buffer 2
	k=(k+1)%maxthreads;
	sem_post(&mutex2);
	sem_post(&plein2);
	return NULL;
}

int main(int argc, char *argv[]) {

	clock_t start = clock(), diff; // lancement de l'horloge
	int nbProd=1; // combien de prod ??
	int nbCons=maxthreads;
	pthread_t cons[nbCons];
	pthread_t prod[nbProd];
	pthread_t final;
	int m;
	// initialisation des sémaphores
	sem_init(&mutex1, 0, 1);
	sem_init(&plein1, 0, 0);
	sem_init(&vide1, 0, maxthreads);
	sem_init(&mutex2, 0, 1);
	sem_init(&plein2, 0, 0);
	sem_init(&vide2, 0, maxthreads);
	
	for(m=0;m<nbProd;m++) {
		pthread_create(&prod[m], NULL, prod_meth, NULL);
	}

	for(m=0;m<nbCons;m++) {
		pthread_create(&cons[m], NULL, cons_meth, NULL);
	}

	pthread_create(&final, NULL, final_meth, NULL);


	diff = clock() - start;//fin du décompte du temps

	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Time taken %d seconds %d milliseconds", msec/1000, msec%1000);


	return 0;
}
	
	
	


