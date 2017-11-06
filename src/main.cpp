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
#include "main_menu.h"
#include "test_menu/test_menu.h"

bool _is_running = true;

void main_start_server()
{

}

void main_start_client()
{

}

int main(int argc, char *argv[])
{

	menu_manager my_menu_manager(&main_menu);
	my_menu_manager.add_menu(&client_menu);
	my_menu_manager.add_menu(&server_menu);

	my_menu_manager.menu_thread.join();
     return 0;
}
