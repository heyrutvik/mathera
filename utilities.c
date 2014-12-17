#include "db.h"
#include "utilities.h"
//#include <stdio.h>

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

void print_row(MYSQL_ROW row)
{
    /* id | year | name */
    printf("%s | %s | %s\n", row[0], row[1], row[2]);
    /* topic */
    printf("%s\n", row[3]);
    /* description */
    printf("%s\n", row[4]);
    printf("\n");
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

        get_by_name(query);

    } else if (!strcmp(sub_command, "topic")) {

        get_by_topic(query);

    } else {

        call_help();

    }
}

void call_create(const char *string)
{
    char command[5];
    char sub_command[6];
    char query[20];
    sscanf(string, "%s %s %s", command, sub_command, query);

    if (!strcmp(sub_command, "year")) {

        set_year(atoi(query));

    } else if (!strcmp(sub_command, "name")) {

        set_name(query);

    } else if (!strcmp(sub_command, "topic")) {

        struct contribution_data input;

        /* list id/year */
        list_year();
        printf("enter year id: ");
        scanf("%d", &input.year_id);

        /* list id/name */
        list_name();
        printf("enter name id: ");
        scanf("%d", &input.name_id);

        CLEAR_STDIN;
        printf("enter topic: ");
        fgets(input.topic, 255, stdin);
        REPLACE_NL_NC(input.topic);

        CLEAR_STDIN;
        printf("enter description: ");
        fgets(input.description, MAXSIZE, stdin);
        REPLACE_NL_NC(input.description);

        set_topic(input);

    } else {

        call_help();

    }
}
