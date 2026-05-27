#include "Database.h"

void DatabaseManager::createSchema(){
    try {
        pqxx::connection C(conn_str);
        pqxx::work W(C);

            // 1. Tạo bảng Book (Thông tin sách)
        W.exec("create schema if not exists csdl_library"); 
        W.exec("set search_path to csdl_library"); 
        W.exec(R"(
            CREATE TABLE IF NOT EXISTS book (
                id_book VARCHAR(50) PRIMARY KEY,
                author TEXT NOT NULL,
                title TEXT NOT NULL,
                price NUMERIC(10, 2),
                intro TEXT,
                quantity INT DEFAULT 0
            );
        )");

            // 2. Tạo bảng BorrowerRecord (Thông tin người mượn)
        W.exec(R"(
            CREATE TABLE IF NOT EXISTS borrower_record (
                id_borrower VARCHAR(50) PRIMARY KEY,
                name TEXT NOT NULL,
                phone VARCHAR(20),
                violations INT DEFAULT 0,
                status varchar(20) default 'binh thuong'
            );
        )");

            // 3. Tạo bảng Library (Nhật ký mượn trả)
        W.exec(R"(
            CREATE TABLE IF NOT EXISTS library_transaction (
                id_transaction SERIAL PRIMARY KEY,
                id_book VARCHAR(50) REFERENCES book(id_book),
                id_borrower VARCHAR(50) REFERENCES borrower_record(id_borrower),
                borrowed_day DATE DEFAULT CURRENT_DATE,
                return_day DATE,
                status varchar(20)
            );
        )");

            // 4. Tạo bảng FeePenalty (Quản lý tiền phạt)
        W.exec(R"(
            CREATE TABLE IF NOT EXISTS fee_penalty (
                id_penalty SERIAL PRIMARY KEY,
                id_borrower VARCHAR(50) REFERENCES borrower_record(id_borrower),
                penalty_day DATE DEFAULT CURRENT_DATE,
                payment_deadline DATE,
                penalty_fee NUMERIC(10, 2),
                penalty_reason TEXT,
                status TEXT
            );
        )");
        W.commit();
    }
    catch (const std::exception &e) {
        std::cerr << "Loi: " << e.what() << std::endl;
    }
}
string DatabaseManager::getConn_str() const{return this -> conn_str;}