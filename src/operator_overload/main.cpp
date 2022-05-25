#include "employee_defs.h"

int main()
{
	tsi::employee_name john_smith{
		.first_name = tsi::first_name_t{"John"},
		.last_name = tsi::last_name_t{"Smith"},
	};

	tsi::employee_info john_smith_info{
		.role = tsi::company_role::ceo,
		.id = tsi::id_t{0001},
		.dept = tsi::department::sales
	};

	tsi::employee_name jane_doe{
		.first_name = tsi::first_name_t{"Jane"},
		.last_name = tsi::last_name_t{"Doe"},
	};

	tsi::employee_info jane_doe_info{
		.role = tsi::company_role::senior_manager,
		.id = tsi::id_t{1234},
		.dept = tsi::department::marketing
	};
}