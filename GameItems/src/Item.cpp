#include "Item.h"

#include <picojson.h>
#include "json_utils.h"

bool Item::from_json(const std::string & filename, picojson::object & json_obj) {

	if (!GameObject::from_json(filename, json_obj))
		return false;

	if (has_field<bool>(json_obj, "Takeable")) {
		takeable = json_obj["Takeable"].get<bool>();
	} else {
		std::cerr << "filename: " << filename << " does not contain a Takeable property (or it is not a boolean)" << std::endl;
		return false;
	}

	if (has_field<bool>(json_obj, "Moveable")) {
		moveable = json_obj["Moveable"].get<bool>();
	} else {
		std::cerr << "filename: " << filename << " does not contain a Moveable property (or it is not a boolean)" << std::endl;
		return false;
	}

	return true;
}
