/**
* Pointers Gone Wild Lab
* CS 241 - Spring 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
/**
 * Checks to see if the input parameter is a passing grade and prints out
 * if the grade is passing using the provided format specifiers. Note that
 * 'grade' is a char pointer pointing to the beginning of a C string. A grade
 * is considered passing iff the numeric interpretation (defined by strtof) is
 * above a 70. Suppose
 * that 'grade' pointed to the string "73.58", then 'grade' would be passing in
 * this example. If 'grade' pointed to "it's over 9000!!!!", then that is still
 * not
 * a passing grade.
 *
 * @param grade
 *     The grade to check.
 */
void one(const char *grade) {
    char* endp;
    errno = 0;
    double g = strtod(grade, &endp);
    if (g == 0 && (errno != 0 || endp == grade)) {
        printf("%s not passed!\n", grade);
    }
    if (g > 70)
        printf("%f passed!\n", g);
    else
        printf("%s not passed!\n", grade);
}

/**
 * Have the integer pointer p point to the integer x which is on the stack.
 * Then print the value that 'p' points to and format it as an integer
 */
void two() {
    int x = 4;
    int *p = &x;
    printf("The value of p is: %d\n", *p);
}

/**
 * Prints "x and y are equal." iff the values x and y point to are equal
 * where equality is defined by integer equality.
 * Else print "x and y are different".
 *
 * @param x
 *     First input parameter.
 *
 * @param y
 *     Second input parameter.
 */
void three(const int *x, const int *y) {
    if (x == y || *x == *y)
        printf("x and y are equal.\n");
    else
        printf("x and y are different.\n");
}

/**
 * Returns a pointer to a float that points to memory on the heap,
 * which contains a copy of the value that the integer pointer 'x' is pointing
 * to.
 *
 * @param x
 *     Input parameter, whose value will be returned as a (float *).
 *
 * @returns
 *     A new pointer, allocated on the heap and not freed, that
 *     contains the value of the input parameter.
 */
float *four(const int *x) {
    float *p = (float*)malloc(sizeof(float));
    *p = *x;
    return p;
}

/**
 * Takes a char pointer 'a' and checks to see if the first char
 * that it points to is alphabetic (upper or lower case).
 *
 * @param a
 *     Input parameter a, which is a char*
 *
 */
void five(const char *a) {
    if ((*a >= 'A' && *a <= 'Z') || (*a >= 'a' && *a <= 'z'))
        printf("a is a letter.\n");
    else
        printf("a is not a letter.\n");
}

/**
 * Concatenates "Hello " and the parameter str, which is guaranteed to be a
 * valid c string, and
 * prints the concatenated string.
 */
void six(const char *str) {
    char *s = "Hello ";
    char* strca = (char*)calloc(6 + strlen(str) + 1, sizeof(char));
    strcat(strca, s);
    strcat(strca, str);
    printf("%s\n", strca);
    free(strca);
}

/**
 * Creates an array of values containing the values {0.0, 0.1, ..., 0.9}.
 */
void seven() {
    float *values = (float*)malloc(sizeof(float) * 10);
    int i, n = 10;
    for (i = 0; i < n; i++)
        values[i] = (float)i / n;

    for (i = 0; i < n; i++)
        printf("%f ", values[i]);
    printf("\n");
    free(values);
}

/**
 * Creates a 2D array of values and prints out the values on the diagonal.
 */
void eight(int a) {
    int i, j;
    int** values = (int**)malloc(10 * sizeof(int*));
    for (i = 0; i < 10; i++){
        values[i] = (int*)malloc(10 * sizeof(int));
        for (j = 0; j < 10; j++) {
            values[i][j] = i * j * a;
        }
        printf("%d ", values[i][i]);
        free(values[i]);
    }
    printf("\n");
    free(values);
}

/**
 * If s points to the string "blue", then print "Orange and BLUE!". If s points
 * to the string
 * "orange", then print "ORANGE and blue!" else just print "orange and blue!".
 * Use strcmp() and
 * friends to test for string equality.
 *
 * @param s
 *     Input parameter, used to determine which string is printed.
 */
int fun(const char* s) {
    if (!strcmp(s, "blue")) {
        return 0;
    }
    else if (!strcmp(s, "orange")) {
        return 1;
    }
    return 2;
}

void nine(const char *s) {
    switch (fun(s)) {
    case 0:
        printf("Orange and BLUE!\n");
        break;

    case 1:
        printf("ORANGE and blue!\n");
        break;

    default:
        printf("orange and blue!\n");
        break;
    }
}

/**
 * Prints out the radius of a circle, given its diameter.
 *
 * @param d
 *     The diameter of the circle.
 */
void ten(const int d) {
    printf("The radius of the circle is: %f.\n", (float)d / 2);
}

/**
 * @brief
 *     Clears the bits in "value" that are set in "flag".
 *
 * This function will apply the following rules to the number stored
 * in the input parameter "value":
 * (1): If a specific bit is set in BOTH "value" and "flag", that
 *      bit is NOT SET in the result.
 * (2): If a specific bit is set ONLY in "value", that bit IS SET
 *      in the result.
 * (3): All other bits are NOT SET in the result.
 *
 * Examples:
 *    clear_bits(value = 0xFF, flag = 0x55): 0xAA
 *    clear_bits(value = 0x00, flag = 0xF0): 0x00
 *    clear_bits(value = 0xAB, flag = 0x00): 0xAB
 *
 * @param value
 *     The numeric value to manipulate.
 *
 * @param flag
 *     The flag (or mask) used in order to clear bits from "value".
 */
long int clear_bits(long int value, long int flag) {
    int index = 0;
    long int result = 0;
    while (value || flag) {
        int val = value & 1;
        int fla = flag & 1;
        if (val && !fla) {
            result += pow(2, index);
        }
        index++;
        value = value >> 1;
        flag = flag >> 1;
    }
    // TODO clear_bits
    return result;
}

/**
 * @brief
 *     A little finite automaton in C.
 *
 * This function will use a provided transition function to simulate a DFA over
 * an input string. The function returns the final state.
 *
 * The DFA starts in state 0. For each character in input_string, call the
 * transition function with the current state and the current character. The
 * current state changes to the state the transition function returns.
 *
 * So, in pseudo code:
 *
 * state = 0
 * for character in input_string:
 *     state = transition_function(state, character)
 *
 * NOTE: the transition_function parameter is a "function pointer." For more
 * information about these fun creatures, see this:
 * http://www.cprogramming.com/tutorial/function-pointers.html
 *
 * @param transition - function pointer to a transition function to use
 * @param input_string - string to run the automaton over
 *
 * @return the final state
 */
int little_automaton(int (*transition)(int, char), const char *input_string) {
    int state = 0;
    // put something here
    for (unsigned long i = 0; i < strlen(input_string); i++) {
        state = transition(state, input_string[i]);
    }
    return state;
}
