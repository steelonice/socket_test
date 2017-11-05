/*
 * main.cpp
 *
 *  Created on: Oct 29, 2017
 *  Author: Hayden Chuter
 *
 *  \notes 	A simple server in the internet domain using TCP
 *   	  	The port number is passed as an argument
 *
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <thread>

#include "main.h"
#include "test_menu/test_menu.h"


void option_one( uint8_t unused )
{
	std::cout << "You selected option one!\n";
}

void option_two( uint8_t unused )
{
	std::cout << "You selected option two!\n";
	std::cout << unsigned(unused) << "\n";
}

int main(int argc, char *argv[])
{
	menu_manager my_menu_manager(&main_menu);
	my_menu_manager.add_menu(&main_2_menu);
	my_menu_manager.menu_thread.join();
	#if 0
#endif
     return 0;
}
