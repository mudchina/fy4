#include <ansi.h>
#include <armor.h> 
inherit CLOTH; 
void create()
{
        set_name(MAG"×Ï³ñÂí¹Ó"NOR, ({ "grey cloth","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 20);
        }
    ::init_cloth();
}    
