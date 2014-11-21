#include <string>
#include <cstring>
#include <iostream>
#include "mysql.hpp"

void fetch_from_test(mysql& sql) {
    Result r = sql.query("SELECT `id`, `name` FROM `test`");
    if (!r) return;
    while (Row row = r.next()) {
        std::cout << std::stoi(row[0]) << "\t" << row[1] << "\n";
    }
}

void insert_into_test(mysql& sql) {
    Stmt stmt = sql.prepare("INSERT INTO `test` (`name`) VALUES (?)");
    if (!stmt) return;
    std::string s;
    while (getline(std::cin, s)) {
        stmt.execute(s);
    }
}

void delete_from_test(mysql& sql) {
    Stmt stmt = sql.prepare("DELETE FROM `test` WHERE `id` = ?");
    if (!stmt) return;
    std::string s;
    while (getline(std::cin, s)) {
        stmt.execute(s);
    }
}

int main()
{
    mysql sql{};
    if (!sql.connect("localhost", "test", "test", "test", 0, 0, 0)) {
        return 1;
    }
    fetch_from_test(sql);
    //delete_from_test(sql);
    insert_into_test(sql);
    fetch_from_test(sql);
}

