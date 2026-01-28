#include <stdio.h>

int main() {
    FILE *fin = fopen("litere.txt", "r");
    if (fin == NULL) {
        perror("file not opened");
        return 1;
    }
    char c1, c2;
    char text[1001];

    // citim literele
    fscanf(fin, "%c %c ", &c1, &c2);

    if (fgets(text, 1001, fin) != NULL) {

        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] == c1) {
                text[i] = c2;
            }
        }
        printf("%s", text);
    }

    fclose(fin);
    return 0;
}