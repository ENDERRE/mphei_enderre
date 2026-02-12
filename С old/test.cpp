/*

#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    cout << "hello";
    keybd_event('f', 0,0,0);
    keybd_event('A', 0,0,0);
    keybd_event('F', 0,0,0);
    keybd_event('g', 0,0,0);
    keybd_event('K', 0,1,0);

    keybd_event('F', 0,KEYEVENTF_KEYUP,0);
    //system("PAUSE");
    //6gf7+ 6gf7+ 6gf7+ 6af7+ 6af7+ 6af7k 6фа7л 
    return 0;
}
*/



#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main()
{
    
    
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
    
    
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead("test.tif");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete api;
    delete [] outText;
    pixDestroy(&image);

    return 0;
}