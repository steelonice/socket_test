/*
 * text_menu.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: Hayden Chuter
 *
 *      \notes
 *
 */

#include "test_menu.h"
#include <iostream>
#include <algorithm>

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
			case HANDLE_CHOICE:
				menu_handle_choice();
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
	std::cout << "Please select an option: ";
	std::cin  >> input;
	_captured_input = input.at(0);
	_state = HANDLE_CHOICE;
}

void menu_manager::menu_handle_choice( void )
{
	uint8_t loop = 0;
	bool	serviced = false;

	/* Loop through all the system menus */
	for(loop = 0; loop < _system_menus.at(_current_menu)->num_options; loop++)
	{
		if(_captured_input == _system_menus.at(_current_menu)->items[loop].select_key)
		{
			if(_system_menus.at(_current_menu)->items[loop].menu_function != NULL)
			{
				_system_menus.at(_current_menu)->items[loop].menu_function(_system_menus.at(_current_menu)->items[loop].argument);
				serviced = true;
			}
			else if(_system_menus.at(_current_menu)->items[loop].next_test_menu != NULL)
			{
				_current_menu = std::find(_system_menus.begin(), _system_menus.end(), _system_menus.at(_current_menu)->items[loop].next_test_menu) - _system_menus.begin();
				serviced = true;
			}
		}
	}
	if(serviced == false)
	{
		std::cout << "Sorry, Invalid Option\n";
	}
	_state = OUTPUT_TEXT;
}




