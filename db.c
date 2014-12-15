#include "db.h"
#include <mysqld_error.h>
#include <errmsg.h>

extern MYSQL *con;
extern unsigned int mysql_error_no;

int setup_db(void)
{
    /* initialises a MYSQL object */
    con = mysql_init(NULL);
    if (con == NULL)
        mysql_fatal_error("main");

    /* connect mysql with database */
    mysql_real_connect(con, HOST, USER, PASS, DBNAME, 0, NULL, 0);

    /* set error number for switch case */
    set_mysql_error_no();

    switch(mysql_error_no) {

    case ER_BAD_DB_ERROR:
        create_database();
        break;

    }

    create_table();

    return 0;
}

void create_database(void)
{
    /* connect mysql without database name */
    mysql_real_connect(con, HOST, USER, PASS, NULL, 0, NULL, 0);
    
    /* create database */
    if (mysql_query(con, "CREATE DATABASE " DBNAME)) {
        mysql_fatal_error(NULL);
    }

    /* re-establish connection with database */
    mysql_close(con);
    con = mysql_init(NULL);
    if (mysql_real_connect(con, HOST, USER, PASS, DBNAME, 0, NULL, 0) == NULL)
        mysql_fatal_error(NULL);

}

void create_table(void)
{
    /* table contribution */
    char *contribution = "\
        CREATE TABLE IF NOT EXISTS `contribution` (\
          `id` int(11) NOT NULL AUTO_INCREMENT,\
          `year_id` int(11) DEFAULT NULL,\
          `name_id` int(11) DEFAULT NULL,\
          `topic` varchar(255) DEFAULT NULL,\
          `description` text,\
          PRIMARY KEY (`id`)\
        ) ENGINE=InnoDB DEFAULT CHARSET=utf8";

    if (mysql_query(con, contribution)) {
        //printf("%s\n", contribution);
        mysql_fatal_error(NULL);
    }

    /* table name */
    char *name = "\
        CREATE TABLE IF NOT EXISTS `name` (\
          `id` int(11) NOT NULL AUTO_INCREMENT,\
          `name` varchar(255) NOT NULL,\
          PRIMARY KEY (`id`)\
        ) ENGINE=InnoDB DEFAULT CHARSET=utf8";

    if (mysql_query(con, name)) {
        //printf("%s\n", name);
        mysql_fatal_error(NULL);
    }

    /* table year */
    char *year = "\
        CREATE TABLE IF NOT EXISTS `year` (\
          `id` int(11) NOT NULL AUTO_INCREMENT,\
          `year` int(4) NOT NULL,\
          PRIMARY KEY (`id`)\
        ) ENGINE=InnoDB DEFAULT CHARSET=utf8";
    
    if (mysql_query(con, year)) {
        //printf("%s\n", year);
        mysql_fatal_error(NULL);
    }
}

inline void set_mysql_error_no(void)
{
    mysql_error_no = mysql_errno(con);
}

inline void mysql_fatal_error(const char *dev_msg)
{
    fprintf(stderr, "%s: (%u)%s\n", dev_msg, mysql_errno(con), mysql_error(con));
    mysql_close(con);
    exit(1);
}
