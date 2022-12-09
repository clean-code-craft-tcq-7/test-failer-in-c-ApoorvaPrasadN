#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName;
    if(cms <= 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms <= 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(38)=='S');
    printf("All is well (maybe!)\n");
    return 0;
}
