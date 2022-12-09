#include <stdio.h>
#include <assert.h>
    
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"}; 

void getformat_Colormap();
const int total_color = 25;
struct colorMap
{
    int pairNumber;
    char *majorColor;
    char *minorColor;
};
struct colorMap formatted_ColorMap[total_color];
int printColorMap() {

    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, formatted_ColorMap[i*5+j].majorColor, formatted_ColorMap[i*5+j].minorColor);
        }
    }
    return i * j;
}

void getformat_Colormap()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            
           formatted_ColorMap[i*5+j].pairNumber = i * 5 + j;
           formatted_ColorMap[i*5+j].majorColor = (char *)majorColor[i];
           formatted_ColorMap[i*5+j].minorColor = (char *)minorColor[j];
        }
    }
          
}

int main() {
    getformat_Colormap();
    int result =printColorMap();
    for(int i =0; i<=total_color;i++)
    {
    assert(formatted_ColorMap[i].minorColor == minorColor[i]);
    }
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
