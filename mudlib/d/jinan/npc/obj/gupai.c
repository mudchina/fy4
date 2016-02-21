#include <weapon.h>
inherit THROWING; 
void create()
{
        set_name("÷½ÅÆ", ({ "gupai" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "Ò»ÕÅ¾§äŞÌŞÍ¸µÄÏóÑÀ÷»ÅÆ\n");
                set("unit", "¶Ñ");
                set("base_value", 1);
                set("base_unit", "ÕÅ");
                set("base_weight", 1);
        }
        set_amount(48);
        init_throwing(1);
}
