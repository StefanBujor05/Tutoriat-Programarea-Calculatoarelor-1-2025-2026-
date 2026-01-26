#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char cuvant[21]; //cuvantul de la inceput
char linie[300]; //sir de caractere care memoreaza fiecare rand
char c; 
int charNo = -1;
int lineNo = 1;

int main(){

    FILE* ptr = fopen("text7.txt", "r");
    FILE* ptrOutput = fopen("linie.bin", "wb"); //in examen numele este linie.txt; este gresit
    //"wb" inseamna write binary
    
    //obtinem primul cuvant
    while( (c = fgetc(ptr)) != '\n'){
        charNo++;
        cuvant[charNo] = c; //cuvant = megadeth
    }

    // hai sa zicem ca avem un text.

    int wordCount = 0;
    int inWord = 0;
    //fegts pune o intreaga linie in sirul de caractere
    while( (fgets(linie, 300, ptr)) != NULL){
        wordCount =0;
        lineNo++;
        for(int i = 0; i < strlen(linie); i++){ //lucram astazi la info
            if(isspace(linie[i]) && inWord){
                inWord = 0;
                wordCount++;
            }
            else inWord = 1;
        }
        if(inWord)wordCount++;

        if(strstr(linie, cuvant) != NULL){ //strstr returneaza NULL daca cuvant NU apare in linie
            //afisez in linia de comanda, pentru a se verifica usor
            printf("linia: %d, numar cuvinte: %d\n", lineNo, wordCount);
            fprintf(ptrOutput, "%d %d \n", lineNo, wordCount );
        }   
    }
    
    return 0;
}