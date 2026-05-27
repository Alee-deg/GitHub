#include<iostream>
#include<mysql/mysql.h>
#include<sstream>
#include<mysql/mysqld_error.h>
#include<thread>
#include<chrono>

using namespace std; 

const char* HOST = "localhost";
const char* USER = "root"; 
const char* PW = "Haule@123"; 
const char* DB = "mydb"; 



int main(){
    MYSQL* conn; 
    conn = mysql_init(NULL); 
    if(!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0)){
        cout << "ERROR: " << mysql_error(conn) << endl; 
    }
    else{
        cout << "Logged in Database" << endl; 
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
    return 0; 
}

