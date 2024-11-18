#include <stdio.h>
#include <time.h>

enum trafficLight {
    Red,        // 0
    Yellow,     // 1
    Green       // 2
};

int main() {
    enum trafficLight currentLight = Red; // Start with Red
    time_t startTime, currentTime;

    // Record the start time
    time(&startTime);

    while(1) {
        // Get the current time
        time(&currentTime);

        // Check if 30 seconds have passed
        if (difftime(currentTime, startTime) >= 30) {
            // Change the light every 30 seconds
            if (currentLight == Red) {
                currentLight = Green;
                printf("The traffic light is Green. Go!\n");
            }
            else if (currentLight == Green) {
                currentLight = Yellow;
                printf("The traffic light is Yellow. Prepare to stop.\n");
            }
            else {
                currentLight = Red;
                printf("The traffic light is Red. Stop!\n");
            }

            // Reset the start time to the current time after changing the light
            time(&startTime);
        }
    }

    return 0;
}
