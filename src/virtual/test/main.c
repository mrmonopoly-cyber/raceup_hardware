#include "../virtual.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <openssl/md5.h>

void hex_to_char_hash(unsigned char *hash, char* out) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; i+=2) {
        sprintf(&out[i],"%02x", hash[i]);
    }
}

int main(void)
{
    const char *input = "example string";
    unsigned char hash[MD5_DIGEST_LENGTH];
    char out_hash[MD5_DIGEST_LENGTH];

    // Compute the MD5 hash
    MD5((unsigned char*)input, strlen(input), hash);
    hex_to_char_hash(hash, out_hash);

    const boardSpecs bs ={
        .analog_pins = 4,
        .digital_pins = 10,
        .serial_modules = 3,
        .can_modules = 2,
    };
    virtualBoard* vb = virtual_board_init(out_hash, &bs);

    return EXIT_SUCCESS;
}
