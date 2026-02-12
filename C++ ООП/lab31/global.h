#ifndef LIB_GLOBAL
#define LIB_GLOBAL
#include "lib_s.h"
void initLibrary(Library *lib);
void freeLibrary(Library *lib);
char* createString(const char *str);
void inputString(const char *prompt, char **str);
void addBook(Library *lib, const char *title, const char *author, int year, int pages);
void deleteBookByTitle(Library *lib, const char *title);
void searchBooks(Library *lib, const char *searchTerm, int searchByAuthor);
void printLibrary(const Library *lib);
void sortLibraryByYear(Library *lib);
void saveToFile(const Library *lib, const char *filename);
void loadFromFile(Library *lib, const char *filename);
void menu();
int inputInt(const char *prompt);
#endif