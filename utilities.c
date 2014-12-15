#include "utilities.h"
#include <stdio.h>

int get_command_code(const char *command)
{
    char word[6];
    sscanf(command, "%s", word);
    
    if (!strcmp(word, "create"))
        return CMD_CREATE;
    else if (!strcmp(word, "read"))
        return CMD_READ;
    else if (!strcmp(word, "update"))
        return CMD_UPDATE;
    else if (!strcmp(word, "delete"))
        return CMD_DELETE;
    else if (!strcmp(word, "quit"))
        return CMD_QUIT;
    else
        return CMD_HELP;
}
