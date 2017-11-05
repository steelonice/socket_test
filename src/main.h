/*
 * main.h
 *
 *  Created on: Oct 29, 2017
 *      Author: hayden
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include <string>

#include "test_menu/test_menu.h"

#define DEFAULT_ARG 0

void option_two( uint8_t unused );
void option_one( uint8_t unused );

test_menu_item main_menu_2_items[] = {

 {'\0', "Option 2", NULL, &option_two, 1},
 {'\0', "Option 3", NULL, &option_two, 2},
};
test_menu main_2_menu =
{
  main_menu_2_items,
  NULL,
  sizeof(main_menu_2_items)/sizeof(test_menu_item)
};

test_menu_item main_menu_items[] = {

 {'\0', "Option 1", NULL, &option_one, DEFAULT_ARG},
 {'\0', "Option 2", NULL, &option_two, 1},
 {'\0', "Menu2"   , &main_2_menu, NULL, 2},
};
test_menu main_menu =
{
  main_menu_items,
  NULL,
  sizeof(main_menu_items)/sizeof(test_menu_item)
};

#endif /* TEST_MENU_H_ */
