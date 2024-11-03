#include <stdio.h>

int main() {
    int window = 0;
    printf("Enter window size : ");
    scanf("%d", &window);

    int sent = 0, ack = 0;

    while (ack < window) {
        for (int i = 0; i < window && sent < window; i++) {
            printf("Frame transmitted: %d\n", sent);
            sent++;
        }

        printf("Enter last received acknowledgment: ");
        scanf("%d", &ack);

        if (ack < window) {
            sent = ack;
        }
    }

    return 0;
}
