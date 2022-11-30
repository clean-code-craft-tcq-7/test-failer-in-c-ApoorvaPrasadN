#include <stdio.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            assert((((i*5 + j)== 1) || ((i*5 + j)== 6)|| ((i*5 + j)== 11)|| ((i*5 + j)== 16)|| ((i*5 + j)== 21)) && (minorColor[i] != minorColor[1]));
            assert((((i*5 + j)== 2) || ((i*5 + j)== 7)|| ((i*5 + j)== 12)|| ((i*5 + j)== 17)|| ((i*5 + j)== 22)) && (minorColor[i] != minorColor[2]));
            assert((((i*5 + j)== 3) || ((i*5 + j)== 8)|| ((i*5 + j)== 13)|| ((i*5 + j)== 18)|| ((i*5 + j)== 23)) && (minorColor[i] != minorColor[3]));
            assert((((i*5 + j)== 4) || ((i*5 + j)== 9)|| ((i*5 + j)== 14)|| ((i*5 + j)== 19)|| ((i*5 + j)== 24)) && (minorColor[i] != minorColor[4]));
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
