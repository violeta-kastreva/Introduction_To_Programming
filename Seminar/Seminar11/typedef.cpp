#include <iostream>

typedef unsigned char byte;

typedef byte Pixel[3];
typedef Pixel Picture[1024][1024];

typedef struct {
    int a;
} Foo;

int main() {
    Picture p;

    p[10][30][0];

    struct {
        int a;
    } anonStructVar;
    anonStructVar.a;
}