#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    int sensorNo;
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
} LogEntry;

void extractData(LogEntry logEntries[], int *numEntries) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    char line[100];
    *numEntries = 0;

    // Read and process each line of the file
    while (fgets(line, sizeof(line), file) != NULL) {
        // Skip the header line
        if (strstr(line, "EntryNo") != NULL) {
            continue;
        }

        LogEntry entry;
        sscanf(line, "%d,%d,%f,%d,%d,%8s",
               &entry.entryNo, &entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.timestamp);

        logEntries[*numEntries] = entry;
        (*numEntries)++;

        if (*numEntries >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(file);
}

void displayData(const LogEntry logEntries[], int numEntries) {
    printf("%-8s %-9s %-12s %-8s %-6s %s\n", "EntryNo", "SensorNo", "Temperature", "Humidity", "Light", "Timestamp");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        LogEntry entry = logEntries[i];
        printf("%-8d %-9d %-12.1f %-8d %-6d %s\n",
               entry.entryNo, entry.sensorNo, entry.temperature,
               entry.humidity, entry.light, entry.timestamp);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractData(logEntries, &numEntries);

    displayData(logEntries, numEntries);

    return 0;
}