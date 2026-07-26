#include <stdio.h>

int main()
{
    int ch, next;

    while ((ch = getchar()) != EOF)
    {
        if (ch == '"')
        {
            putchar(ch);

            while ((ch = getchar()) != EOF)
            {
                putchar(ch);

                if (ch == '\\')
                {
                    ch = getchar();
                    if (ch != EOF)
                        putchar(ch);
                }
                else if (ch == '"')
                {
                    break;
                }
            }
        }
        else if (ch == '\'')
        {
            putchar(ch);

            while ((ch = getchar()) != EOF)
            {
                putchar(ch);

                if (ch == '\\')
                {
                    ch = getchar();
                    if (ch != EOF)
                        putchar(ch);
                }
                else if (ch == '\'')
                {
                    break;
                }
            }
        }
        else if (ch == '/')
        {
            next = getchar();

            if (next == '/')
            {
                while ((ch = getchar()) != EOF && ch != '\n');

                if (ch == '\n')
                    putchar('\n');
            }
            else if (next == '*')
            {
                int prev = 0;

                while ((ch = getchar()) != EOF)
                {
                    if (prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }
            }
            else
            {
                putchar(ch);

                if (next != EOF)
                    ungetc(next, stdin);
            }
        }
        else
        {
            putchar(ch);
        }
    }

    return 0;
}
