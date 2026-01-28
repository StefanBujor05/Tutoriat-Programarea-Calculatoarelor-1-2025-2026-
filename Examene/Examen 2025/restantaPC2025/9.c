#include <stdio.h>

// 14-15 metode
int numaraCuvinte(char *linie) {
    int count = 0;
    int inCuvant = 0;
    
    for (int i = 0; linie[i] != '\0'; i++) {
        if (linie[i] != ' ') { // daca dam de spatiu, issapce(liniep[i])
            // alternativ, ne asiguram ca linie[i] este litera sau numar
            if (!inCuvant) {
                count++;
                inCuvant = 1;
            }
        } else {
            inCuvant = 0;
        }
    }
    return count;
}

int main() {
    char numeFisier[100];
    char linie[501];
    int maxCuvinte = -1, linieMax = 0, linieCurenta = 0;

    printf("nume fisier:  ");
    scanf("%s", numeFisier);

    FILE *fin = fopen(numeFisier, "r");
    if (!fin) {
        perror("coudlnt open file");
        return 1;
    }

    // 50 de metode
    while (fgets(linie, 501, fin)) {
        linieCurenta++;
        int nrCuvinte = numaraCuvinte(linie);
        
        if (nrCuvinte > maxCuvinte) {
            maxCuvinte = nrCuvinte;
            linieMax = linieCurenta;
        }
    }
    fclose(fin);

    FILE *fout = fopen("linie.out", "wb");
    if (!fout) {
        perror("couldnt create file");
        return 1;
    }

    fwrite(&linieMax, sizeof(int), 1, fout);
    fclose(fout);


    printf("%d %d", linieMax, maxCuvinte);

    return 0;
}