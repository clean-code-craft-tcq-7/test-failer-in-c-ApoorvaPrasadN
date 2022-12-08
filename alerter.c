#include <stdio.h>
#include <assert.h>
#define SW_TEST 0
int alertFailureCount = 0;
#if(SW_TEST == 1)
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius == 200)// Return 200 for ok
        return 200;
    else
        return 500;// Return 500 for not-ok 
    // stub always succeeds and returns 200
    return 200;
}
#endif

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    #if(SW_TEST == 1)
    int returnCode = networkAlertStub(celcius);
    #else
    int returnCode = celcius;
    #endif
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    assert(alertFailureCount=0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
