#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
        set_name("佛光斧头" , ({ "lightaxe", "axe" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把很不起眼的斧头，上书“佛光”\n");
                set("value", 6000);
                set("material", "iron");
                set("wield_msg", "$N拿出一把雪亮的$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        } 
        init_axe(43);
}     
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_sen");
        victim->receive_damage("sen",dam/10,me);
        return HIY"斧头随着招式画出一道优美的弧线，既似日出晨光，又若菩提树影，看得$n如痴如醉，不懂反应！\n" NOR;
}   