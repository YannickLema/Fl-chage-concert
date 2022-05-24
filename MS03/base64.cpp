#include <iostream>
#include <string.h>
using namespace std;

char base64ToAscii(char c64)
{
    char c;
    // Décryptage Base64 -> ASCII
    if(c64<26) c = 'A' + c64;
    else if (c64<52) c = 'a' + c64 - 26;
    else if (c64<62) c = '0' + c64 - 52;
    else if (c64 == 62) c = '+';
    else c = '/';
    return c;
}

void codage64(const char mot[], char motCode[] )
{
    // 0 3 6 9

    char c64;
    int lgMot = strlen(mot);
    int j = 0;
    // Codage de tous les caractères par groupe de 3, sans exception
    for(int i=0 ; i<=lgMot-3 ; i=i+3)
    {
        c64 = (mot[i]>>2) & 0x3F;
        motCode[j++] = base64ToAscii(c64);

        c64 = ((mot[i]<<4) & 0x3F) | (mot[i+1]>>4);
        motCode[j++] = base64ToAscii(c64);

        c64 = ((mot[i+1]<<2) & 0x3F) | (mot[i+2]>>6);
        motCode[j++] = base64ToAscii(c64);

        c64 = mot[i+2] & 0x3F;
        motCode[j++] = base64ToAscii(c64);
    }
    // S'il reste 1 caractère à coder
    if(lgMot%3 == 1)
    {
        c64 = (mot[lgMot-2]>>2) & 0x3F;
        motCode[j++] = base64ToAscii(c64);
        c64 = (mot[lgMot-2]<<4) & 0x3F;
        motCode[j++] = base64ToAscii(c64);
        motCode[j++] = '=';
        motCode[j++] = '=';
    }
    // S'il reste 2 caractères à coder
    else if(lgMot%3 == 2)
    {
        c64 = (mot[lgMot-2]>>2) & 0x3F;
        motCode[j++] = base64ToAscii(c64);
        c64 = ((mot[lgMot-2]<<4) & 0x3F) | (mot[lgMot-1]>>4);
        motCode[j++] = base64ToAscii(c64);
        c64 = (mot[lgMot-1]<<2) & 0x3F;
        motCode[j++] = base64ToAscii(c64);
        motCode[j++] = '=';
    }

    motCode[j] = '\0';
}
