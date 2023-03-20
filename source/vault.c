#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MD5 Hash a67d057d83332ec6bfcad14410e6b93f 
// flashthunder

int main (int argc, char * argv[]) {
    char baed[] = "c6";
    char sibhok[] = "3f";
    char song[] = "7d";
    char saam[] = "05";
    char sib[] = "ca";
    char ptrois[] = "19#";
    char sibhaa[] = "b9";
    char pun[] = "Bk>";
    char sibsaam[] = "10";
    char nxng[] = "a6";
    char jet[] = "2e";
    char haa[] = "83";
    char sii[] = "7d";
    char kaew[] = "bf";
    char sibed[] = "d1";
    char pdeux[] = "k{$";
    char sibsong[] = "44";
    char hok[] = "33";
    char sibsii[] = "e6";
    char p1[50];
    char p2[50];
    char h[3];

    strcat(p1, ptrois);
    printf("Please Enter Vault Code ... \n");
    strcat(p1, pun);
    scanf("%s", p2);
    strcat(p1, pdeux);

    int check = strcmp(p1,p2);
    if (check == 0) {
        printf("Thank You!!\nHere is your password recovery hint: ");
        strcpy(h, nxng);
        printf("%s", h);

        strcpy(h, song);
        printf("%s", h);

        strcpy(h, saam);
        printf("%s", h);

        strcpy(h, sii);
        printf("%s", h);

        strcpy(h, haa);
        printf("%s", h);

        strcpy(h, hok);
        printf("%s", h);

        strcpy(h, jet);
        printf("%s", h);

        strcpy(h, baed);
        printf("%s", h);

        strcpy(h, kaew);
        printf("%s", h);

        strcpy(h, sib);
        printf("%s", h);

        strcpy(h, sibed);
        printf("%s", h);

        strcpy(h, sibsong);
        printf("%s", h);

        strcpy(h, sibsaam);
        printf("%s", h);

        strcpy(h, sibsii);
        printf("%s", h);

        strcpy(h, sibhaa);
        printf("%s", h);

        strcpy(h, sibhok);
        printf("%s", h);

        printf("\n");
    }
    else {
        printf("Incorrect code provided, Goodbye!\n");
    }
    return 0;
}