#include<iostream>
#include<string>
#include<pqxx/pqxx>
#include<thread>
#include<chrono>
#include "Database.h"
#include "Library.h"
#include "Book.h"
#include "BorrowerRecord.h"

using namespace std; 

void Intro(){
    system("clear");
    cout << "\n\n\n\n\t\t\t"; 
    for(int i = 1; i <= 63; i++){cout << "*";}
    cout << "\n\t\t\t "; 
    for(int i = 1; i <= 61; i ++){cout << "*";}
    cout << "\n\t\t\t  "; 
    for(int i = 1; i <= 59; i++){cout << "*";}
    cout << "\n\t\t\t\t\t    LIBRARY MANAGER SYSTEM";
    cout << "\n\t\t\t  "; 
    for(int i = 1; i <= 59; i ++){cout <<"*";}
    cout << "\n\t\t\t "; 
    for(int i = 1; i <= 61; i++){cout << "*";}
    cout << "\n\t\t\t"; 
    for(int i = 1; i <= 63; i ++){cout << "*";};
    cout << "\n";  
    cin.get(); 
    system("clear"); 
}; 
void Login(){
    int count = 2; 
    string userName, password; 
    while(1){
        system("clear"); 
        cout << "\n\n\t\t\t\t\t\tLogin"; 
        if(count != 2){
            cout << "\n\t\t\tYou have " << count + 1 << " attempts left to enter your username and password!"; 
        }
        cout << "\n\t\t\tUserName: ";
        cin >> userName; 
        system("stty -echo"); 
        cout << "\n\t\t\tPassword: "; 
        cin >> password; 
        system("stty echo"); 
        if(userName == "Haule0915" && password == "12345"){
            cout << "\n\t\t\t\t\tLogin Successfully..."; 
            cout << "\n\t\t\t\t\tPress enter to continue!"; 
            cin.ignore(); 
            cin.get(); 
            return; 
        }
        else if(count == 0){
            for(int i = 5; i > 0; i --){
                cout << "\r\t\t\tToo many failed attempts. Retrying in " << i << " seconds... " << flush; 
                std::this_thread::sleep_for(std::chrono::seconds(1)); 
            }
            cout << "\r\t\t\tYou can now try to login again.                      " << endl;
            count = 2;
            cin.ignore();
            cin.get();
        }
        else{
            cout << "\n\t\t\t\t\t\t\t\tInvalid Username & Password\n"; 
            cin.ignore(); 
            cin.get(); 
            count --; 
        }
    }
}
class getDataFromDB{
    public:
    void getBook(string conn_str, Library &LB){
        try{
            string g_id, g_author, g_title, g_intro;
            double g_price;
            int g_quantity; 
            pqxx::connection C(conn_str); 
            if(C.is_open()){
                pqxx::nontransaction N(C); 
                N.exec("set search_path to csdl_library;"); 
                pqxx::result R = N.exec("select * from book;");
                for(const auto &row : R){
                    g_id = row[0].as<string>();
                    g_author = row[1].as<string>(); 
                    g_title = row[2].as<string>(); 
                    g_price = row[3].as<double>(); 
                    g_intro = row[4].as<string>(); 
                    g_quantity = row[5].as<int>(); 
                    Book* newBook = new Book(g_id, g_author, g_title, g_intro, g_price, g_quantity); 
                    LB.p_addBook(g_id, newBook); 
                }
            }
            else{
                throw std::runtime_error("Cannot open database"); 
            }
        }
        catch(const pqxx::sql_error& e){
            std::cerr << "ERROR: " << e.what() << endl; 
            cin.ignore(); 
            cin.get(); 
        }
    }
    void getBorrowerRecord(string conn_str, Library &LB){
        try{
            string g_id, g_name, g_phone, g_status; 
            int g_nbVio; 
            pqxx::connection C(conn_str); 
            pqxx::nontransaction N(C);
            N.exec("set search_path to csdl_library;");  
            string sql = "select * from borrower_record;"; 
            pqxx::result R = N.exec(sql); 
            for(const auto &row : R){
                g_id = row[0].as<std::string>(); 
                g_name = row[1].as<std::string>(); 
                g_phone = row[2].as<std::string>(); 
                g_nbVio = row[3].as<int>(); 
                g_status = row[4].as<std::string>(); 
                BorrowerRecord *newBor = new BorrowerRecord(g_id, g_name, g_phone, g_nbVio, g_status); 
                LB.p_addBorrowerRecord(g_id, newBor); 
            }
        }
        catch(const std::exception& e){
            std::cerr << "ERROR: " << e.what() << std::endl; 
        }
    }
}; 
int main(){
    Intro(); 
    Login();
    DatabaseManager DB; 
    getDataFromDB get; 
    Library LB("HCMUS");
    get.getBorrowerRecord(DB.getConn_str(), LB); 
    get.getBook(DB.getConn_str(), LB); 
    DB.createSchema(); 
    LB.menu(); 
    return 0; 
}