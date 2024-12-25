#include "evaluate.h"

char *expression_start;

char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; (tmp = strstr(ins, rep)); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}


int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage:\n");
        printf("  yac -e expression\n");
        printf("  yac -f function min max step\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-e") == 0 && argc == 3) {
        char *expression = argv[2];
        printf("Evaluating expression: %s\n", expression);
        evaluate(expression);
    } else if (strcmp(argv[1], "-f") == 0 && argc == 6) {
        char *function = argv[2];
        float min = atof(argv[3]);
        float max = atof(argv[4]);
        float step = atof(argv[5]);

        for (float i = min; i <= max; i += step) {
            char buffer[64];
            snprintf(buffer, sizeof(buffer), "%f", i);

            char *current_function = str_replace(function, "X", buffer);
            char *formatted_function = str_replace(current_function, " ", "");

            if (!formatted_function) {
                fprintf(stderr, "Error replacing string.\n");
                free(current_function);
                return EXIT_FAILURE;
            }

            evaluate(formatted_function);

            free(current_function);
            free(formatted_function);
        }
    } else {
        printf("Invalid arguments.\n");
        printf("Usage:\n");
        printf("  yac -e expression\n");
        printf("  yac -f function min max step\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

