#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Converts mm.ss.ss to total seconds
double convertToSeconds(int minutes, double seconds) {
    return (minutes * 60) + seconds;
}

int main() {
    int distance;
    int splitInterval;
    int minutes;
    float seconds;
    char input[10];  // Array to store the user input (e.g., "1.20.33.68")
    double splits1[60]; // Array to store split times (max 60 splits for 1500m with 25m splits)
    double splits2[60];
    char originalTimes[2][60][10];

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

    //###---------event 1--------
    
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
        strcpy_s(originalTimes[0][i], 10, input);
        // Calculate total time in seconds
        splits1[i] = convertToSeconds(minutes, seconds);
    }

    //###---------event 2--------

    // Input split times
    puts("----- Event 2 -----");
    for (int i = 0; i < numSplits; i++) {
        printf("Please enter your time for split %d (mm.ss.ss): ", i + 1);

        // Read input time as a string
        if (scanf_s("%19s", input, (unsigned)_countof(input)) != 1) {
            printf("Invalid input format.\n");
            continue; // Skip the invalid input and ask for the split again
        }

        // Parse the time string using sscanf
        if (sscanf_s(input, "%d.%f", &minutes, &seconds) != 2) {
            printf("Invalid input format.\n");
            continue; // Skip the invalid input and ask for the split again
        }

        strcpy_s(originalTimes[1][i], 10, input); // Copy input to Event 2 array

        // Calculate total time in seconds
        splits2[i] = convertToSeconds(minutes, seconds);
    }

    // Display split times
    puts("\n---- Split Times ----");
    printf("\n---- Event 1 ----\t\t---- Event 2 ----\n");
    for (int i = 0; i < numSplits; i++) {
        printf("Split %d: %.2f\t\tSplit %d: %.2f\n", i + 1, splits1[i], i + 1, splits2[i]);

        // Print the difference between consecutive splits (skip for the last split)
        if (i < numSplits - 1) {
            printf("\t\t+%.2f seconds\t\t\t+%.2f seconds\n", splits1[i + 1] - splits1[i], splits2[i + 1] - splits2[i]);
        }
    }

    return 0;
}
