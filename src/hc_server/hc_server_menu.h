/*
 * hc_server_menu.h
 *
 *  Created on: Oct 29, 2017
 *      Author: Hayden Chuter
 *
 *      \notes
 *
 */

#ifndef HC_SERVER_MENU_H_
#define HC_SERVER_MENU_H_

#include "../test_menu/test_menu.h"
#include "hc_server.h"

test_menu_item server_menu_items[] =
{
	{'\0', "Start", NULL, hc_server_dummy, 0},
	{'\0', "Stop", NULL, hc_server_dummy, 0},
};

test_menu server_menu =
{
		server_menu_items,
		NULL,
		sizeof(server_menu_items)/sizeof(test_menu_item)
};

#endif
