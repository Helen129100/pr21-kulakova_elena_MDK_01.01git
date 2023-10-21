#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100]; // буфер для чтения данных из файла

    // Открытие файла для чтения в бинарном режиме
    file = fopen("file.bin", "rb");

    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    // Чтение данных из файла
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer), file);

    if (bytesRead > 0) {
        printf("Прочитано %zu байт из файла.\n", bytesRead);
    } else {
        printf("Ошибка чтения файла.\n");
    }

    // Закрытие файла
    fclose(file);

    return 0;
}
