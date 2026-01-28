#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nume;
    int note[3];
    float medie;
} Student;

float calculeazaMedie(int note[]) {
    if (note[0] < 5 || note[1] < 5 || note[2] < 5) return 0;
    return (note[0] + note[1] + note[2]) / 3.0f;
}
// func pt qsort alfabetic
int cmpNume(const void *a, const void *b) {
    return strcmp(((Student *)a)->nume, ((Student *)b)->nume);
}

// func pentru qsort
int cmpMedie(const void *a, const void *b) {
    float m1 = ((Student *)a)->medie;
    float m2 = ((Student *)b)->medie;
    if (m1 <= m2) return 1;
    if (m1 > m2) return -1;
    return 0;
}

int main() {
    int n;
    printf("Numar studenti: ");
    scanf("%d", &n);
    getchar(); // newline

    Student *grupa = (Student *)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        char tempNume[51];
        printf("nume %d: ", i + 1);
        fgets(tempNume, 51, stdin);
        tempNume[strcspn(tempNume, "\n")] = 0;

        grupa[i].nume = (char *)malloc((strlen(tempNume) + 1) * sizeof(char));
        strcpy(grupa[i].nume, tempNume);

        printf("note: ");
        scanf("%d %d %d", &grupa[i].note[0], &grupa[i].note[1], &grupa[i].note[2]);
        getchar();

        grupa[i].medie = calculeazaMedie(grupa[i].note);
    }

    // b
    for (int i = 0; i < n; i++)
        printf("medie %s: %.2f\n", grupa[i].nume, grupa[i].medie);

    qsort(grupa, n, sizeof(Student), cmpNume);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%s\n", grupa[i].nume);

    qsort(grupa, n, sizeof(Student), cmpMedie);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%s: %.2f\n", grupa[i].nume, grupa[i].medie);


    float maxMedie = grupa[0].medie;

    qsort(grupa, n, sizeof(Student), cmpNume);
    printf("\n\n\nmedii maxime: ", maxMedie);
    for (int i = 0; i < n; i++) {
        if (grupa[i].medie == maxMedie) printf("%s\n", grupa[i].nume);
    }

    for (int i = 0; i < n; i++) free(grupa[i].nume);
    free(grupa);

    return 0;
}