#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ubi_common/errors.h>
#include <ubi_common/macros.h>
#include <ubi_common/structs.h>
#include <ubi_crypt/pairings.h>
#include <ubi_crypt/ec2.h>

void test_pairings(void);

void test_pairings(void) {
    uint8_t e[] = {0xa9, 0x51, 0x04, 0x80, 0x00, 0x7f, 0x6e, 0xaa, 0xcf, 0xc1, 0x98, 0x02, 0x41, 0x32, 0x80, 0x9e, 0xef, 0xbc, 0x76, 0x73, 0x6b, 0x36, 0x4c, 0x3f, 0xb2, 0x45, 0x51, 0xd6, 0x76, 0x42, 0x87, 0xac};
    uint8_t A[] = {0x04, 0x06, 0x2a, 0x87, 0x5c, 0x37, 0xde, 0xb0, 0x91, 0x33, 0xec, 0xb4, 0xbd, 0x41, 0x24, 0x94, 0xc7, 0xc4, 0x6f, 0x0e, 0xdf, 0xeb, 0x31, 0x00, 0x38, 0x59, 0x0f, 0x44, 0xe6, 0x57, 0xcb, 0x98, 0x24, 0xb0, 0x68, 0xa5, 0xbf, 0x0f, 0xdb, 0x10, 0x09, 0x5e, 0xf1, 0x76, 0xec, 0x1c, 0xc1, 0x95, 0x7f, 0x99, 0x72, 0xe0, 0x58, 0x51, 0x72, 0xae, 0x8b, 0x3e, 0x32, 0xaa, 0x11, 0x67, 0xa7, 0xd9, 0x84};
    uint8_t PKI[] = {0x04, 0xd9, 0x84, 0x37, 0x1f, 0xc1, 0xe2, 0x59, 0x57, 0x82, 0x3e, 0x3b, 0x22, 0x0b, 0x57, 0x30, 0x9d, 0x0d, 0x76, 0x37, 0x06, 0xb2, 0xa3, 0x04, 0x64, 0xd8, 0x34, 0xac, 0xbd, 0x8d, 0x30, 0xa3, 0x26, 0xe4, 0x47, 0xa1, 0xb9, 0x82, 0xe5, 0x85, 0x0a, 0x3d, 0xf2, 0xa3, 0x32, 0x96, 0x5d, 0xfa, 0xfb, 0xc2, 0xe5, 0x17, 0x3a, 0x9d, 0x57, 0xae, 0xa7, 0xbd, 0xca, 0x56, 0xea, 0xc1, 0xe9, 0x06, 0x30, 0x26, 0xca, 0xa9, 0x4c, 0xe9, 0x44, 0xef, 0x4e, 0xbc, 0xee, 0x0d, 0x19, 0xca, 0x8c, 0xa5, 0x3d, 0x9e, 0x49, 0xd5, 0x11, 0xb9, 0xf2, 0xed, 0xae, 0x87, 0x36, 0xf9, 0xe9, 0x3c, 0x1d, 0xd5, 0xa6, 0x74, 0x82, 0xeb, 0xeb, 0xe7, 0xb3, 0x62, 0x46, 0xe3, 0x26, 0x81, 0x42, 0x72, 0x60, 0xa5, 0xd4, 0x25, 0xb7, 0xf5, 0x44, 0xfe, 0x1a, 0x96, 0x63, 0x0e, 0xfe, 0x8d, 0xbc, 0x98, 0xdd, 0xf0, 0x6a};
    uint8_t g2[] = {0x04, 0x4e, 0xa6, 0x60, 0x57, 0x73, 0x8a, 0xc0, 0x54, 0xdb, 0x5a, 0xe1, 0xc6, 0x37, 0xd8, 0x13, 0xb9, 0x24, 0xdd, 0x78, 0xe2, 0x87, 0xd0, 0x35, 0x89, 0xd2, 0x69, 0xed, 0x34, 0xa3, 0x7e, 0x6a, 0x2b, 0xfe, 0x0c, 0x33, 0x50, 0xb4, 0xc9, 0x6c, 0x20, 0x28, 0x56, 0x0f, 0x57, 0x7c, 0x28, 0x91, 0x3a, 0xce, 0x1c, 0x53, 0x9a, 0x12, 0xbf, 0x84, 0x3c, 0xd2, 0x26, 0x16, 0xb6, 0x89, 0xc0, 0x9e, 0xfb, 0x05, 0x54, 0xe3, 0xbc, 0xd3, 0x88, 0xc2, 0x90, 0x42, 0xee, 0xa6, 0x49, 0x29, 0x7e, 0xb2, 0x9f, 0x8b, 0x4c, 0xbe, 0x80, 0x82, 0x1a, 0x98, 0xb3, 0xe0, 0x12, 0x81, 0x11, 0x4a, 0xad, 0x04, 0x9b, 0x70, 0x20, 0x46, 0xe7, 0xc5, 0x42, 0xa3, 0xb3, 0x76, 0x77, 0x0d, 0x75, 0x12, 0x4e, 0x3e, 0x51, 0xef, 0xcb, 0x24, 0x75, 0x8d, 0x61, 0x58, 0x48, 0xe9, 0x09, 0xb4, 0x81, 0xbe, 0xdc, 0x27, 0xff};
    uint8_t g0yc[] = {
    0x04, 0x90, 0xde, 0xd8, 0x77, 0xab, 0x9b, 0xaf, 0xfc, 0x7e, 0x3a, 0xb4, 
    0xf7, 0x89, 0xb0, 0x7a, 0xfb, 0x97, 0xe8, 0x55, 0x69, 0x0c, 0xb0, 0x4b, 
    0xdb, 0x2c, 0x81, 0x4c, 0x0c, 0x77, 0x04, 0xc3, 0x67, 0xfd, 0xe4, 0xde, 
    0x64, 0x9b, 0x89, 0x2b, 0xac, 0x62, 0x2e, 0xdf, 0xd2, 0xd1, 0xa7, 0xa9, 
    0xed, 0x93, 0x8d, 0xcb, 0x35, 0x20, 0xff, 0xa7, 0x36, 0xd8, 0x16, 0xac, 
    0x0b, 0x6d, 0x3b, 0x87, 0x16
};

    ubi_buffer ubi_g0yc = {g0yc, sizeof(g0yc)};
    ubi_buffer ubi_g2 = {g2, sizeof(g2)};
    ubi_buffer ubi_e = {e, sizeof(e)};
    ubi_buffer ubi_A = {A, sizeof(A)};
    ubi_buffer ubi_PKI = {PKI, sizeof(PKI)};
    ubi_commit2_in c2_in = {
        .points = (struct ubi_buffer *[]){&ubi_g2},
        .commit_num = 1,
        .curve_type = BNP_256,
        .commited_secret = &ubi_e
    };
    ubi_commit2_out *c2_out = NULL;
    int ret = ubi_commit2(&c2_in, &c2_out);
    if (ret != 0) {
        printf("ubi_commit2 failed: %d\n", ret);
        return;
    } else {
        printf("ubi_commit2 succeeded\n");
        // Validate the output
        if (c2_out != NULL && c2_out->commitment != NULL && c2_out->commitment[0] != NULL && c2_out->commitment[0]->buffer != NULL && c2_out->commitment[0]->buffer_len > 0) {
            printf("Commitment buffer length: %zu\n", c2_out->commitment[0]->buffer_len);
            printf("Commitment buffer data: ");
            for (size_t i = 0; i < c2_out->commitment[0]->buffer_len; i++) {
                printf("%02x", c2_out->commitment[0]->buffer[i]);
            }
            printf("\n");
        } else {
            printf("Invalid commitment output\n");
            return;
        }
    }

    ubi_ec2_point_add_in ec2_in = {
        .curve_type = BNP_256,
        .points = (struct ubi_buffer *[]){&ubi_PKI, c2_out->commitment[0]},
        .points_num = 2
    };
    ubi_ec2_point_add_out *ec2_out = NULL;
    ret = ubi_ec2_point_add(&ec2_in, &ec2_out);
    if (ret != 0) {
        printf("ubi_ec2_point_add failed: %d\n", ret);
        return;
    } else {
        printf("ubi_ec2_point_add succeeded\n");
        // Validate the output
        if (ec2_out != NULL && ec2_out->point != NULL && ec2_out->point->buffer != NULL && ec2_out->point->buffer_len > 0) {
            printf("Result buffer length: %zu\n", ec2_out->point->buffer_len);
            printf("Result buffer data: ");
            for (size_t i = 0; i < ec2_out->point->buffer_len; i++) {
                printf("%02x", ec2_out->point->buffer[i]);
            }
            printf("\n");
        } else {
            printf("Invalid result output\n");
            return;
        }
    }
    struct ubi_verify_bbs_pairings_in in = {
        .curve_type = BNP_256,
        .point2_a = &ubi_g2,
        .point_b = &ubi_g0yc,
        .point2_c = ec2_out->point,
        .point_d = &ubi_A
    };
    struct ubi_verify_bbs_pairings_out out;
    ret = ubi_verify_bbs_pairings(&in, &out);
    if (ret != 0) {
        printf("ubi_verify_bbs_pairings failed: %d\n", ret);
        return;
    } else {
        printf("ubi_verify_bbs_pairings succeeded\n");
        // Validate the output
        printf("Pairing status: %d\n", out.pairing_status);
    }



    free_ubi_commit2_out(c2_out);
    free_ubi_ec2_point_add_out(ec2_out);
}

int main(void) {
    printf("this is a place holder for testing pairings\n");
    test_pairings();
    return 0;
}