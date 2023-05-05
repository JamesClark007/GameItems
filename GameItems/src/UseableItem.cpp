#include "UseableItem.h"
#include "picojson.h"
#include "json_utils.h"

UseableItem::UseableItem() : Item(), AffectedItems(""), AffectedMethod("") {}

UseableItem::UseableItem(const std::string& affectedItems, const std::string& affectedMethod)
    : Item(), AffectedItems(affectedItems), AffectedMethod(affectedMethod) {}

UseableItem::~UseableItem() {}

std::string UseableItem::getAffectedItems() const {
    return AffectedItems;
}

void UseableItem::setAffectedItems(const std::string& affectedItems) {
    AffectedItems = affectedItems;
}

std::string UseableItem::getAffectedMethod() const {
    return AffectedMethod;
}

void UseableItem::setAffectedMethod(const std::string& affectedMethod) {
    AffectedMethod = affectedMethod;
}

void UseableItem::use(GameObject& target) {
    // Implement the interaction between the UseableItem and the target game object here
}

bool UseableItem::from_json(const std::string &filename, picojson::object &json_obj) {
    // Call the superclass from_json method
    if (!Item::from_json(filename, json_obj))
        return false;

    // Deserialize the affected items and methods
    if (has_field<std::string>(json_obj, "AffectedItems")) {
        setAffectedItems(json_obj["AffectedItems"].get<std::string>());
    } else {
        std::cerr << "filename: " << filename << " does not contain an AffectedItems property (or it is not a string)" << std::endl;
        return false;
    }

    if (has_field<std::string>(json_obj, "AffectedMethod")) {
        setAffectedMethod(json_obj["AffectedMethod"].get<std::string>());
    } else {
        std::cerr << "filename: " << filename << " does not contain an AffectedMethod property (or it is not a string)" << std::endl;
        return false;
    }

    return true;
}
