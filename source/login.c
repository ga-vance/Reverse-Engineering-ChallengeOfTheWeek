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
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    char input_uname[128];
    char input_pword[128];

    char acc[8] = "mallory";

    /*/ old, terminal-based inputs
    if (argc < 3) {
        printf("Usage: %s USER_NAME PASSWORD\n", argv[0]);
        exit(1);
    }
    // */

    printf("Enter your username (max 128 characters): ");
    fflush(stdout);
    scanf("%128s", input_uname);

    int check = strcmp(acc, input_uname);
    if (check != 0) {
        printf(input_uname);
        printf(" isn't a valid user\nGoodbye!\n");
        fflush(stdout);
        return 0;
    }
    else {
        printf("Enter your password (max 128 characters): ");
        fflush(stdout);
        scanf("%127s", input_pword);
        char pwdcmp[33];
        FILE * phashf = fopen("./phash.txt", "r");
        fscanf(phashf, "%s", pwdcmp);
        // sprintf(pwdcmp, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", nxng, song, saam, sii, haa, hok, jet, baed, kaew, sib, sibed, sibsong, sibsaam, sibsii, sibhaa, sibhok);
        unsigned char c[MD5_DIGEST_LENGTH];
        MD5_CTX mdContext;
        MD5_Init(&mdContext);
        // MD5_Update(&mdContext, argv[2], strlen(argv[2]));
        MD5_Update(&mdContext, input_pword, strlen(input_pword));
        MD5_Final(c, &mdContext);
        char hex[2*sizeof(c) + 1];
        sprintf(hex, "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x", c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14], c[15]);
        if (strcmp(pwdcmp, hex)) {
            printf("Incorrect Password, Goodbye!\n");
            fflush(stdout);
        }
        else {
            char bsf[45];
            FILE * flag = fopen("./flag.txt", "r");
            fscanf(flag, "%s", bsf);
            // snprintf(bsf, sizeof(bsf), "%s%s%s%s%s%s%s%s%s%s%s%s%s%s",fi, se, th, fo, ff, si, sv, ei, ni, te, el, tw, ti, fu);
            // long dSize = strlen(bsf);
            // char * fn = convert(bsf, dSize, &dSize);
            // printf("%s\n", fn);
            printf("%s\n", bsf);
            fflush(stdout);
        }
    }   

    return 0;
}
