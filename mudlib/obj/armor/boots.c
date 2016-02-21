 // boots.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <armor.h>
inherit BOOTS; 
void create() {
        set_name("²¼Ð¬", ({ "shoes", "boots" }) );
        set_weight(90);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "Ë«");
                set("value", 10);
        }
        ::init_boots();
}     
