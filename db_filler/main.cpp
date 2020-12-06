/* Create DB with two columns and fill it with random data */


#include <iostream> 
#include <sqlite3.h> 
#include <string>
#include <stdio.h>

//user includes
#include "db_randgen.hpp"
  
int main(int argc, char** argv) 
{

    
    sqlite3* DB; 
    auto exit = 0; 
    auto rc = 0;
    char *zErrMsg = 0;
    exit = sqlite3_open("example.db", &DB); 
    // db_randgen::DbRandgen my_randgen{DB, "name"};
  
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

    /* Create SQL statement */
    std::string sql = "CREATE TABLE TEST("  \
        "ID INT PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL," \
        "AGE            INT     NOT NULL," \
        "ADDRESS        CHAR(50)," \
        "SALARY         REAL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(DB, sql.c_str(), NULL, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(DB); 
    return (0); 
} 
