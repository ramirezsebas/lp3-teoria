#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

const char *program_name;

void print_usage(FILE *stream, int exit_code)
{
    fprintf(stream, "Usage: %s options [ inputfile ... ]\n", program_name);
    fprintf(stream,
            " -h --help Display this usage information.\n"
            " -o --output filename Write output to file.\n"
            " -v --verbose Print verbose messages.\n");
    exit(exit_code);
}

int main(int argc, char const *argv[])
{
    int next_option;
    /* A string listing valid short options letters. */
    const char *const short_options = "ho:v";

    const struct option long_options[] = {
        {"help", 0, NULL, 'h'},
        {"output", 1, NULL, 'o'},
        {"verbose", 0, NULL, 'v'},
        {NULL, 0, NULL, 0}};

    const char *output_filename = NULL;
    /* Whether to display verbose messages. */
    int verbose = 0;
    /* Remember the name of the program, to incorporate in messages.
    The name is stored in argv[0]. */
    program_name = argv[0];
    printf(program_name);
    do{
        next_option = getopt_long(argc, argv, short_options,
                                  long_options, NULL);
        switch (next_option){
        case 'h': /* -h or --help */
            /* User has requested usage information. Print it to standard
            output, and exit with exit code zero (normal termination). */
            print_usage(stdout, 0);
        case 'o': /* -o or --output */
            /* This option takes an argument, the name of the output file. */
            output_filename = optarg;
            break;
        case 'v': /* -v or --verbose */
            verbose = 1;
            break;
        case '?': /* The user specified an invalid option. */
            /* Print usage information to standard error, and exit with exit
code one (indicating abnormal termination). */
            print_usage(stderr, 1);
        case -1: /* Done with options. */
            break;
        default: /* Something else: unexpected. */
            abort();
        }
    } while (next_option != -1);

    if (verbose)
    {
        int i;
        for (i = optind; i < argc; ++i)
            printf("Argument: %s\n", argv[i]);
    }
    return 0;
}
