#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WINDOW_SIZE 4     
#define TOTAL_FRAMES 10   

void sender();
bool receiver(int frame);

int main() {
    srand(time(0));  
    printf("Starting Go-Back-N Protocol Simulation...\n\n");
    sender();
    printf("\nSimulation complete.\n");
    return 0;
}

void sender() {
    int next_frame_to_send = 0;
    int ack_received = -1;

    while (ack_received < TOTAL_FRAMES - 1) {
        for (int i = next_frame_to_send; i < next_frame_to_send + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            printf("Sender: Sending Frame %d\n", i);

            if (receiver(i)) {
                printf("Receiver: Frame %d acknowledged\n", i);
                ack_received = i;
                next_frame_to_send = i + 1;
            } else {
                printf("Receiver: Frame %d lost, resending from Frame %d\n", i, next_frame_to_send);
                break;
            }
        }
        usleep(500000);
    }
}

bool receiver(int frame) {
    return rand() % 5 != 0;  // 20% chance of frame loss
}
