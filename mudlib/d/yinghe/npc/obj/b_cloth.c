 // -neon
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name("À¶ÉÀ", ({ "blue cloth", "cloth" }) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "¼þ");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    set("value",400);
    }
    ::init_cloth();
}     
