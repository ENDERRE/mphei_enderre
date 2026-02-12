#include <stdio.h>
#include <string.h>

// Определение структуры данных
struct Event {
    int id;
    int level;
    char text[100];
};

// Запись структуры в бинарный файл
void writeEventToFile(struct Event event, const char* filename) {
    FILE* file = fopen(filename, "ab");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return;
    }

    fwrite(&event, sizeof(struct Event), 1, file);
    fclose(file);
}

// Чтение структуры из бинарного файла
void readEventFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return;
    }

    struct Event event;
    while (fread(&event, sizeof(struct Event), 1, file) == 1) {
        printf("Идентификатор: %d\n", event.id);
        printf("Уровень важности: %d\n", event.level);
        printf("Текст: %s\n\n", event.text);
    }

    fclose(file);
}

int main() {
    // Пример использования
    struct Event event1;
    event1.id = 1;
    event1.level = 3;
    strcpy(event1.text, "Пример события 1");

    struct Event event2;
    event2.id = 2;
    event2.level = 1;
    strcpy(event2.text, "Пример события 2");

    writeEventToFile(event1, "events.bin");
    writeEventToFile(event2, "events.bin");
    
    readEventFromFile("events.bin");

    return 0;
}