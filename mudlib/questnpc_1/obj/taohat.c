 // hat.c
#include <armor.h>
inherit HEAD; 
void create()
{
        set_name("Ì«¼«µÀ¹Ú", ({ "taiji hat", "hat" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
                set("value", 10000);
                set("material", "cloth");
                set("armor_type", "head");
                set("armor_prop/armor", 10);
        }
        ::init_head();
}
