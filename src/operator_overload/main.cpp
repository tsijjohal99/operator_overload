#include <iostream>
#include <map>

#include "employee_defs.h"

int main() {
    tsi::employee_name john_smith{
        tsi::first_name_t{"John"},
        tsi::last_name_t{"Smith"},
    };

    tsi::employee_info john_smith_info{
        .role = tsi::company_role::ceo,
        .id = tsi::id_t{0001},
        .dept = tsi::department::sales,
    };

    tsi::employee_name jane_doe{
        tsi::first_name_t{"Jane"},
        tsi::last_name_t{"Doe"},
    };

    tsi::employee_info jane_doe_info{
        .role = tsi::company_role::senior_manager,
        .id = tsi::id_t{1234},
        .dept = tsi::department::marketing,
    };

    std::cout << john_smith.full_name() << " comes ";
    std::cout << ((john_smith < jane_doe) ? "before " : "after ");
    std::cout << jane_doe.full_name() << '\n';

    std::map<tsi::employee_name, tsi::employee_info> employee_database{
        {john_smith, john_smith_info},
        {jane_doe, jane_doe_info},
    };

    int YoS = 1;
    for (auto& entry : employee_database) {
        entry.second += YoS++;
        std::cout << entry.first.full_name() << ' ' << entry.second << '\n';
    }
}