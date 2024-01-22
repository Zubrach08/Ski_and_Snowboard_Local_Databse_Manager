#include "Data.hpp"
#include <iostream>
namespace cmdex {
	bool decide_to_continue() {
		std::cout << "Press 0 to exit \n";
		std::cout << "Press 1 if you'd like to continue";
		std::cout << ": ";
		int a;
		std::cin >> a;
		if (a == 1) return true;
		return false;
	}

	bool Execute_Command(int command_type) {
		bool er = true;
		if (command_type == 0) {
			er = false;
		}else
		if (command_type == 1) {
			std::cout << db::print_quantity() << std::endl;
			er = decide_to_continue();
		}else
		if (command_type == 3) {
			std::cout << "Enter type of filter (brand, model, type, subtype, qantity, widght, height): \n";
			std::string a;
			std::cin >> a;
			std::cout << "Enter searched " << a << "(put underscores inbetween words of the filter): \n";
			std::string b;
			cin >> b;
			db::search_by_filter(a, b);
			er = decide_to_continue();
		}else
		if (command_type == 2) {
			std::cout << "Enter wanted id : ";
			int id;
			std::cin >> id;
			db::print_element(id);
			er = decide_to_continue();
		}else
			if (command_type == 4) {
				int id;
				int itt = 0;
				do {
					if (itt > 0) {
						std::cout << "Wrong id, try again\n";
					}
					itt++;
					std::cout << "Enter wanted id : ";
					std::cin >> id;
				} while (!db::delete_element_by_id(id));

				
				//std::cout << "not currently implemented\n";
			er = decide_to_continue();
		}else
			if(command_type == 5){
				std::cout << "Enter id for the product whose filter isbeing replaced : ";
				int id;
				std::cin >> id;
				std::cout << endl;
				std::string b;
				std::cout << "Enter type of filter (brand, model, type, subtype, qantity, widght, height): \n";
				std::string a;
				std::cin >> a;
				std::cout << "Enter what the filter will be replaced by: \n";
				std::string c;
				cin >> c;
				db::change_Filter(id, a, b, a, c);
				er = decide_to_continue();
		}else
			if (command_type == 6) {
				std::string brand;
				std::string model;
				std::string type;
				std::string subtype;
				std::string quantity;
				std::string quantity_type;
				std::string width;
				std::string height;
				std::string length;
				std::cout << "(put underscores inbetween words of the filter): \n";
				std::cout << "Enter brand : "; cin >> brand;
				std::cout << "Enter model : "; cin >> model;
				std::cout << "Enter type : "; cin >> type;
				std::cout << "Enter subtype : "; cin >> subtype;
				std::cout << "Enter quantity type : "; cin >> quantity_type;
				std::cout << "Enter quantity : "; cin >> quantity;
				std::cout << "Enter width : "; cin >> width;
				std::cout << "Enter height : "; cin >> height;
				std::cout << "Enter length : "; cin >> length;
				db::add_member(brand, model, type, subtype, quantity_type, quantity, width, height, length);
				er = decide_to_continue();
			}
		return er;
	}

	

}