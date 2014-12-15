#include "db.h"
#include "utilities.h"

MYSQL *con;
unsigned int mysql_error_no;

int main(void)
{
    char command[MAXSIZE];
    int command_code;

    setup_db();

    do {

        PROMPT(command);
        command_code = get_command_code(command);

        switch (command_code) {

        case CMD_CREATE:
            printf("create\n");
            break;

        case CMD_READ:
            printf("read\n");
            break;

        case CMD_UPDATE:
            printf("update\n");
            break;

        case CMD_DELETE:
            printf("delete\n");
            break;

        case CMD_HELP:
            printf("help\n");
            break;
            
        }

    } while (strcmp(command, "quit") != 0);

    mysql_close(con);
    return 0;
}
