#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void copyFile(FILE *sourceFile, FILE *targetFile, char *option) {
    char ch;

    if (strcmp(option, "-u") == 0) {
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(toupper(ch), targetFile);
        }
    } else if (strcmp(option, "-L") == 0) {
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(tolower(ch), targetFile);
        }
    } else if (strcmp(option, "-s") == 0) {
        int sentenceStart = 1;

        while ((ch = fgetc(sourceFile)) != EOF) {
            if (sentenceStart && isalpha(ch)) {
                fputc(toupper(ch), targetFile);
                sentenceStart = 0;
            } else {
                fputc(tolower(ch), targetFile);
            }

            if (ch == '.' || ch == '!' || ch == '?') {
                sentenceStart = 1;
            }
        }
    } else {
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, targetFile);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    char option[3];

    if (argc < 2) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./file_copy source_file target_file [option]\n");
        return 1;
    }

    strcpy(sourcePath, argv[1]);
    strcpy(targetPath, argv[2]);

    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (argc >= 4) {
        strcpy(option, argv[3]);
        copyFile(sourceFile, targetFile, option);
    } else {
        copyFile(sourceFile, targetFile, "");
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}