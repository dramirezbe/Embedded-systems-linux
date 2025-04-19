#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <linux/limits.h>

int main() {
    FILE *fp;
    char buffer[128];
    char actual_path[PATH_MAX];

    const char *base_path = "/proc";
    const char *files[] = {"cpuinfo", "meminfo", "stat", "uptime"};
    size_t num_files = sizeof(files) / sizeof(files[0]);

    for (size_t i = 0; i < num_files; ++i) {
        snprintf(actual_path, sizeof(actual_path), "%s/%s", base_path, files[i]);

        char command[PATH_MAX + 10];
        snprintf(command, sizeof(command), "cat %s", actual_path);

        fp = popen(command, "r");
        if (fp == NULL) {
            perror("popen() failed");
            return 1;
        }

        printf("--------File %s---------\n", actual_path);
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }

        int status = pclose(fp);
        if (status == -1) {
            perror("pclose() failed");
            return 1;
        }
    }
    return 0;
}