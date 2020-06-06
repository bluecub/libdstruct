/**
 * Copyright (c) 2020 bluecub
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the BSD license. See LICENSE for details.
 **/

#ifndef DS_HASH_H
#define DS_HASH_H

#include "ds_list.h"

/* Define structure for the hash node*/
typedef struct DS_Hash_Node_ {
    char *key;
    void *data;
} DS_Hash_Node;

typedef DS_Hash_Node * DS_Hash_Node_Ptr;

/* Define a structure for chained hash table */
typedef unsigned (*Hash)(const char *key);

typedef struct DS_Hash_Table_ {
    int buckets;
    Compare compare;
    Destroy destroy;
    Hash hash;
    int size;
    DS_List_Ptr table;
} DS_Hash_Table;

typedef DS_Hash_Table * DS_Hash_Table_Ptr;

/* Public Interface */

ushort ds_hash_init (DS_Hash_Table_Ptr *htbl, int buckets, Compare compare, Destroy destroy);

ushort ds_hash_free (DS_Hash_Table_Ptr *htbl);
ushort ds_hash_put (DS_Hash_Table_Ptr htbl, const char *key, const void *data);
ushort ds_hash_remove (DS_Hash_Table_Ptr htbl, const char *key, void **data);
ushort ds_hash_get (const DS_Hash_Table_Ptr htbl, const char *key, void **data);

#define ds_hash_size(htbl) ((htbl)->size)

#endif
