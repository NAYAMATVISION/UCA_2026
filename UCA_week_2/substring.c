#include <stdio.h>

int length(const char str[]) {
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}


char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }

    return ch;
}


int find_substring(const char haystack[], const char needle[]) {

    int n = length(haystack);
    int m = length(needle);

    if (m == 0)
        return 0;

    if (m > n)
        return -1;

    for (int i = 0; i <= n - m; i++) {

        int j = 0;

        while (j < m && toLower(haystack[i + j]) == toLower(needle[j])) {
            j++;
        }

        if (j == m)
          return i;
    }

    return -1;
}

int main() {

    char haystack[] = "Embedded systems";
    char needle[] = "bed";

    printf("%d\n", find_substring(haystack, needle));

    return 0;
}
