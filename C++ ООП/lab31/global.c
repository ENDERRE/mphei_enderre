#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib_s.h"
#include "global.h"
#define MAX_LINE_LENGTH 256

void initLibrary(Library *lib) {
    lib->head = NULL;
    lib->tail = NULL;
}

void freeLibrary(Library *lib) {
    Node *current = lib->head;
    while (current) {
        Node *next = current->next;
        free(current->data.title);
        free(current->data.author);
        free(current);
        current = next;
    }
    lib->head = NULL;
    lib->tail = NULL;
}


char* createString(const char *str) {
    char *res = malloc(strlen(str) + 1);
    if (res) {
        strcpy(res, str);
    }
    return res;
}


void inputString(const char *prompt, char **str) {
    char buffer[MAX_LINE_LENGTH];
    printf("%s", prompt);
    if (fgets(buffer, MAX_LINE_LENGTH, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
        *str = createString(buffer);
    }
}


void addBook(Library *lib, const char *title, const char *author, int year, int pages) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    newNode->data.title = createString(title);
    newNode->data.author = createString(author);
    newNode->data.year = year;
    newNode->data.pages = pages;
    newNode->prev = lib->tail;
    newNode->next = NULL;

    if (lib->tail) {
        lib->tail->next = newNode;
    } else {
        lib->head = newNode;
    }
    lib->tail = newNode;
}


void deleteBookByTitle(Library *lib, const char *title) {
    Node *current = lib->head;
    while (current) {
        if (strcmp(current->data.title, title) == 0) {
            if (current->prev)
                current->prev->next = current->next;
            else
                lib->head = current->next;
            if (current->next)
                current->next->prev = current->prev;
            if (current == lib->tail)
                lib->tail = current->prev;

            free(current->data.title);
            free(current->data.author);
            free(current);
            printf("Книга \"%s\" удалена.\n", title);
            return;
        }
        current = current->next;
    }
    printf("Книга с названием \"%s\" не найдена.\n", title);
}


void searchBooks(Library *lib, const char *searchTerm, int searchByAuthor) {
    Node *current = lib->head;
    int found = 0;
    while (current) {
        if (searchByAuthor) {
            if (strcmp(current->data.author, searchTerm) == 0) {
                printf("Название: %s | Автор: %s | Год: %d | Страниц: %d\n",
                       current->data.title, current->data.author, current->data.year, current->data.pages);
                found = 1;
            }
        } else {
            if (strcmp(current->data.title, searchTerm) == 0) {
                printf("Название: %s | Автор: %s | Год: %d | Страниц: %d\n",
                       current->data.title, current->data.author, current->data.year, current->data.pages);
                found = 1;
            }
        }
        current = current->next;
    }
    if (!found) {
        printf("Ничего не найдено.\n");
    }
}


void printLibrary(const Library *lib) {
    Node *current = lib->head;
    if (!current) {
        printf("Библиотека пуста.\n");
        return;
    }
    printf("Список книг:\n");
    while (current) {
        printf("Название: %s | Автор: %s | Год: %d | Страниц: %d\n",
               current->data.title, current->data.author, current->data.year, current->data.pages);
        current = current->next;
    }
}


void sortLibraryByYear(Library *lib) {
    if (!lib->head || !lib->head->next)
        return;

    int swapped;
    do {
        swapped = 0;
        Node *current = lib->head;
        while (current->next) {
            if (current->data.year > current->next->data.year) {

                Book temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}


void saveToFile(const Library *lib, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Ошибка открытия файла для записи.\n");
        return;
    }
    Node *current = lib->head;
    while (current) {
        fprintf(f, "%s\n%s\n%d\n%d\n",
                current->data.title,
                current->data.author,
                current->data.year,
                current->data.pages);
        current = current->next;
    }
    fclose(f);
    printf("Данные успешно сохранены в файл.\n");
}

void loadFromFile(Library *lib, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Ошибка открытия файла для чтения.\n");
        return;
    }

    freeLibrary(lib);

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, f)) {
        buffer[strcspn(buffer, "\n")] = 0;
        char *title = createString(buffer);

        if (!fgets(buffer, MAX_LINE_LENGTH, f))
            break;
        buffer[strcspn(buffer, "\n")] = 0;
        char *author = createString(buffer);

        int year, pages;
        if (!fgets(buffer, MAX_LINE_LENGTH, f))
            break;
        sscanf(buffer, "%d", &year);

        if (!fgets(buffer, MAX_LINE_LENGTH, f))
            break;
        sscanf(buffer, "%d", &pages);

        addBook(lib, title, author, year, pages);

        free(title);
        free(author);
    }

    fclose(f);
    printf("Данные успешно загружены из файла.\n");
}

void menu() {
    printf("\nВыберите действие:\n");
    printf("1. Добавить книгу\n");
    printf("2. Удалить книгу по названию\n");
    printf("3. Поиск по автору\n");
    printf("4. Поиск по названию\n");
    printf("5. Вывести все книги\n");
    printf("6. Отсортировать по году\n");
    printf("7. Сохранить в файл\n");
    printf("8. Загрузить из файла\n");
    printf("0. Выход\n");
    printf("Ваш выбор: ");
}

int inputInt(const char *prompt) {
    int num;
    printf("%s", prompt);
    while (scanf("%d", &num) != 1) {
        printf("Некорректный ввод. Попробуйте снова: ");
        while (getchar() != '\n'); 
    }
    while (getchar() != '\n'); 
}
