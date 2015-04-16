#include <stdio.h>
#include <stdlib.h>

	
struct facteur {
	int val;
	struct facteur *nxt;
};


void ajout(struct facteur *liste, int valeur) {
	struct facteur new;
	new.val = valeur;
	new.nxt = NULL;
	if (liste == NULL) { // si la liste est vide, il suffit de renvoyer l'élément créé
		return;;
	}
	else { // sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on indique que le dernier élément de la liste est relié au nouvel élément
		struct facteur* temp=liste;
		while(temp->nxt != NULL) {
			temp = temp->nxt;
		}
		temp->nxt= &new;
		return;
	}
}

void decomposition(struct facteur *liste, int a) {
	if (a==0 || a==1) {
		printf("le nombre %d n'est pas premier", a);
	}
	else {
		int b=sqrt(a);
		int i=2;
		while (a<b) {
			if (a%i) {
				ajout(liste, i);
				a=a/i;
			}
			i++;
		}
	}
	return;
}

void afficherListe(struct facteur * liste) {
	struct facteur *tmp = liste;
	printf("salut\n");
	while(tmp != NULL) {
		printf("coucou\n");
		printf("%d", tmp->val);
		tmp = tmp->nxt;
	}
}

void main(int argc, const char *argv[]) {

struct facteur *liste1 = NULL;
struct facteur *liste2 = NULL;
struct facteur *liste3 = NULL;
struct facteur *liste4 = NULL;

decomposition(liste1, 43);
decomposition(liste2, 147);
decomposition(liste3,1);
decomposition(liste4,2);

afficherListe(liste1);
afficherListe(liste2);
afficherListe(liste3);
afficherListe(liste4);
printf("bisou\n");
return;
}
