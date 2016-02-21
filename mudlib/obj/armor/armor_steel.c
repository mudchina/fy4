 // armor_steel.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <armor.h>
inherit ARMOR; 
void create() {
        set_name("¸Ö¼×", ({ "gangjia" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 50);
                set("material", "steel");
                set("armor_prop/armor", 30);
        }
        ::init_armor();
}   
