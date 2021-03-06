/**
*  Copyright (c) 2020 Surgams
*
*  This library is free software; you can redistribute it and/or modify it
*  under the terms of the BSD license. See LICENSE for details.
*
**/

#ifndef DS_SET_H
#define DS_SET_H

#include "ds_list.h"

/* Implement set as lists */
typedef DS_List DS_Set;
typedef DS_List_Ptr DS_Set_Ptr;

/* Public Interface */
uint8_t ds_set_init (DS_Set_Ptr *set, Compare compare, Destroy destroy);
uint8_t ds_set_insert (DS_Set_Ptr set, const void *data);
uint8_t ds_set_remove (DS_Set_Ptr set, void **data);
uint8_t ds_set_union (DS_Set_Ptr *setu, const DS_Set_Ptr set1, const DS_Set_Ptr set2);
uint8_t ds_set_intersect (DS_Set_Ptr *seti, const DS_Set_Ptr set1, const DS_Set_Ptr set2);
uint8_t ds_set_diff (DS_Set_Ptr *setd, const DS_Set_Ptr set1, const DS_Set_Ptr set2);
boolean ds_set_is_member (const DS_Set_Ptr, const void *data);
boolean ds_set_is_subset (const DS_Set_Ptr, const DS_Set_Ptr);
boolean ds_set_is_equal (const DS_Set_Ptr, const DS_Set_Ptr);

#define ds_set_free ds_list_free
#define ds_set_size(set) ((set)->size)

#endif
