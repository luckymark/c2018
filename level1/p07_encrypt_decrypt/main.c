//每四个bit位对应table中的一位可见字符，改版base16，(>.<)
//长度还是做了一点限制的，不然会stackoverflow的(*>。<*)
//only supports ascii
//ubuntu14.04, CLion C99

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define LENGTH 10000

char table[17] = "@.0r*_zoO-=UESTC";

char String[LENGTH + 1] = {0};

char *Encrypt() {
    int length = strlen(String) - 1;//去掉\n
    char *encryptedStr = malloc(2 * length + 1);
    memset(encryptedStr, 2 * length + 1, 0);
    for (int i = 0; i < length; i++) {
        encryptedStr[2 * i] = table[String[i] >> 4];
        encryptedStr[2 * i + 1] = table[String[i] & 0xf];
    }
    return encryptedStr;
}

int getIndex(char Char) {
    for (int i = 0; i < 16; i++) {
        if (table[i] == Char) {
            return i;
        }
    }
    return -1;
}

char *Decrypt() {
    int length = strlen(String) - 1;//去掉\n
    char *decryptedStr = malloc(length / 2 + 1);
    memset(decryptedStr, length / 2 + 1, 0);

    for (int i = 0; i < length; i += 2) {
        int high = getIndex(String[i]);
        int low = getIndex(String[i + 1]);
        if (high == -1 || low == -1) {
            decryptedStr = "Invalid string!";
            return decryptedStr;
        }
        decryptedStr[i / 2] = (high << 4) + low;
    }
    return decryptedStr;
}

int main() {
    char *result;
    char mode;
    while (1) {
        printf("Choose mode:\n1.Encrypt\n2.Decrypt\n3.Exit\n");

        fgets(&mode, 2, stdin);
        getchar();//消除\n

        if (mode == '1') {
            puts("Input your string:");
            fgets(String, LENGTH / 2 + 1, stdin);//理论上加密结果是原文长度的两倍
            result = Encrypt();
            printf("Encrypted string:\n%s\n\n", result);
        } else if (mode == '2') {
            puts("\Input your string:");
            fgets(String, LENGTH + 1, stdin);
            result = Decrypt();
            printf("Decrypted string:\n%s\n\n", result);
        } else if (mode == '3') {
            break;
        } else {
            puts("Wrong input!\n\n");
            continue;
        }
        free(result);
    }

    return 0;
}