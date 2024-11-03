#include <stdio.h>

int main() {
    int n, f, frames[30], i;

    printf("Enter window size : ");
    scanf("%d", &n);
    printf("Enter number of frames to transmit: ");
    scanf("%d", &f);
    printf("Enter %d frames: \n", f);
    
    for (i = 1; i <= f; i++) {
        scanf("%d", &frames[i]);
    }

    printf("\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n");
    printf("After sending %d frames at each stage, sender waits for acknowledgement sent by the receiver\n\n", n);

    for (i = 1; i <= f; i++) {
        printf("%d ", frames[i]);
        
        if (i % n == 0) {
            printf("\nAcknowledgement of above frames sent is received by sender\n\n");
        }
    }

    if (f % n != 0) {
        printf("\nAcknowledgement of above frames sent is received by sender\n");
    }

    return 0;
}
