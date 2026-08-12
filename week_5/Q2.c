#include <stdio.h>
#include <string.h>

char table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

void base64Encode(char input[], char output[])
{
    int len = strlen(input);
    int i = 0;
    int j = 0;

    while (i < len)
    {
        int a = input[i++];

        int b = 0;
        int c = 0;

        int bytes = 1;

        if (i < len)
        {
            b = input[i++];
            bytes++;
        }

        if (i < len)
        {
            c = input[i++];
            bytes++;
        }

        output[j++] = table[a >> 2];

        output[j++] = table[((a & 3) << 4) | (b >> 4)];

        if (bytes >= 2)
            output[j++] = table[((b & 15) << 2) | (c >> 6)];
        else
            output[j++] = '=';

        if (bytes == 3)
            output[j++] = table[c & 63];
        else
            output[j++] = '=';

    }

    output[j] = '\0';
}

int main()
{
    char input[100];
    char output[200];

    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    base64Encode(input, output);

    printf("Base64: %s\n", output);

    return 0;
}
