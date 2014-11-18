## NAME

mysql-cpp - a wrapper around libmysqlclient

## SYNOPSYS

    #include <string>
    #include <cstring>
    #include <iostream>
    #include "mysql.hpp"

    int main()
    {
        mysql sql{};

        sql.connect("localhost", "test", "test", "test", 0, 0, 0);

        {
            Stmt stmt = sql.prepare("DELETE FROM `test` WHERE `id` = ?");
            std::string s;
            while (std::cin) {
                getline(std::cin, s);
                if (s.size() == 0) break;
                stmt.execute(s);
            }
        }

        Result r = sql.query("SELECT `id`, `name` FROM `test`");

        while (Row row = r.fetch_row()) {
            std::cout << std::stoi(row[0]) << "\t" << row[1] << "\n";
        }
    }

