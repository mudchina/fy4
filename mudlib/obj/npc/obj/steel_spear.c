#include <weapon.h>
inherit SPEAR; 
void create()
{
        set_name("¸ÖÇ¹", ({ "steel spear" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("value", 3000);
                set("no_get",1);
                set("no_drop",1); 
                set("material", "steel");
        }
        ::init_spear(25);
}    
