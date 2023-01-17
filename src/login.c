// gcc -o login login.c -lssl -lcrypto
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

static char enc[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                    'w', 'x', 'y', 'z', '0', '1', '2', '3',
                    '4', '5', '6', '7', '8', '9', '+', '/'};
static char *table = NULL;
void build_table() {
 
    table = malloc(256);
 
    for (int i = 0; i < 64; i++)
        table[(unsigned char) enc[i]] = i;
}
unsigned char *convert(const char *data, size_t input_length, size_t *output_length) {
 
    if (table == NULL) build_table();
 
    if (input_length % 4 != 0) return NULL;
 
    *output_length = input_length / 4 * 3;
    if (data[input_length - 1] == '=') (*output_length)--;
    if (data[input_length - 2] == '=') (*output_length)--;
 
    unsigned char *dData = malloc(*output_length);
    if (dData == NULL) return NULL;
 
    for (int i = 0, j = 0; i < input_length;) {
 
        uint32_t sextet_a = data[i] == '=' ? 0 & i++ : table[data[i++]];
        uint32_t sextet_b = data[i] == '=' ? 0 & i++ : table[data[i++]];
        uint32_t sextet_c = data[i] == '=' ? 0 & i++ : table[data[i++]];
        uint32_t sextet_d = data[i] == '=' ? 0 & i++ : table[data[i++]];
 
        uint32_t triple = (sextet_a << 3 * 6)
        + (sextet_b << 2 * 6)
        + (sextet_c << 1 * 6)
        + (sextet_d << 0 * 6);
 
        if (j < *output_length) dData[j++] = (triple >> 2 * 8) & 0xFF;
        if (j < *output_length) dData[j++] = (triple >> 1 * 8) & 0xFF;
        if (j < *output_length) dData[j++] = (triple >> 0 * 8) & 0xFF;
    }
 
    return dData;
}

int main (int argc, char * argv[]) {
    char f[] = "mal";
    char s[] = "lo";
    char t[] = "ry";
    char acc[9];
    strcat(acc, f);
    strcat(acc, s);
    strcat(acc, t);
    char fi[] = "dWN";
    char se[] = "zZW";
    char th[] = "N7c";
    char fo[] = "jN2";
    char ff[] = "ZXI";
    char si[] = "1ZV";
    char sv[] = "83a";
    char ei[] = "DNf";
    char ni[] = "djR";
    char te[] = "1bF";
    char el[] = "RzX";
    char tw[] = "3Mz";
    char ti[] = "Y3I";
    char fu[] = "zdDV9";


    if (argc < 3) {
        printf("Usage: %s USER_NAME PASSWORD\n", argv[0]);
        exit(1);
    }
    int check = strcmp(acc, argv[1]);
    if (check != 0) {
        printf(argv[1]);
        printf(" isn't a valid user\nGoodbye!\n");
        exit(1);
    }
    else {
        char baed[] = "c6";
        char sibhok[] = "3f";
        char song[] = "7d";
        char saam[] = "05";
        char sib[] = "ca";
        char sibhaa[] = "b9";
        char sibsaam[] = "10";
        char nxng[] = "a6";
        char jet[] = "2e";
        char haa[] = "83";
        char sii[] = "7d";
        char kaew[] = "bf";
        char sibed[] = "d1";
        char sibsong[] = "44";
        char hok[] = "33";
        char sibsii[] = "e6";
        char pwdcmp[33];
        sprintf(pwdcmp, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", nxng, song, saam, sii, haa, hok, jet, baed, kaew, sib, sibed, sibsong, sibsaam, sibsii, sibhaa, sibhok);
        unsigned char c[MD5_DIGEST_LENGTH];
        MD5_CTX mdContext;
        MD5_Init(&mdContext);
        MD5_Update(&mdContext, argv[2], strlen(argv[2]));
        MD5_Final(c, &mdContext);
        char hex[2*sizeof(c) + 1];
        sprintf(hex, "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x", c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14], c[15]);
        if (strcmp(pwdcmp, hex)) {
            printf("Incorrect Password, Goodbye!\n");
        }
        else {
            char bsf[45];
            snprintf(bsf, sizeof(bsf), "%s%s%s%s%s%s%s%s%s%s%s%s%s%s",fi, se, th, fo, ff, si, sv, ei, ni, te, el, tw, ti, fu);
            long dSize = strlen(bsf);
            char * fn = convert(bsf, dSize, &dSize); 
            printf("%s\n", fn);
        }
    }   

    return 0;
}