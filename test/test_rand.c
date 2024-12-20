#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ubi_crypt/rand.h>
#include <ubi_crypt/numeric.h>
#include <ubi_common/errors.h>
#include <ubi_common/structs.h>

#define MOD_ORDER_SIZE 16
#define RANDOM_BYTES_SIZE 16

void test_ubi_random_bytes_mod(void);

void test_ubi_random_bytes_mod(void) {
    struct ubi_random_bytes_mod_in in;
    struct ubi_random_bytes_mod_out *out = NULL;
    int ret;

    // Initialize mod_order buffer
    struct ubi_buffer mod_order;
    mod_order.buffer = malloc(MOD_ORDER_SIZE);
    mod_order.buffer_len = MOD_ORDER_SIZE;
    for (int i = 0; i < MOD_ORDER_SIZE; i++) {
        mod_order.buffer[i] = i + 1;
    }

    // Set input parameters
    in.bytes_num = RANDOM_BYTES_SIZE;
    in.mod_order = &mod_order;

    // Call the function
    ret = ubi_random_bytes_mod(&in, &out);

    // Check the return value
    if (ret != UBI_SUCCESS) {
        printf("ubi_random_bytes_mod failed with error code: %d\n", ret);
    } else {
        printf("ubi_random_bytes_mod succeeded\n");

        // Print the generated random bytes mod in hexadecimal format
        printf("Generated random bytes mod: ");
        for (size_t i = 0; i < out->random_bytes_mod->buffer_len; i++) {
            printf("%02x", out->random_bytes_mod->buffer[i]);
        }
        printf("\n");
    }

    // Free allocated memory
    free_ubi_random_bytes_mod_out(out);
    free(mod_order.buffer);
}


int main(void) {
    unsigned char output[RANDOM_BYTES_SIZE];
    int ret = 0;

    // Generate random bytes
    ret = ubi_random_bytes(NULL, output, RANDOM_BYTES_SIZE);

    if (ret != 0) {
        printf("Failed to generate random bytes\n");
        return 1;
    }

    // Print the generated random bytes in hexadecimal format
    printf("Generated random bytes: ");
    for (int i = 0; i < RANDOM_BYTES_SIZE; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}
