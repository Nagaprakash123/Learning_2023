#include <stdio.h>

int main() {
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    char ch;

    printf("Enter the path of the source file: ");
    scanf("%s", sourcePath);

    printf("Enter the path of the target file: ");
    scanf("%s", targetPath);

    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    targetFile = fopen(targetPath, "a");
    if (targetFile == NULL) {
        printf("Unable to create or open the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}