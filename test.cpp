#include <string>
#include <cstring>
#include <iostream>
#include "mysql.hpp"

void fetch_from_test(mysql& sql) {
    Result r = sql.query("SELECT `id`, `name` FROM `test`");
    while (Row row = r.fetch_row()) {
        std::cout << std::stoi(row[0]) << "\t" << row[1] << "\n";
    }
}

void delete_from_test(mysql& sql)
{
    Stmt stmt = sql.prepare("DELETE FROM `test` WHERE `id` = ?");
    std::string s;
    while (getline(std::cin, s)) {
        stmt.execute(s);
    }
}

int main()
{
    mysql sql{};
    sql.connect("localhost", "test", "test", "test", 0, 0, 0);

    delete_from_test(sql);
    fetch_from_test(sql);
}

