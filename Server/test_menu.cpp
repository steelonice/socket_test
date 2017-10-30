/*
 * text_menu.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: hayden
 */

#include "test_menu.h"
#include <iostream>

menu_manager::menu_manager(test_menu * main_menu)
{
	_is_running = true;
	_state = OUTPUT_TEXT;
	add_menu(main_menu);
	_current_menu = 0;
	_main_menu = 0;
	menu_thread = std::thread(&menu_manager::service_menu, this);
}

bool menu_manager::add_menu(test_menu * menu_to_add)
{
	_system_menus.push_back(menu_to_add);
	for(uint8_t loop= 0; loop < menu_to_add->num_options; loop++)
	{
		_system_menus.back()->items[loop].select_key = ('0' + loop);
	}
	return true;
}

void menu_manager::service_menu()
{
	while(_is_running)
	{
		switch(_state)
		{
			case GET_INPUT:
				menu_input_text();
				break;
			case OUTPUT_TEXT:
				menu_output_text();
				break;
			case SERVICE_MENU:
				break;
			case SERVICE_FUNC:
				break;
			default:
				break;
		}
	}
}

void menu_manager::menu_output_text( void )
{
	for(uint8_t loop= 0; loop < _system_menus.at(_current_menu)->num_options; loop++)
	{
		std::cout << _system_menus.at(_current_menu)->items[loop].select_key;
		std::cout << " - ";
		std::cout << _system_menus.at(_current_menu)->items[loop].menu_text;
		std::cout << "\n";
	}
	_state = GET_INPUT;
}
void menu_manager::menu_input_text( void )
{
	std::string input;
	std::cout << "Please select an option";
	std::cin  >> input;
	_state = OUTPUT_TEXT;
}




