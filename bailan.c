#include <stdio.h>
#include <unistd.h>

// The total frames number
int total = 1;
// Frame per second
int fps = 1;

// Print a frame to the console.
int printFrame(int frame) {
    char filename[14];
    sprintf(filename, "./data/%d.txt", frame);

    // Open the file
    FILE *f = NULL;
    f = fopen(filename, "r");
    if (!f) {printf("ERROR: File not found\n"); return -1;}

    // Test the file length
    fseek(f, 0, SEEK_END);
    int filelen = ftell(f);
    rewind(f);

    // Read the data
    char buf[filelen + 1];
    
        fgets(buf, filelen, f);
    
    fclose(f);

    // Print data
    char out[2002];
    sprintf(out, "%s\n", buf);
    printf(out);
    return 0;
}

int main() {
    int time = (1 / fps) * 1000000;
    for (int i = 1; i <= total; i++) {
        printFrame(i);
        usleep(time);
    }
    return 0;
}
