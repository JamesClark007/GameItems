#pragma once

#include "Item.h"
#include <string>

class UseableItem : public Item {
public:
    UseableItem();
    UseableItem(const std::string& affectedItems, const std::string& affectedMethod);
    virtual ~UseableItem();

    // Getters and setters for affected items and methods
    std::string getAffectedItems() const;
    void setAffectedItems(const std::string& affectedItems);
    std::string getAffectedMethod() const;
    void setAffectedMethod(const std::string& affectedMethod);

    // Method to use the item on another game object
    void use(GameObject& target);
    virtual bool from_json(const std::string & filename, picojson::object & json_obj) override;

protected:
    std::string AffectedItems;
    std::string AffectedMethod;
};
