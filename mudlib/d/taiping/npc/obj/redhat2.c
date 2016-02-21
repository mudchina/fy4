#include <armor.h>
#include <ansi.h>
inherit HEAD; 
void create() {
        set_name(RED"ºìÓ§Ã±"NOR, ({ "red hat","hat" }) );
        set_weight(6);
        if(clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
                set("long","Ò»¶¥¹Ù²îÃÇ´÷µÄºìÓ§Ã±¡£");
                set("value", 8);
                set("material", "cloth");
        }
        ::init_head();
}  
