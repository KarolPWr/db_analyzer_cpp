#pragma once

namespace db_randgen{

class DbRandgen
{
    public:
    DbRandgen();
    DbRandgen(sqlite3* DB, std::string db_name);
    ~DbRandgen();

    private:
    void create_db();
    void create_data();
    void fill_db();

};

}
