#include "stdafx.h"
#include <baseapi.h> // подключаем заголовочные файлы библиотек, связанных с tesseract
#include <allheaders.h>
#include <iostream> // подключаем функции ввода/вывода

using namespace std; // эта строка нужна чтобы не писать std

int _tmain(int argc, _TCHAR* argv[])
{
    FILE* f; // объявляем файловую переменную
    tesseract::TessBaseAPI* myOCR =
        new tesseract::TessBaseAPI();
    myOCR->Init(NULL, "eng"); //будем распознавать тексты на английском языке
    Pix* pix = pixRead("c:\\1.jpg"); // загружаем картинку с текстом с диска 

    myOCR->SetImage(pix);

    // вывод результатов распознавания текста в файл
    f = fopen("text.txt", "w");
    fprintf(f, "OCR output:\n\n");
    fprintf(f, myOCR->GetUTF8Text());
}