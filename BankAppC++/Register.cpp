#include <iostream>
#include <string>
#include "Register.h"

#include <fstream>

#include "Customer.h"
#include <nlohmann/json.hpp>

void Register()
{
	std::string username;
	std::string password;
	std::hash <std::string> hash;

	std::cout << "Username: "; std::cin >> username;
	std::cout << "Password: "; std::cin >> password;

	Customer customer(username, password);


	nlohmann::json cus;

	cus["name"] = customer.Username;
	cus["password"] = hash(customer.Password);


	/*nlohmann::json cus = nlohmann::json::parse(customer);

	std::ofstream o(customer.Username + ".json");
	o << std::setw(4) << cus << std::endl;
	o.close();*/
	
	/*cus["name"] = customer.Username;
	cus["password"] = hash(password);*/


	/*std::string fileName = "Customers.json";
	if(check_if_file_exists(fileName))
	{
		std::cout << "Thank you for registering." << std::endl;
		return;
	}
	std::ofstream o(fileName);
	o << std::setw(2) << cus << std::endl;

	o.close();*/

	std::cout << "Thank you for registering." << std::endl;

	/*std::ifstream ifs(customer.Username + ".json");
	nlohmann::json j = nlohmann::json::parse(ifs);

	std::cout << j << std::endl;*/
}
