#include <stdio.h>

int test_num = 0x00FFA;

int test_n_bit(int n, int num) {
    // printf("%d \n", test_num & (1 << n));
    return ((num & (1 << n)) != 0);
} 

int set_n_bit_zero(int n, int num) {
    return num & (0xFFFFFFFF ^ (1 << n)); 
}

int set_n_bit_one(int n, int num) {
    return num |  (1 << n);
}

main() {
    int i;
    for (i = 0; i < 32; i++) {
        printf("%d ", test_n_bit(i, test_num));
    }
    printf("\n");
    
    int after_set = test_num;
    for (i = 4; i < 9; i++) {
        after_set = set_n_bit_zero(i, after_set);
    }
    printf("\n");
    for (i = 0; i < 32; i++) {
        printf("%d ", test_n_bit(i, after_set));
    }
    printf("\n");

    for (i = 4; i < 9; i++) {
        after_set = set_n_bit_one(i, after_set);
    }
    for (i = 0; i < 32; i++) {
        printf("%d ", test_n_bit(i, after_set));
    }
    printf("\n");
}
