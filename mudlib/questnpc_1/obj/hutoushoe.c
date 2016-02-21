 // shoe.c
#include <armor.h>
#include <ansi.h>
inherit BOOTS; 
void create()
{
        set_name( HIR"»¢Í·ºìÈÞÐ¬"NOR, ({ "shoes" }) );
        set_weight(750);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "Ë«");
                set("value", 500);
                set("armor_prop/armor", 1 );
        }
    ::init_boots();
}
