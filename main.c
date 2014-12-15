#include "db.h"

MYSQL *con;
unsigned int mysql_error_no;

int main(void)
{
    setup_db();
    mysql_close(con);
    return 0;
}
