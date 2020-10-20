#include <iostream> 
#include <sqlite3.h> 

namespace db_randgen{

class DbRandgen
{
    public:
    sqlite3& local_db;

    DbRandgen();
    DbRandgen(sqlite3* DB, std::string db_name);
    ~DbRandgen();


    private:
    void create_db();
    void create_data();
    void fill_db();

};

DbRandgen::DbRandgen()
{
    std::cout<< "Created class DbRandgen" << std::endl;
}

DbRandgen::DbRandgen(sqlite3* DB, std::string db_name): local_db(DB)
{
    std::cout<< "Created class DbRandgen DB name: " << db_name << std::endl;
}

DbRandgen::~DbRandgen()
{
    std::cout<< "Destroyed class DbRandgen" << std::endl;

}

}