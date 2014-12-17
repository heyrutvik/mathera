
/*
 * common headers
 */

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

/*
 * database config
 */

#define HOST    "localhost"
#define USER    "root"
#define PASS    ""
#define DBNAME  "mathera"
#define VARCHAR 255
#define TEXT    4096

/* structure hold contribution table data */
struct contribution_data {
    int year_id;
    int name_id;
    char topic[VARCHAR];
    char description[TEXT];
};

/*
 * function prototype
 */

/* setup mysql connection */
int setup_db(void);

/* create database */
void create_database(void);

/* create table if not exist */
void create_table(void);

/* set global variable for mysql error code */
inline void set_mysql_error_no(void);

/* halt program with developer message and mysql error message */
inline void mysql_fatal_error(const char *dev_msg);

void get_by_year(int year);

void get_by_name(char *name);

void get_by_topic(char *topic);

void set_year(int year);

void set_name(char *name);

void set_topic(struct contribution_data input);

void list_year(void);

void list_name(void);
