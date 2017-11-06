/*
 * hc_server.h
 *
 *  Created on: Oct 29, 2017
 *      Author: Hayden Chuter
 *
 *      \notes
 *
 */

#ifndef SRC_MAIN_MENU_H_
#define SRC_MAIN_MENU_H_

#include "main.h"
#include "test_menu/test_menu.h"
#include "hc_client/hc_client_menu.h"
#include "hc_server/hc_server_menu.h"
#include "hc_socket/hc_socket_menu.h"

#define DEFAULT_ARG 0

test_menu_item main_menu_items[] =
{
	{'\0', "Server", &server_menu, NULL, DEFAULT_ARG},
	{'\0', "Client", &client_menu, NULL, DEFAULT_ARG},
};

test_menu main_menu =
{
  main_menu_items,
  NULL,
  sizeof(main_menu_items)/sizeof(test_menu_item),
};

#endif /* SRC_MAIN_MENU_H_ */
