/* ѕроверить, упор€дочен ли текст по длине слов. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define SENTENCE 1000
#define WORD 50

char* get_word(char* str, char* word) {
    int i = 0;
    while (isspace(*str))
        str++;
    while (!isspace(*str) && *str != '\0')
        word[i++] = *str++;
    word[i] = '\0';
    return str;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char* punctuation_marks = " .,!?;:-<>[]{}()";

    while(1){
        char text[SENTENCE];
        fgets(text, SENTENCE, stdin);

        char* main = text;
        char word1[WORD];
        char word1_clean[WORD];
        while (*main) {
            main = get_word(main, word1);
            strcpy(word1_clean, word1);
            strcat(word1, " ");
            while (strchr(punctuation_marks, word1_clean[strlen(word1_clean) - 1]))
                word1_clean[strlen(word1_clean) - 1] = '\0';

            if (strlen(word1_clean) > 0) {
                char* main2 = main;
                char word2[WORD];
                char word2_clean[WORD];

                while (*main2) {
                    main2 = get_word(main2, word2);
                    strcpy(word2_clean, word2);
                    strcat(word2, " ");
                    while (strchr(punctuation_marks, word2_clean[strlen(word2_clean) - 1]))
                        word2_clean[strlen(word2_clean) - 1] = '\0';

                    if (strlen(word2_clean) > 0) {
                        if (strlen(word1_clean) > strlen(word2_clean)) {
                            printf("-The sentence is not ordered in ascending order.");
                        }
                        break;
                    }
                }
            }
        }
        printf("+The sentence is ordered in ascending order.\n");
    }

    return 0;
}