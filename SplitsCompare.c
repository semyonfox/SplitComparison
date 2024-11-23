#include <stdio.h>
#include <stdlib.h>

// Converts mm.ss.ss to total seconds
double convertToSeconds(int minutes, double seconds) {
    return (minutes * 60) + seconds;
}

int main() {
    int distance;
    int splitInterval;
    int minutes;
    float seconds;
    char input[20];  // Array to store the user input (e.g., "1.20.33.68")

    // Introductory messages
    puts("-------- Comparing Splits ---------");
    puts("------ Created by Semyon Fox ------");

    // Get event distance
    puts("\nEnter event distance (m): ");
    if (scanf_s("%d", &distance) != 1) {
        printf("Invalid input for distance.\n");
        return 1;
    }

    // Get split interval
    puts("\nEnter split interval (e.g., 50 for splits every 50m): ");
    if (scanf_s("%d", &splitInterval) != 1 || splitInterval <= 0) {
        printf("Invalid input for split interval.\n");
        return 1;
    }

    // Calculate number of splits
    int numSplits = (distance / splitInterval);
    double splits[60]; // Array to store split times (max 60 splits for 1500m with 25m splits)

    // Input split times
    puts("----- Event 1 -----");
    for (int i = 0; i < numSplits; i++) {
        printf("Please enter your time for split %d (mm.ss.ss): ", i + 1);

        // Read input time as a string
        if (scanf_s("%19s", input, (unsigned)_countof(input)) != 1) {
            printf("Invalid input format.\n");
            continue; // Skip the invalid input and ask for the split again
        }

        // Parse the time string using sscanf
        if (sscanf_s(input, "%d.%f",&minutes, &seconds) != 2) {
            printf("Invalid input format.\n");
            continue; // Skip the invalid input and ask for the split again
        }

        // Calculate total time in seconds
        splits[i] = convertToSeconds(minutes, seconds);
    }

    // Display split times
    puts("\n---- Split Times ----");
    for (int i = 0; i < numSplits; i++) {
        printf("Split %d: %.2f seconds\n", i + 1, splits[i]);

        // Print the difference between consecutive splits (skip for the last split)
        if (i < numSplits - 1) { // Only calculate the difference if it's not the last split
            printf("\t\t+%.2f seconds\n", splits[i + 1] - splits[i]);
        }
    }

    return 0;
}
