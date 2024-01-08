#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* is_valid_char: return the input if it's a digit or a white space (backtab,
 * spaces or next line).
 */
char is_valid_char(char c) {
    if ((c >= '0' && c <= '9') || c == ' ' || c == '\n' || c == '\t' ||
        c == '-')
        return TRUE; /* c is a digit or a minus sign (maybe a start of a
                        negative number) */
    else
        return FALSE;
}

/* get_char_and_skip_spaces: return the input if it's a digit or a white space
 * (backtab, spaces or next line).
 */
char get_char_and_skip_spaces(void) {
    char c;
    while ((c = getchar()) == ' ' || c == '\n' || c == '\t') {
    }
    return c;
}

/* A function to convert separate char digits to an int number.
    the function adds to the sum only valid inputs
    if detects invalid inpute - return the saved defination NONDIGIT
    if detects a stop after one or more following digits - return the number
   that the digits represent
 */
int get_num(char c, int *input_num) {
    int num, is_positive;
    num = 0;
    is_positive = TRUE;

    if (c == '-') { /* maybe a negative number */
        if (!is_valid_char(c = getchar()))
            return FALSE;
        else
            is_positive = FALSE;
    }

    while (c != '\n' && c != '\t' && c != ' ' && c != EOF) {
        num = num * 10 + (c - '0');
        c = getchar();
        if (!is_valid_char(c))
            return FALSE;
    }
    *input_num = is_positive ? num : -num;
    return TRUE;
}

/* A function to check if the user added the required quantity of numbers.
    return TRUE if passes the requirmetnsthe or prints the problem and return
   False  */
int is_square(int i, int j, char c, int N) {
    if (i == N && j == 0) {
        if (c == EOF)
            return TRUE;
        else
            printf("Too many numbers in the input.\n");
    } else
        printf("Not enogh numbers in the input.\n");
    printf("Program will be closed because of an input faliure.\n");
    return FALSE;
}

/* A function to print the user instructions. */
void instrutions(int total) {
    printf("Please insert %d integer numbers.\nPress ctrl+d when done.\n",
           total);
}

/* A function to print a squre out of 2dim array. */
void print_mat(int **mat, int N) {
    int row, col;
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col)
            printf("%3d", mat[row][col]);
        putchar('\n');
    }
}

/* check_diagonal: return TRUE if the sum of the diagonal is even, FALSE
 * otherwise.
 */
int check_diagonal(int **mat, int N) {
    int diagonalSum1 = 0, diagonalSum2 = 0;
    int i;

    /* Compute the sums of the two diagonals */
    for (i = 0; i < N; i++) {
        diagonalSum1 += mat[i][i];
        diagonalSum2 += mat[i][N - 1 - i];
    }

    if (diagonalSum1 != diagonalSum2) {
        printf("Failed in diagonal check\n");
        return FALSE;
    }
    return TRUE;
}

/* check_row_col: return TRUE if the sum of the row and the column is even,
 * FALSE otherwise.
 */
int check_row_col(int **mat, int N) {
    int rowSum, colSum;
    int i, j;

    /* Check the sum of each row and column */
    for (i = 0; i < N; i++) {
        rowSum = 0;
        colSum = 0;
        for (j = 0; j < N; j++) {
            rowSum += mat[i][j];
            colSum += mat[j][i];
        }
        if (rowSum != colSum) {
            printf("Failed in row and column check\n");
            return FALSE;
        }
    }
    return TRUE;
}

/* A function to check if the sum in every row, colum and cross are even
    if even - return TRUE, other - return FALSE */
int is_magic(int **mat, int N) {
    if (!check_diagonal(mat, N))
        return FALSE;

    if (!check_row_col(mat, N))
        return FALSE;

    printf("It's a magic square!\n");
    return TRUE;
}

void print_mat_with_index(int **mat, int N) {
    int row, col;

    printf("The matrix is:\n");
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col)
            printf("(%d,%d) = %2d | ", row, col, *(*(mat + row) + col));
        putchar('\n');
    }
    putchar('\n');
}

void free_mat(int **mat, int N) {
    int i;
    for (i = 0; i < N; i++)
        free(mat[i]);
    free(mat);
}

/* A function to create and test the square.
    It creates an empty NxN matrix and than,
    it asks the user for N^2 intigers for filling the matrix.
    If the input was valid it prints the matrix and whether it's a "magic squre"
   or not */
void new_square(int N) {
    int num, rows, cols;
    char c; /* current character */
    int **mat;
    num = rows = cols = 0;

    mat = (int **)malloc(N * sizeof(int *));
    if (mat == NULL) {
        printf("Memory allocation failure\n");
        exit(1);
    }
    for (; rows < N; rows++) {
        mat[rows] = (int *)malloc(N * sizeof(int));
        if (mat[rows] == NULL) {
            printf("Memory allocation failure in row %d\n", rows);
            exit(1);
        }
    }

    rows = 0;

    printf("creating matrix...\n");

    instrutions(N * N);
    c = get_char_and_skip_spaces();

    while ((c != EOF) && (rows < N)) {
        if (get_num(c, &num) == FALSE)
            return;
        *(*(mat + rows) + cols) = num;
        cols++;
        if (cols == N) {
            cols = 0;
            rows++;
        }
        c = get_char_and_skip_spaces();
    } /* if N^2 numbers were readen the loop ends whith i = N and j = 0 */

    putchar('\n');

    print_mat_with_index(mat, N);

    if (is_square(rows, cols, c, N)) {
        print_mat(mat, N);
        if (!(is_magic(mat, N)))
            printf("Not a magic square...\n");
    }

    free_mat(mat, N);
}

/* create_histogram: ... */


/* Get matrix size from user, build the matrix and check if it's a magic square.
 */
int main(void) {
    int size;
    printf("Please enter a number for the square's size (1-9): ");
    while (scanf("%d", &size) != 1 || size < 1 ||
           size > 9) /* check if the input is valid */
        printf("Invalid input. Please enter a number for the square's size "
               "(1-9): ");
    printf("The square's size is %d.\n", size);
    new_square(size);
    return 0;
}
