#include <stdio.h>
#define DIM 20

void import(char v[]);

void cifrazione(char v[], int cif1, int cif2);

void insman(char v[]);

int menu();

void decifrazione(char v[], int cif1, int cif2);


int main(){
	int cif1, cif2, scelta;
	char v[DIM];
	
	printf("\n Caesar double ASCII cypher\n Current version : v1.4 **********\n author : Judjmentnaut\n\n\n Inserire le due chiavi di cifratura.\n Una volta inserite inserire una frase di massimo 100 caratteri.\n I caratteri in eccesso verranno scartati.\n il file di output di default e' [output.txt.]\n Se la frase non raggiunge i 20 caratteri e' consigliabile l'uso degli spazi come carattere nullo.\n La frase verra' cifrata usando un doppio cifratore (pari e dispari) di cesare basato sul formato ASCII.\n");
	printf("\n prima chiave di cifratura : ");
	scanf("%d", &cif1);
	printf("\n seconda chiave di cifratura : ");
	scanf("%d", &cif2);
	scelta=menu();
	
	switch(scelta){
		case 1:{
			import(v);
			cifrazione(v, cif1, cif2);
			break;
		}
		
		case 2:{
			insman(v);
			cifrazione(v, cif1, cif2);
			break;
		}
	}
	
//	import(v);
//	cifrazione(v, cif1, cif2);
	decifrazione(v, cif1, cif2);
	printf("\n\nl'operazione e' finita\nil file output contiene ora la frase cifrata\nil file out_def contine una copia della frase inserita");
}


void insman(char v[]){
	int i;
	
	for(i=0;i<DIM;i++){
		scanf("%c", v[i]);
	}
}


void cifrazione(char v[],int cif1,int cif2){
	int i;
	
	FILE *pf;
	pf=fopen("output.txt","w");
		
		for(i=0;i<DIM;i++)
		{
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



void decifrazione(char v[], int cif1, int cif2){
	int i;
	FILE *pf;
	
	pf=fopen("out_def.txt","w");
	
	for(i=0;i<DIM;i++)
	
	{
		if(i%2==0){
				v[i]=v[i]-cif1;
			}else {
				v[i]=v[i]-cif2;
			}
		fprintf(pf,"%c", v[i]);
	}
}



int menu(){
	int s;
	
	printf("\n\n seleziona la modalita' di inserimento: \n\n\t 1- inserimento da file\n\n\t 2- inerimento manuale");
	scanf("%d", s);
	
	return s;
}
