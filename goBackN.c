#include <stdio.h>

int main() {
    int window = 0;
    printf("Enter window size : ");
    scanf("%d", &window);

    int sent = 0, ack = 0, i = 0;

    while (1) {
        for (i = 0; i < window; i++) {
            printf("Frame transmitted: %d\n", sent);
            sent++;
            if (sent == window) {
                break;
            }
        }

        printf("Enter last received acknowledgment: ");
        scanf("%d", &ack);

        if (ack == window) {
            break;
        } else {
            sent = ack;
        }
    }

    return 0;
}
