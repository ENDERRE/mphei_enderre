#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Структура для представления списка слов
typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

// Функция для добавления слова в список
void addWord(WordNode **head, char *word) {
    // Создание нового узла
    WordNode *newNode = (WordNode *)malloc(sizeof(WordNode));
    newNode->word = word;
    newNode->next = NULL;

    if (*head == NULL) {
        // Если список пуст, новый узел становится головным
        *head = newNode;
    } else {
        // Иначе, добавляем новый узел в конец списка
        WordNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Функция для группировки слов по одинаковым символам
void groupWords(WordNode *head) {
    WordNode *currNode = head;
    WordNode *prevNode = NULL;
    WordNode *groupTail = NULL;
    int fullGroupFlag = 0;

    while (currNode != NULL) {
        WordNode *nextNode = currNode->next;

        // Сравниваем символы первого слова с символами остальных слов
        int firstChar = tolower(currNode->word[0]);

        // Если текущее слово является началом новой группы
        if (prevNode == NULL || firstChar != tolower(prevNode->word[0])) {
            fullGroupFlag = 0; // Обнуляем флаг полной группы

            // Если предыдущая группа закончилась
            if (groupTail != NULL) {
                groupTail->next = nextNode;
                groupTail = NULL;
            }
        }

        // Если текущее слово относится к текущей группе
        if (tolower(currNode->word[0]) == firstChar) {
            if (!fullGroupFlag) {
                // Выводим слово на экран, если группа не полная
                printf("%s ", currNode->word);
            }
            prevNode = currNode;
        } else {
            // Если текущее слово не относится к текущей группе
            if (groupTail == NULL) {
                // Запоминаем последнее слово текущей группы
                groupTail = prevNode;
                fullGroupFlag = 1; // Группа полная
            }
            // Выводим слово на экран
            printf("%s ", currNode->word);
            prevNode = currNode;
        }

        currNode = nextNode;
    }
    printf("\n");
}

int main() {
    WordNode *head = NULL;

    while (1) {
        char c = getchar();
        if (c == '\n' || c == EOF) {
            // Если строка закончилась, группируем слова и выводим результат на экран
            groupWords(head);
            
            // Очищаем список
            while (head != NULL) {
                WordNode *temp = head;
                head = head->next;
                free(temp);
            }
            break;
        } else if (isspace(c) && head != NULL) {
            // Если пробел найден, добавляем слово в список
            addWord(&head, NULL);
        } else {
            // Иначе, добавляем символ в текущее слово
            WordNode *tail = head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            int len = (tail->word != NULL) ? strlen(tail->word) : 0; // Длина текущего слова
            tail->word = (char *)realloc(tail->word, (len + 2) * sizeof(char));
            tail->word[len] = c;
            tail->word[len + 1] = '\0';
        }
    }

    return 0;
}
