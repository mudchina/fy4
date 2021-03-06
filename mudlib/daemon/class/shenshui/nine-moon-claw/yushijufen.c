#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
    string msg; 
	int extra;
    if(me->query("class")!="shenshui")
          return notify_fail("只有神水宫弟子才能使出「玉石俱焚」的绝技。\n"); 
    
	extra = me->query_skill("nine-moon-force",1);
    if( extra < 150)
        return notify_fail("你的九阴心经还不够熟练！\n"); 
    if(!me->query_condition("tianyi"))
        return notify_fail("「玉石俱焚」必须要利用天一神水的毒性才能使用！！\n");
    if( !target ) target = offensive_target(me); 
    if( !target ||!target->is_character()|| !me->is_fighting(target) )
        return notify_fail("「玉石俱焚」只能对战斗中的对手使用。\n");
    
    msg = RED "$N"+NOR RED"含泪道：“恶贼！我要与你同归于尽！”说完狂喷鲜血，瞬时间天地为之变色！\n\n";
    if(me->query("combat_exp") > random(target->query("combat_exp")*40/extra) )
    {
        msg += "慢慢地，$n"+NOR RED"被一片红色的血雾包围，什么都看不见了！\n"NOR;
        //target->receive_damage("kee",(int)me->query("max_kee")+1,me);
        //receive_wound("kee", ((int)me->query("max_kee")+5000),me);
        message_vision(msg, me, target);
        target->die();
        me->die();
        me->set_skill("nine-moon-force",101 + random(extra-110));
    }
    else
    {
        msg += WHT"可是$n还是躲过了$N"+NOR WHT"的最后一击！！"
            "$n"+NOR WHT"脸上似乎蒙上了一层淡淡的银灰色！\n" NOR;
        message_vision(msg, me, target);
        target->apply_condition("tianyi",50);
        me->unconcious();
    }
    
    return 1;
}    
