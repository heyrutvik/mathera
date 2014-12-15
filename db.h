
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
