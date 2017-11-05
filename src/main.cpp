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
#include "hc_client/hc_client.h"
#include "hc_server/hc_server.h"
#include "hc_socket/hc_socket.h"

bool _is_running = true;

void main_start_server()
{

}

void main_start_client()
{

}

int main(int argc, char *argv[])
{
#if 0
	menu_manager my_menu_manager(&main_menu);
	my_menu_manager.add_menu(&main_2_menu);
	my_menu_manager.menu_thread.join();
#endif
     return 0;
}
