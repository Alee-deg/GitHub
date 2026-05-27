#ifndef DATABASE_H
#define DATABASE_H
#include<pqxx/pqxx>
#include<string>
#include<iostream>
using namespace std; 
class DatabaseManager{
    private:
    std::string conn_str = "host=localhost dbname=postgres user=alee password=123456"; 
    public:
    void createSchema(); 
    string getConn_str() const; 
}; 
#endif