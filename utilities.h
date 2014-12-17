#include <string.h>

#define MAXSIZE 4096

/* replace new line with null character */
#define REPLACE_NL_NC(x) {\
                            x[strlen(x) - 1] = '\0';\
                        }

/* command prompt */
#define PROMPT(x)   {\
                            printf("mathera > ");\
                            fgets(x, MAXSIZE, stdin);\
                            REPLACE_NL_NC(x);\
                        }

/* clear stdin */
#define CLEAR_STDIN {\
                while(getchar() != '\n');\
                }

#define CMD_CREATE  1
#define CMD_READ    2
#define CMD_UPDATE  3
#define CMD_DELETE  4
#define CMD_HELP    5
#define CMD_QUIT    6

int get_command_code(const char *command);

void call_read(const char *command);
void call_create(const char *command);
void call_help(void);

/* temporary function to print row of `read` command */
void print_row(MYSQL_ROW row);
