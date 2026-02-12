#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *process(char *text){
    if (text == NULL){
        return NULL;
    }
    int len = strlen(text);
    char *result = malloc(len);
    char *sep = " ";
    char *str = strdup(text);
    int k = 0;
    while (str[0] == ' '){
        for (int i = 0; i < len-k-1; ++i){
            str[i] = str[i + 1];
        }
        k += 1;
        str[len-k] = '\0';
        str = realloc(str, (len-k)*sizeof(char));
    }
    int l_f = 0;
    char *word1 = strtok(str, sep);
    char *word2 = strtok(NULL, sep);
    while (word2 != NULL){
        if (strcmp(word1, word2) != 0){
            int len_word = strlen(word2);
            memcpy(result + l_f, word2, len_word);
            l_f += len_word;
            result[l_f] = ' ';
            l_f += 1;
        }
        word2 = strtok(NULL, sep);
    }
    result[l_f-1] = '\0';
    result = realloc(result, l_f*sizeof(char));
    free(word1);
    free(word2);
    return result;
}

int main(){
    char *text = calloc(300, sizeof(char));
    strcpy(text, "      Mama papa Mama    Ada Sasha  Mama Nina Toma");
    char *text_pro = calloc(100, sizeof(char));
    text_pro = process(text);
    printf("%s\n", text_pro);
    free(text);
    free(text_pro);
}
