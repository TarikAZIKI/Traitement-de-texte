#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void projet()
{
	printf("		########################################################################################\n");
	printf("					- | BIENVENUE DANS LE MINI PROJET | - \n");
	printf("						- | MINI PROJET | - \n");
	printf("					- BOUBNANE HAMZA | AZIKI TARIK  - \n");
	printf("		########################################################################################\n\n\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n\n\n\n");
	sleep(1);
	system("CLS");
	
		
}

int ComptMot(char rech[30],char fichier[30])
{
		int choice;
		FILE *f,*ftest;
		f = fopen(fichier,"r");
		char c,m[100];
		int i=0;
		while((c=fgetc(f)) != EOF)
		{
			m[i]=c;
			i++; 
		}
		i = 0;
		int occ = 0,nb=0, j=0;
		while (i<strlen(m) && j<strlen(rech))
		{
			if(m[i]==rech[j])
			{
				occ++;
				i++;
				j++;
			}
			else
			{
				j=0;
				i++;
			}
			if(occ==strlen(rech))
			{
				nb++;
				j=0;
				occ=0;
			}
		}  
		
		return nb;	
		fclose(f);
		
	}

void MajtoMin(char fichier[30])
{
	
		int choice,a,i=0;
		FILE *f,*ftest;
		f = fopen(fichier,"r");
   	    ftest = fopen("test.txt","w");
   	    
		char c,m[100];
		while((c=fgetc(f)) != EOF)
		{
			m[i]=tolower(c);
			fprintf(ftest,"%c",m[i]);
			i++;
		}

		fclose(f);
		fclose(ftest);
		remove(fichier);
     	rename("test.txt",fichier);
     	
		printf("\n\n######################################################\n");
     	printf("# Le texte a ete converti en miniscule avec succes ! #");
		printf("\n######################################################");     
}

void MintoMaj(char fichier[30])
{
	
		int choice,a,i=0;
		FILE *f,*ftest;
		f = fopen(fichier,"r");
   	    ftest = fopen("test.txt","w");

		char c,m[100];
		while((c=fgetc(f)) != EOF)
		{
			m[i]=toupper(c);
			fprintf(ftest,"%c",m[i]);
			i++;
		}
		fclose(f);
		fclose(ftest);
		remove(fichier);
     	rename("test.txt",fichier);
     	
		printf("\n######################################################\n");
     	printf("# Le texte a ete converti en majuscule avec succes ! #");
		printf("\n######################################################");     	
}

void SuppAppCara(char e,char fichier[30])
{
		int choice,c,i;
		FILE *f,*ftest;
		f = fopen(fichier,"r");
   	    ftest = fopen("test.txt","w");

		while((c=fgetc(f)) != EOF)
		{

			if(c!=e)
			{
				fprintf(ftest,"%c",c);
			}
		}
		fclose(f);
		fclose(ftest);
		remove(fichier);
     	rename("test.txt",fichier);
     	
		printf("\n###############################################\n");
     	printf("# Le caractere %c a ete supprime avec succes ! #",e);
		printf("\n###############################################");
		
     	
}


int main()
{
		projet();
		int choice;
		char e,f[30],mot[30];

		do{
menu :			printf("\t\t			------------------------------------------\n");
			printf("\t\t			| - [1]  - Supprimer un caractere     	-|\n");
			printf("\t\t			| - [2]  - Convertir de MIN a MAJ     	-|\n");
			printf("\t\t			| - [3]  - Convertir de MAJ a MIN     	-|\n");
			printf("\t\t			| - [4]  - Nombre d'occurence d'un mot  -|\n");
			printf("\t\t			------------------------------------------\n");
			printf("\t\t			| - [5]  - Quitter	  	      	-|\n");
			printf("\t\t			------------------------------------------\n");

			printf("\t\t\t\t\t\t - Votre choix : ");
	
			scanf("%d",&choice);
			if(choice < 1 || choice > 5)
				printf("				\n !! Choix invalide !!"); sleep(2); system("CLS");
		}while(choice < 1 || choice > 5);
		
		switch(choice)
		{
			
			case 1:
				printf("########################################################################################################################");
				printf("- | Entrer le fichier souhaite : ");
				fflush(stdin);
				gets(f);
				printf("- | Entrer le caractere : ");
				fflush(stdin);
				scanf("%c",&e);
				SuppAppCara(e,f);
				sleep(1);
				system("cls");
				goto menu;
				break;
			
			case 2:
				printf("########################################################################################################################");
				printf("- | Entrer le fichier souhaite : ");
				fflush(stdin);
				gets(f);
				MintoMaj(f);
				sleep(1);
				goto menu;
				system("cls");
				break;
			case 3:
				printf("########################################################################################################################");
				printf("- | Entrer le fichier souhaite : ");
				fflush(stdin);
				gets(f);
				MajtoMin(f);
				sleep(1);
				system("cls");		
				goto menu;
				break;
			case 4:
				printf("########################################################################################################################");
				printf("- | Entrer le fichier souhaite : ");
				fflush(stdin);
				gets(f);
				printf("- | Entrer le mot recherche : ");
				scanf("%s",&mot);
				int nb=ComptMot(mot,f);
				printf("\n##################################\n");
     			printf("# Le mot %s est repete %d fois ! #",mot,nb);
				printf("\n##################################");
				sleep(1);
				system("cls");				
				goto menu;
				break;
			case 5:
				printf("fin du programme ");
				break;
			
		}
		

		
		/* ####################################################################################################################################################
		 ####################################################################################################################################################*/
		 
		 

}



