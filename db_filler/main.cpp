/* Create DB with two columns and fill it with random data */


#include <iostream> 
#include <sqlite3.h> 

//user includes
#include "db_randgen.hpp"
  
int main(int argc, char** argv) 
{

    
    sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("example.db", &DB); 
    db_randgen::DbRandgen my_randgen{DB, "name"};
  
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
    sqlite3_close(DB); 
    return (0); 
} 