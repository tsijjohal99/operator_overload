#pragma once
#include <array>
#include <string>

#include "named_type.h"

namespace tsi {
    using first_name_t = named_type<std::string, struct first_name_tag>;
    using last_name_t = named_type<std::string, struct last_name_tag>;
    using id_t = named_type<unsigned int, struct id_tag>;

    enum class company_role {
        ceo,
        executive,
        director,
        senior_manager,
        manager,
        employee
    };

    enum class department {
        sales,
        marketing,
        product,
        development,
        support,
        HR
    };

    constexpr static std::array company_role_str{
        "ceo",
        "executive",
        "director",
        "senior_manager",
        "manager",
        "employee",
    };

    constexpr static std::array department_str{
        "sales",
        "marketing",
        "product",
        "development",
        "support",
        "HR",
    };

    struct employee_name {
       private:
        first_name_t first_name;
        last_name_t last_name;

       public:
        explicit employee_name(const first_name_t& first, const last_name_t& last) : first_name(first), last_name(last) {}
        std::string full_name() const { return first_name.get() + ' ' + last_name.get(); }

        friend std::weak_ordering operator<=>(const employee_name& lhs, const employee_name& rhs);
        friend bool operator==(const employee_name& lhs, const employee_name& rhs);

        // bool operator<(const employee_name& rhs) const {
        //     return last_name.get() < rhs.last_name.get();
        // }
    };

    struct employee_info {
        company_role role;
        id_t id;
        department dept;
        int years_of_service{0};

        // Prefix increment
        employee_info& operator++() {
            ++years_of_service;
            return *this;
        }

        // Postfix increment
        employee_info operator++(int) {
            employee_info orig = *this;
            operator++();
            return orig;
        }

        employee_info& operator+=(int n) {
            years_of_service += n;
            return *this;
        }
    };

    std::weak_ordering operator<=>(const employee_name& lhs, const employee_name& rhs) {
        return lhs.last_name.get() <=> rhs.last_name.get();
    }

    bool operator==(const employee_name& lhs, const employee_name& rhs) {
        return lhs.last_name.get() == rhs.last_name.get();
    }

    std::ostream& operator<<(std::ostream& os, const employee_info& info) {
        os << "Role: " << company_role_str[static_cast<int>(info.role)] << ' ';
        os << "ID: " << info.id.get() << ' ';
        os << "Role: " << department_str[static_cast<int>(info.dept)] << ' ';
        os << "YoS: " << info.years_of_service << ' ';
        return os;
    }

}  // namespace tsi