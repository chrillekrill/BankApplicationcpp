#include "Initialize.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include "Register.h"
#include <mysql.h>




void Initialize()
{

	bool menu = true;

	while (menu)
	{
		std::cout << "Please choose an option." << std::endl;
		std::cout << "Register: 1" << std::endl;
		std::cout << "Login: 2" << std::endl;

		int option = 0;
		std::cin >> option;
		switch (option)
		{
		case 1:
			Register();
			break;
		case 0:
			menu = false;
			break;
		}
	}
}
