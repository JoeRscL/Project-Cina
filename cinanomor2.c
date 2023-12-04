#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 6
#define WORD_LENGTH 5

char *chooseWord();
void displayWord(char *word, char *guessed);

int main() {
    srand(time(NULL));

    char *wordToGuess = chooseWord();
    char guessedWord[WORD_LENGTH + 1];
    memset(guessedWord, '_', WORD_LENGTH);
    guessedWord[WORD_LENGTH] = '\0';

    int tries = 0;

    printf("Selamat datang di Wordle!\n");

    while (tries < MAX_TRIES) {
        displayWord(wordToGuess, guessedWord);

        char guess;
        printf("Tebak huruf: ");
        scanf(" %c", &guess);

        int found = 0;

        for (int i = 0; i < WORD_LENGTH; i++) {
            if (wordToGuess[i] == guess) {
                guessedWord[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            tries++;
            printf("Salah! Sisa kesempatan: %d\n", MAX_TRIES - tries);
        } else {
            printf("Benar!\n");
        }

        if (strcmp(wordToGuess, guessedWord) == 0) {
            printf("Selamat, Anda menang!\n");
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printf("Maaf, Anda kalah. Kata yang benar: %s\n", wordToGuess);
    }

    free(wordToGuess);

    return 0;
}

char *chooseWord() {
    char *words[] = {"apple", "table", "chair", "snake", "grape"};
    int index = rand() % (sizeof(words) / sizeof(words[0]));
    
    char *word = malloc(strlen(words[index]) + 1);
    strcpy(word, words[index]);

    return word;
}

void displayWord(char *word, char *guessed) {
    printf("Kata: ");
    for (int i = 0; i < WORD_LENGTH; i++) {
        printf("%c ", guessed[i]);
    }
    printf("\n");
}

