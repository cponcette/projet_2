#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <endian.h>



int main(int argc, char *argv[])
 {
   FILE* fichier = NULL;
   fichier = fopen("numbers.txt", "r");
   int *tab;
   tab = malloc(20*sizeof(int));
   if(fichier != NULL)
   {
   fread(tab, sizeof(int), 20, fichier);//(endroit mémoire, taille des éléments, occurence des éléments, source)//
   }
   else
   {
    printf("Impossible de lire le fichier\n");
   }
   int i;
   for(i=0; i<=20; i++)
   {
    printf("%d\n", tab[i]);
   }
}
