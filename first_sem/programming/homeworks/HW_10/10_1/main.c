#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Rus");
    char *str = (char *) malloc(1000);
    gets(str);
    int min_word_size = 100000000;
    char* min_word = (char *) malloc(1000);
    strcat(str,"\0");
    for (int i = 0; i < strlen(str); i++){
        int word_size = 0;

        char *last_word = (char*) malloc(1000);
        for(;i< strlen(str);i++) {

            if (!isspace(str[i]) || ispunct(str[i])) {
                last_word[word_size] = str[i];
                word_size++;
            } else {
                last_word[word_size+1] = '\0';
                break;
            }
        }
        if (min_word_size >= word_size) {
            min_word_size = word_size;
            free(min_word);
            min_word = NULL;
            min_word = malloc(word_size+1);
        }
            strcpy(min_word, last_word);
        free(last_word);
        last_word = NULL;
    }


    printf("%s", min_word);
    return 0;
}
