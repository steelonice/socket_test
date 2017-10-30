/*
 * test_menu.h
 *
 *  Created on: Oct 29, 2017
 *      Author: hayden
 */

#ifndef TEST_MENU_H_
#define TEST_MENU_H_

#include <stdint.h>
#include <string>
#include <vector>
#include <iterator>
#include <thread>

typedef struct test_menu_item{
	char				select_key;
	std::string			menu_text;
	test_menu_item * 	next_test_menu;
	void 				(* menu_function)(uint8_t);
	uint8_t				argument;
}test_menu_item;

typedef struct test_menu{
	test_menu_item * items;
	test_menu 	   * prev_test_menu;
	uint8_t			 num_options;
}test_menu;

typedef enum{
	GET_INPUT,
	OUTPUT_TEXT,
	SERVICE_MENU,
	SERVICE_FUNC,
}menu_state;

class menu_manager{
	public:
		menu_manager(test_menu * main_menu);
		bool add_menu(test_menu * menu_to_add);
		void service_menu();

		std::thread 			 menu_thread;
	protected:

	private:
		bool 					 _is_running;
		menu_state 				 _state;
		std::vector<test_menu *> _system_menus;
		uint8_t					 _current_menu;
		uint8_t					 _main_menu;


		void menu_output_text( void );
		void menu_input_text( void );
};

#endif /* TEST_MENU_H_ */
