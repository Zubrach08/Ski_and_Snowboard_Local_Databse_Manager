#include <fstream>
#include <string>
#include <iostream>

using namespace std;

namespace db {

	inline void add_member(string brand, string model, string type, string subtype, string quantity_type, string quantity, string width, string height, string length) {
		fstream MyFile;
		MyFile.open("Storage.txt");
		int max_id = -1;
		string curr_word;
		do {
			MyFile >> curr_word;
			if (curr_word == "id") {
				MyFile >> curr_word;
				int tek_id = stoi(curr_word);
				if (tek_id > max_id) {
					max_id = tek_id;
				}
			}
		} while (!MyFile.eof());
		max_id++;
		MyFile.close();
		MyFile.open("Storage.txt", std::ios::out | std::ios::app);
		MyFile << endl << "id " + to_string(max_id) << endl;
		MyFile << "brand " + brand << endl;
		MyFile << "model " + model << endl;
		MyFile << "type " + type << endl;
		MyFile << "subtype " + subtype << endl;
		MyFile << "quantity type " + quantity_type << endl;
		MyFile << "quantity " + quantity << endl;
		MyFile << "width " + width << endl;
		MyFile << "height " + height << endl;
		MyFile << "length " + length << endl;
		MyFile.flush();
		MyFile.close();
	}

	inline void print_element(int id) {
		fstream MyFile;
		MyFile.open("Storage.txt");
		std::string curr_Line;
		bool flag = true;
		do {
			//std::cout << "fadsdklfj";
			MyFile >> curr_Line;
			if (curr_Line == "id") {
				MyFile >> curr_Line;
				if (curr_Line == to_string(id)) {
					flag = !flag;
				}
			}
		} while (flag);
		std::cout << "id " << id << endl;
		getline(MyFile, curr_Line);
		MyFile >> curr_Line;
		getline(MyFile, curr_Line);
		cout << "brand : " << curr_Line << endl;
		MyFile >> curr_Line;
		getline(MyFile, curr_Line);
		cout << "model : " << curr_Line << endl;
		MyFile >> curr_Line;
		getline(MyFile, curr_Line);
		cout << "type : " << curr_Line << endl;
		MyFile >> curr_Line;
		getline(MyFile, curr_Line);
		cout << "subtype : " << curr_Line << endl;
		MyFile >> curr_Line;
		MyFile >> curr_Line;
		MyFile >> curr_Line;
		std::string qt;
		if (curr_Line == "pair") qt = "pairs";
		else if (curr_Line == "1") qt = "boards";
		MyFile >> curr_Line;
		getline(MyFile, curr_Line);
		cout << "quantity : " << curr_Line << " " << qt << endl;
		MyFile >> curr_Line;
		getline(MyFile, curr_Line);
		cout << "width : " << curr_Line << endl;
		MyFile >> curr_Line;
		getline(MyFile, curr_Line);
		cout << "height : " << curr_Line << endl;
		MyFile >> curr_Line;
		getline(MyFile, curr_Line);
		std::string extra;
		MyFile >> extra;
		if (extra != "id") {
			cout << "length : " << extra << endl;
		}
		else { cout << "length : " << curr_Line << endl; }
		MyFile.close();
	}

	inline int print_quantity() {
		fstream MyFile;
		MyFile.open("Storage.txt");
		std::string curr;
		int sum = 0;
		do {
			MyFile >> curr;
			if (curr == "quantity") {
				MyFile >> curr;
				if (curr != "type") {
					//std::cout << curr;
					int tek = stoi(curr);
					sum += tek;
				}
			}

		} while (!MyFile.eof());
		MyFile.close();
		return sum;
	}
	inline void search_by_filter(std::string a, std::string b) {
		fstream MyFile;
		MyFile.open("Storage.txt");
		std::string curr_word;
		string curr_id;
		do {
			MyFile >> curr_word;
			if (curr_word == "id") {
				MyFile >> curr_id;
			}
			if (curr_word == a) {
				std::string dis;
				MyFile >> dis;
				if (dis == b) {
					print_element(stoi(curr_id));
				}
			}
		} while (!MyFile.eof());
		MyFile.close();
	}
	inline bool delete_element_by_id(int id) {
		fstream MyFile;
		MyFile.open("Storage.txt");
		std::string curr_Line;
		fstream temp;
		temp.open("temp.txt", std::ios::out, std::ios::trunc);
		int to_endl = 0;
		bool wrong_id = true;
		while (getline(MyFile, curr_Line)) {
			//std::cout << curr_Line << endl;
			//std::cout << curr_Line << " " << "id " + to_string(id) << endl;
			if (curr_Line == "id " + to_string(id)) {
				wrong_id = false;
				do {
					std::cout << "skipping to wrtie : " << curr_Line << endl;
					MyFile >> curr_Line;
				} while (curr_Line != "id" && !MyFile.eof());
				temp << endl;
				temp << "id";
			}
			else {
				temp << curr_Line;
				temp << endl;
			}
		}
		MyFile.close();
		temp.close();
		rename("temp.txt", "Storage2.txt");
		rename("Storage.txt", "temp.txt");
		rename("Storage2.txt", "Storage.txt");
		if (wrong_id) {
			return false;
		}
		return true;
	}
	inline bool change_Filter(int id, string a, string b, string c, string d) {
		fstream MyFile;
		MyFile.open("Storage.txt");
		std::string curr_Line;
		fstream temp;
		bool can_i_change = false;
		temp.open("temp.txt", std::ios::out, std::ios::trunc);
		int to_endl = 0;
		bool wrong_id = true;
		while (getline(MyFile, curr_Line)) {
			//std::cout << curr_Line << endl;
			//std::cout << curr_Line << " " << "id " + to_string(id) << endl;
			if (curr_Line == "id " + id) {
				do{
					MyFile >> curr_Line;
					if (curr_Line == a) {
						wrong_id = false;
						temp << c + " " + d;
						temp << endl;
						MyFile >> curr_Line;
					}
					else {
						temp << curr_Line;
						if (curr_Line != "brand" &&
							curr_Line != "model" &&
							curr_Line != "type" &&
							curr_Line != "subtype" &&
							curr_Line != "quantity" &&
							curr_Line != "width" &&
							curr_Line != "length" &&
							curr_Line != "height" &&
							curr_Line != "id"
							) temp << endl;
					}
					temp << " ";

				} while (curr_Line != "id" && !MyFile.eof());
				MyFile >> curr_Line;
					temp << curr_Line << endl;
			}
			
			else {
				temp << curr_Line;
				temp << endl;
			}
		}
		MyFile.close();
		temp.close();
		rename("temp.txt", "Storage2.txt");
		rename("Storage.txt", "temp.txt");
		rename("Storage2.txt", "Storage.txt");
		if (wrong_id) {
			return false;
		}
		return true;
	}


}