#include <weapon.h>
inherit HAMMER; 
void create()
{
        set_name("∞À¿‚¥∏", ({ "steel hammer" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "∞—");
                set("value", 3000);
                set("no_get",1);
                set("no_drop",1); 
                set("material", "steel");
        }
        ::init_hammer(25);
}       
