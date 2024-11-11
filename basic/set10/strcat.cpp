#include <iostream>
using namespace std;

#define DEST_SIZE 100 // Fixed size for destination
#define SRC_SIZE 50   // Fixed size for source

void strcat(char *dest, char *src)
{
    int dest_len = 0;
    int src_len = 0;

    // Calculate the length of dest up to DEST_SIZE - 1 to prevent overflow
    while (dest_len < DEST_SIZE - 1 && dest[dest_len] != '\0')
    {
        dest_len++;
    }

    // Copy src to dest starting at dest_len
    while (src[src_len] != '\0' && dest_len < DEST_SIZE - 1)
    {
        dest[dest_len] = src[src_len];
        dest_len++;
        src_len++;
    }

    // Null-terminate dest
    dest[dest_len] = '\0';
}

int main()
{
    char dest[DEST_SIZE] = "Hello, ";
    char src[SRC_SIZE] = "world!";

    strcat(dest, src);

    cout << "Concatenated string: " << dest << endl;

    return 0;
}