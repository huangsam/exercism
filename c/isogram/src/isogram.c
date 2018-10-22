#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "isogram.h"

bool is_isogram(const char phrase[])
{
    if (!phrase) {
        return false;
    }

    int *freq = (int *) calloc(sizeof(int), 27);
    int i;

    int plen = strlen(phrase);
    for (i = 0; i < plen; i++) {
        if (!isalnum(phrase[i])) {
            continue;
        }

        int c = (int) (tolower(phrase[i]) - 'a');
        freq[c] += 1;
    }

    for (i = 0; i < 27; i++) {
        if (freq[i] > 1) {
            return false;
        }
    }

    return true;
}
