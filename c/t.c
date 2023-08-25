#include <stdio.h>
#include <string.h>

int main() {
    const char ipAddress[] = "192.168.1.1"; // Replace with your IP address
    int segments[4] = {0}; // Array to store the four integer segments
    int currentIndex = 0;  // Index to keep track of the current segment
    int currentNumber = 0; // Variable to construct the current segment's value

    for (int i = 0; ipAddress[i] != '\0'; i++) {
        if (ipAddress[i] == '.') {
            segments[currentIndex++] = currentNumber;
            currentNumber = 0;
        } else if (ipAddress[i] >= '0' && ipAddress[i] <= '9') {
            currentNumber = currentNumber * 10 + (ipAddress[i] - '0');
        } else {
            // Invalid character found, handle the error if needed
            printf("Invalid character in IP address.\n");
            return 1; // Exit with an error code
        }
    }

    // Add the last segment to the array
    segments[currentIndex] = currentNumber;

    // Check if the IP address has exactly 4 segments
    if (currentIndex != 3) {
        printf("Invalid IP address format.\n");
        return 1; // Exit with an error code
    }

    // Print the four segments
    for (int i = 0; i < 4; i++) {
        printf("Segment %d: %d\n", i + 1, segments[i]);
    }

    return 0;
}
