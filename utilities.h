#include <string.h>

#define MAXSIZE 255
#define PROMPT(x)   {\
                            printf("mathera > ");\
                            fgets(x, MAXSIZE, stdin);\
                            x[strlen(x) - 1] = '\0';\
                        }
#define CMD_CREATE  1
#define CMD_READ    2
#define CMD_UPDATE  3
#define CMD_DELETE  4
#define CMD_HELP    5
#define CMD_QUIT    6

int get_command_code(const char *command);

void call_read(const char *command);
void call_help(void);
