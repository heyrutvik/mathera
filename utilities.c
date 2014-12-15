#include "utilities.h"
#include "db.h"
#include <stdio.h>

int get_command_code(const char *string)
{
    char command[6];
    sscanf(string, "%s", command);
    
    if (!strcmp(command, "create"))
        return CMD_CREATE;
    else if (!strcmp(command, "read"))
        return CMD_READ;
    else if (!strcmp(command, "update"))
        return CMD_UPDATE;
    else if (!strcmp(command, "delete"))
        return CMD_DELETE;
    else if (!strcmp(command, "quit"))
        return CMD_QUIT;
    else
        return CMD_HELP;
}

void call_help(void)
{
    printf("\nmathEra utility help\n");
    
    char *read = "\tread year ___\n\tread name ___\n\tread topic ___\n";
    printf("%s\n", read);
}

void call_read(const char *string)
{
    char command[5];
    char sub_command[6];
    char query[20];
    sscanf(string, "%s %s %s", command, sub_command, query);
    
    if (!strcmp(sub_command, "year")) {
        get_by_year(atoi(query));
    } else if (!strcmp(sub_command, "name")) {
        //get_by_name(query);
    } else if (!strcmp(sub_command, "topic")) {
        //get_by_topic(query);
    } else {
        call_help();
    }
}
