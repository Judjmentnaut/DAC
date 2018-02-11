#include <stdio.h>
#define DIM 20

void menu();

void cifratura(char v[]);

//	void decifratura(char v[]);   decifrazione spostata nella versione 1.2

int main(){
	char v[DIM];
	char temp;
	FILE *pf;
	
	menu();
	cifratura(v);
}

void cifratura(char v[]){
	int i, cif1, cif2;
	char temp;
	FILE *pf;
	
	printf("\n prima chiave di cifratura : ");
	scanf("%d", &cif1);
	printf("\n seconda chiave di cifratura : ");
	scanf("%d", &cif2);
	printf("\n inserire la frase da cifrare : ");
		pf=fopen("output.txt","w");
		
		for(i=0;i<DIM;i++)
		{
			scanf("%c", &v[i]);
			if(i%2==0){
				v[i]=v[i]+cif1;
			}else {
				v[i]=v[i]+cif2;
			}
			fprintf(pf,"%c", v[i]);
		}
		fclose(pf);
}

void menu(){
	printf("\n Caesar double ASCII cypher\n Current version : v1.0 happy yuu\n author : Judjmentnaut\n\n\n Inserire le due chiavi di cifratura.\n Una volta inserite inserire una frase di massimo 100 caratteri.\n I caratteri in eccesso verranno scartati.\n il file di output di default e' [output.txt.]\n Se la frase non raggiunge i 20 caratteri e' consigliabile l'uso dell' invio come carattere nullo.\n La frase verrà cifrata usando un doppio cifratore (pari e dispari) di cesare basato sul formato ASCII.\n");
	// menu placeholder, verrà cambiato con l'implementazione delle librerie di cifrazione personalizzate
}
