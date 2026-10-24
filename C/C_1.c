#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

void *custom_memcpy(void *dest, const void *src, size_t n) {

    //Code

    return dest;

}

size_t my_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len + 1;
}

int main(int argc, char *argv[]) {

    unsigned char buffer[1024] = {0};
    for(int i = 0; i < 1024; i++) buffer[i] = ' ';

    const char *strings[] = {
        "mpazziti tutti quanti",
        "Co",
        "limetta verde",
        "nti challenge complet",
        "ata!"
    };

    size_t offsets[] = {3, 0, 5, 9, 30};
    size_t num_strings = sizeof(strings) / sizeof(strings[0]);

    for (size_t i = 0; i < num_strings; i++) {
        size_t len = my_strlen(strings[i]);
        if (offsets[i] + len <= sizeof(buffer)) {
            custom_memcpy(buffer + offsets[i], strings[i], len);
        }
    }

    FILE *f = fopen("sol_utente", "wb");
    if (!f) {
        return 1;
    }

    fwrite(buffer, 1, sizeof(buffer), f);
    fclose(f);

    return 0;


}
