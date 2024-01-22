#pragma once

#include<string>
class Ski
{	
	public:
		int id;
		std::string brand;
		std::string model;
		std::string type;
		int quantity;
		std::string quantity_type;
		double price;
		std::string ski_type;
		Ski(int _id, std::string _brand, std::string _model, std::string _type, std::string _ski_type,
			double _price, int _quantity, std::string _quantity_type)
		{
			id = _id;
			brand = _brand;
			model = _model;
			type = _type;
			ski_type = _ski_type;
			price = _price;
			quantity = _quantity;
			quantity_type = _quantity_type;

		}
};
