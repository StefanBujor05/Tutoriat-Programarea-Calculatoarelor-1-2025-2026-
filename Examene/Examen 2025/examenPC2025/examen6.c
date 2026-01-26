#include<stdio.h>
#include<stdlib.h> //pentru qsort
#include<string.h>

//a)
typedef struct{
    char nume[35];
    float note[5];
    int credite;
    char situatie[20];
}Student;

//b)
void getCredite(int n, Student t[]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j<5; j++)
            if(t[i].note[j] >= 5)t[i].credite+=5;

        if(t[i].credite == 25)
            strcpy(t[i].situatie, "integralist"); //credite = 25 => toate examenele trecute
        else strcpy(t[i].situatie, "restantier");
    }
}

//c)
int compare(const void* a, const void* b){
    Student* aa = (Student*)a;
    Student* bb = (Student*)b;

    return (bb->credite - aa->credite);
}


int main(){
    
    int n;
    Student* t = (Student*)malloc(n*sizeof(Student));

    strcpy(t[0].nume, "Stefan");
    t[0].note[0] = 3;
    t[0].note[1] = 6;
    t[0].note[2] = 7;
    t[0].note[3] = 8;
    t[0].note[4] = 10; 
    strcpy(t[1].nume, "Andreea");
    t[1].note[0] = 10;
    t[1].note[1] = 10;
    t[1].note[2] = 10;
    t[1].note[3] = 10;
    t[1].note[4] = 10;
    getCredite(2, t);

    qsort(t, 2, sizeof(Student), compare);
    for(int i = 0; i< 2; i++)
        printf("%s ", t[i].nume);
    return 0;
}