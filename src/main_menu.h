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

#define DEFAULT_ARG 0

test_menu_item main_menu_items[] =
{
	{'\0', "Server", NULL, NULL, DEFAULT_ARG},
	{'\0', "Client", NULL, NULL, DEFAULT_ARG},
};

test_menu main_menu =
{
  main_menu_items,
  NULL,
  sizeof(main_menu_items)/sizeof(test_menu_item)
};

#endif /* SRC_MAIN_MENU_H_ */
