#include "db.h"

MYSQL *con;
unsigned int mysql_error_no;

int main(void)
{
    printf("hello, world\n");
    setup_db();
    mysql_close(con);
    return 0;
}
