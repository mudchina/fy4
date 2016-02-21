#include <weapon.h>
#include <ansi.h>
inherit SPEAR; 
void create()
{
        set_name( HIC "·ÉÔÆÇ¹" NOR, ({ "feiyunspear","spear" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("long", "Ò»°ÑïÙÌú¶ÌÇ¹¡£");
                set("value", 150000);
                set("material", "iron"); 
        }
        ::init_spear(100);
}       
