
#include <cublas.h>
#include <math.h>

#define BLOCK_SIZE 128

typedef struct{
    float* mat;
    float* mat_d;
    int dim[2];
} matrix;

typedef enum{
    compute,
    cleanup
} action_t;

//creating, allocating, moving matrices
void read_matrix(matrix* A, char* file);
void write_matrix(matrix A, char* file);
void create_matrix(matrix* A, int rows, int cols, float value);
void create_matrix_on_device(matrix* A, int rows, int cols, float value);
void create_matrix_on_both(matrix* A, int rows, int cols, float value);
void copy_matrix_to_device(matrix* A);
void copy_matrix_on_device(matrix A, matrix B);
void copy_matrix_from_device(matrix* A);
void destroy_matrix(matrix* A);
void print_matrix(matrix A);
float matrix_difference_norm_d(action_t action,  matrix a, matrix c, int block1, int lapt1, int block2, int lapt2);
float matrix_div_d(action_t action, matrix a, matrix b, int block1, int lapt1,int block2, int lapt2);
void matrix_multiply_d( matrix a, matrix b, matrix c );
void matrix_multiply_AtB_d( matrix a, matrix b, matrix c );
void matrix_multiply_ABt_d( matrix a, matrix b, matrix c );
void element_multiply_d( matrix a, matrix b, matrix c);
void element_divide_d( matrix a, matrix b, matrix c, int block_size);
void matrix_eps_d( matrix a, int block_size);
void row_divide_d( matrix a, matrix b, matrix c);
void col_divide_d( matrix a, matrix b, matrix c);
void sum_cols_d(action_t action, matrix a, matrix c, int block1, int lapt1, int block2, int lapt2);
void sum_rows_d(action_t action, matrix a, matrix c, int block1, int lapt1, int block2, int lapt2);
void sum_cols_d_test(action_t action, matrix a, matrix c, int block1, int lapt1,int block2, int lapt2);
void sum_cols_d_test2(action_t action, matrix a, matrix c, int block1, int lapt1,int block2, int lapt2);
void sum_cols_d_test3(action_t action, matrix a, matrix c, int block1, int lapt1,int block2, int lapt2);
void sum_cols_d_test4(action_t action, matrix a, matrix c, int block1, int lapt1,int block2, int lapt2);
void sum_cols_d_test5(action_t action, matrix a, matrix c, int block1, int lapt1,int block2, int lapt2);
