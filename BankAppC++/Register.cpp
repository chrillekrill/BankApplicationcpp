#include <iostream>
#include <string>
#include "Register.h"

#include "Customer.h"

void Register()
{
	std::string username;
	std::string password;

	std::cout << "Username: "; std::cin >> username;
	std::cout << "Password: "; std::cin >> password;

	Customer customer(username, password);

	std::cout << "Thank you for registering." << std::endl;

	std::cout << username << std::endl;
}
