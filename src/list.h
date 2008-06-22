#ifndef LIST_H__
#define LIST_H__

/*
 * Copyright (C) 2008 Frank Aurich (1100101+automatic@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifdef MEMWATCH
	#include "memwatch.h"
#endif


typedef struct NODE NODE;
typedef struct rss_obj* rss_item;
typedef NODE* linked_list;

struct rss_obj {
	char *name;
	char *url;
};

struct NODE {
   NODE *pNext;
   rss_item item;
};

/* read-only functions */
unsigned int listCount(linked_list head);
int hasURL(const char *url, linked_list head);
void printList(linked_list list);

/* list modifiers */
void freeRSSItem(rss_item listItem);
int addItem(rss_item elem, NODE **head);
void freeList(NODE **head);
rss_item newRSSItem();
int add_to_bucket(rss_item elem, NODE **b, int max_bucket_items);
void cleanupList(NODE **list);



#endif
