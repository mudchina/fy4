#include <weapon.h>
#include <ansi.h> 
inherit SWORD; 
void create()
{
        set_name(HIW"µû½£"NOR, ({ "die sword", "sword" }) );
        set_weight(3000);
        set("class","legend");
        set("experience",3500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("value", 300);
                set("material", "iron");
                set("weapon_prop/sword",20);
                set("long",
                          "Ò»±ú¿³½ð¶ÏÓñ¡¢·æÈñÎÞÆ¥µÄ±¦½££¬½£·æ·¢³öÓ¨Ó¨×Ï¹â¡£\n");
        }
        init_sword(70, SECONDARY);
}   
