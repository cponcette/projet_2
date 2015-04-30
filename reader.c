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
   fichier = fopen("file1", "r");
   int *onebuffer[20];
  if(fichier != NULL)
   {
   fread(onebuffer, sizeof(int), 20, fichier);//(endroit mémoire, taille des éléments, occurence des éléments, source)//
   int *buffer;
   buffer = malloc(20*(sizeof(int)));
   int i;
   for(i=0 ; i<=20 ; i++)
    {
     buffer[i] = be64toh(onebuffer[i]);
     return 0;
    }
   int j;
   for(j=0; i<=20 ; j++)
    {
     printf(buffer[i]);
    }
    return 0;
   }
  return 0;
}



