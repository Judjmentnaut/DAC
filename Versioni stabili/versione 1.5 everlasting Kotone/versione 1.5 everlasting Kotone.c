#include <stdio.h>
#define DIM 20

void import(char v[]);

void cifrazione(char v[], int cif1, int cif2);

void menu();

//void cifratura(char v[], int cif1, int cif2);

void decifrazione(char v[], int cif1, int cif2);

int main(){
	int i, cont=0, cif1, cif2;
	char v[DIM];
	char temp;
	FILE *pf;
	
	menu();
	printf("\n prima chiave di cifratura : ");
	scanf("%d", &cif1);
	printf("\n seconda chiave di cifratura : ");
	scanf("%d", &cif2);
//	cifratura(v, cif1, cif2);			OBSOLETA
	import(v);
	cifrazione(v, cif1, cif2);
	decifrazione(v, cif1, cif2);
	printf("\n\nl'operazione e' finita\nil file output contiene ora la frase cifrata\nil file out_def contine una copia della frase inserita");
}

void cifrazione(char v[],int cif1,int cif2){
	int i;
	
	FILE *pf;
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


void import(char v[]){
	int i;
	FILE *pf;
	
	printf("\n acquisizione in corso : ");
		pf=fopen("inport.txt","r");
		
		for(i=0;i<DIM;i++)
		{
			fscanf(pf,"%c", &v[i]);
			printf("%c", v[i]);
		}
		fclose(pf);
}

void cifratura(char v[], int cif1, int cif2){
	int i;
	char s[DIM];
	//char temp;
	FILE *pf;
	
	printf("\n inserire la frase da cifrare : ");
		pf=fopen("output.txt","w");
		
		for(i=0;i<DIM;i++)
		{
			scanf("%c", &s[i]);
			if(i%2==0){
				s[i]=s[i]+cif1;
			}else {
				s[i]=s[i]+cif2;
			}
			fprintf(pf,"%c", s[i]);
		}
		fclose(pf);
}

void decifrazione(char v[], int cif1, int cif2){
	int i;
	char s[DIM];
	FILE *pf;
	
	pf=fopen("out_def.txt","w");
	
	for(i=0;i<DIM;i++)
	
	{
		if(i%2==0){
				s[i]=s[i]-cif1;
			}else {
				s[i]=s[i]-cif2;
			}
		fprintf(pf,"%c", v[i]);
	}
}

void menu(){
	printf("\n Caesar double ASCII cypher\n Current version : v1.4 **********\n author : Judjmentnaut\n\n\n Inserire le due chiavi di cifratura.\n Una volta inserite inserire una frase di massimo 100 caratteri.\n I caratteri in eccesso verranno scartati.\n il file di output di default e' [output.txt.]\n Se la frase non raggiunge i 20 caratteri e' consigliabile l'uso dell' invio come carattere nullo.\n La frase verra' cifrata usando un doppio cifratore (pari e dispari) di cesare basato sul formato ASCII.\n");
	// menu placeholder, verrà cambiato con l'implementazione delle librerie di cifrazione personalizzate
}
