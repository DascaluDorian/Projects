#include<stdio.h>

static void caesarEncryption(char *message, int key);
static void caesarDecryption(char *message, int key);

int main()
{
    char message[100];
    int key;

    printf("Enter a message : ");
    gets(message);

    printf("Enter key: ");
    scanf("%d", &key);

    int number;
    printf("1. Encryption\n2. Decryption\n");
    scanf("%d", &number);

    if ( 1 == number)
    {
        caesarEncryption(&message[0], key);
    }
    else
    {
        caesarDecryption(&message[0], key);
    }

    return 0;
}

static void caesarEncryption(char *message, int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; i++)
    {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
    printf("Encrypted message: %s", message);
}

static void caesarDecryption(char *message, int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; i++){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }

    printf("Decrypted message: %s", message);
}
