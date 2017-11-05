/*
 * hc_client_menu.h
 *
 *  Created on: Oct 29, 2017
 *      Author: Hayden Chuter
 *
 *      \notes
 *
 */

#ifndef HC_CLIENT_MENU_H_
#define HC_CLIENT_MENU_H_

#include "main_menu.h"
#include "test_menu/test_menu.h"
#include "hc_client.h"

test_menu_item client_menu_items[] =
{
	{'\0', "Start", NULL, hc_client_dummy, DEFAULT_ARG},
	{'\0', "Stop", NULL, hc_client_dummy, DEFAULT_ARG},
};

test_menu client_menu =
{
  client_menu_items,
  NULL,
  sizeof(client_menu_items)/sizeof(test_menu_item)
};

#endif
