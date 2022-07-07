#include <iostream>
#include <mysql.h>
#include <ostream>

struct connection_details
{
	const char* server, * user, * password, * database;
};

MYSQL* mysql_connection_setup(struct connection_details mysql_details) {
	MYSQL* connection = mysql_init(NULL);

	if (!mysql_real_connect(connection, mysql_details.server, mysql_details.user, mysql_details.password, mysql_details.database, 0, NULL, 0)) {
		std::cout << "Connection Error: " << mysql_error(connection) << std::endl;
		exit(1);
	}

	return connection;
}

MYSQL_RES* mysql_perform_query(MYSQL* connection, const char* sql_query) {
	if (mysql_query(connection, sql_query)) {
		std::cout << "MySQL Query Error: " << mysql_error(connection) << std::endl;
		exit(1);
	}

	return mysql_use_result(connection);
}

void database_query()
{
	MYSQL* con;	// the connection
	MYSQL_RES* res;	// the results
	MYSQL_ROW row;	// the results rows (array)

	struct connection_details mysqlD;
	mysqlD.server = "localhost";  // where the mysql database is
	mysqlD.user = "root"; // user
	mysqlD.password = "sql12345!"; // the password for the database
	mysqlD.database = "bankappcpp";	// the databse

	// connect to the mysql database
	con = mysql_connection_setup(mysqlD);

	res = mysql_perform_query(con, "select * from users;");

	std::cout << ("Database Output:\n") << std::endl;

	while ((row = mysql_fetch_row(res)) != NULL) {
		// the below row[] parametes may change depending on the size of the table and your objective
		std::cout << row[0] << " | " << row[1] << std::endl << std::endl;
	}

	mysql_free_result(res);

	// close database connection
	mysql_close(con);
}