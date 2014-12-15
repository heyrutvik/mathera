#include "db.h"
#include "utilities.h"

MYSQL *con;
unsigned int mysql_error_no;

int main(void)
{
    char string[MAXSIZE];
    int command_code;

    setup_db();

    do {

        PROMPT(string);
        command_code = get_command_code(string);

        switch (command_code) {

        case CMD_CREATE:
            printf("create\n");
            break;

        case CMD_READ:
            call_read(string);
            break;

        case CMD_UPDATE:
            printf("update\n");
            break;

        case CMD_DELETE:
            printf("delete\n");
            break;

        case CMD_HELP:
            call_help();
            break;
            
        }

    } while (strcmp(string, "quit") != 0);

    mysql_close(con);
    return 0;
}
