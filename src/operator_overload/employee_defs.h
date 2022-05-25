#pragma once
#include "named_type.h"
#include <string>

namespace tsi
{
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

	struct employee_name
	{
		first_name_t first_name;
		last_name_t last_name;

		std::string full_name() { return first_name.get() + ' ' + last_name.get(); }
	};

	struct employee_info
	{
		company_role role;
		id_t id;
		department dept;
	};

}