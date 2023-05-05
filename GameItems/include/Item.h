#pragma once

#include <string>

#include "GameObject.h"

class Item : public GameObject {

	protected:

		// Add properties for your object here.
		bool takeable;
		bool moveable;

	public:
		Item() : GameObject(), takeable(true), moveable(true) {
			// This is the default constructor, set sensible defaults for your properties here		
		}

		virtual bool from_json(const std::string & filename, picojson::object & json_obj) override;

		virtual bool is_item() const override { return true; }
		virtual bool can_be_taken() const override { return takeable; }

		// Accessor methods
		bool is_takeable() const { return takeable; }
		bool is_moveable() const { return moveable; }
};
