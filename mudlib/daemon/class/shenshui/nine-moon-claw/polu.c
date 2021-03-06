 // silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void hit_break(object target, object me, int factor); 
int perform(object me, object target)
{
        string msg;
        int extra, my_exp, exp_factor;
        
        if(me->query("class")!="shenshui")
                return notify_fail("只有神水宫弟子才能使出「破颅」的绝技。\n");
        if (me->query_skill("nine-moon-claw",1)<150)
                return notify_fail("你的［九阴白骨爪］还不够纯熟。\n");
        if (me->query_skill("nine-moon-steps",1)<150)
                return notify_fail("你的［九阴身法］还不够纯熟。\n");
        if (me->query_skill("nine-moon-force",1)<150)
                return notify_fail("你的［九阴心经］还不够纯熟。\n");
        if (me->query_skill("nine-moon-spirit",1)<150)
                return notify_fail("你的［姹女神功］还不够纯熟。\n"); 
        if (me->query_skill_mapped("force") != "nine-moon-force")
                return notify_fail("「破颅」需要九阴心经的配合。\n");
        if (me->query_skill_mapped("dodge") != "nine-moon-steps")
                return notify_fail("「破颅」需要九阴身法的配合。\n");
        my_exp = (int) me->query("combat_exp");
        exp_factor = 750000000/my_exp;
        if (exp_factor < 100) exp_factor = 100;
        
//      2.7M, 4-5mins delay, after 3.4M no delay.
        if(exp_factor>220 && (int)me->query("timer/polu") + exp_factor > time())
                return notify_fail(HIM"「破颅」耗费体力极大，不能连续使用。\n"NOR);
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［破颅］只能对战斗中的对手使用。\n");
        
        extra = me->query_skill("nine-moon-claw",1)*3/2+ me->query_skill("nine-moon-steps",1)/2
                + me->query_skill("nine-moon-force",1)+ me->query_skill("nine-moon-spirit",1);
   extra = extra *4;
// 2.7M 2400, 6.4M 3020.        
        
// >3.125M  have 2 hits.
        if (exp_factor>240) {
                message_vision(HIW"$N身形闪动，兔起鹘落，迅捷无比，如鬼魅般欺到$n"+HIW"身边，
袖中伸出纤纤素手，五根手指向$n"+HIW"的头顶插了下去。\n"NOR,me,target);
                hit_break(target, me, extra*2/3);
                if (me->query_busy()<3) me->start_busy(3);
        }
        
        else {
                me->add_temp("apply/attack", extra/6);  
                me->add_temp("apply/damage", extra/6);
                msg = HIW"$N身形闪动，兔起鹘落，迅捷无比，如鬼魅般欺到$n"HIW"身边，
袖中伸出纤纤素手，五根手指疾抓$n"+HIW"$l。\n"NOR ;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
                me->add_temp("apply/attack", -extra/6);
                me->add_temp("apply/damage", -extra/6);
                //<- adjust damage here
                
                if (target->query_temp("damaged_during_attack") && (int)me->query("timer/polu") + exp_factor/20 < time()) {
                        //<- Adjust timer here
                        message_vision(HIW"\n$N"+HIW"一招得手，更不稍停，反掌间五根手指已向$n"+HIW"的头顶插了下去。\n"NOR,me,target);
                        hit_break(target, me, extra/2);
                }
//      after 4.5M, 2 self busy instead of 3.
                if (me->query_busy()<2+exp_factor/166) 
                        me->start_busy(2 + exp_factor/166);    //<- Addjust busy here
                
        } 
        return 1;
} 
void hit_break(object target, object me, int factor) {
        int resist; 
// damage is 2400+random(2400) to 3000+random(3000);    
        if(target->query("combat_exp") < random((int)me->query("combat_exp"))*10)
        {
                message_vision(MAG"$N"+MAG"惨叫一声，顶门已被$n"+MAG"的手掌罩住！\n"NOR,target,me);
                resist=target->query("resistance/kee");
           target->set("resistance/kee",0);
                target->receive_wound("kee",factor/2+random(factor));
                target->receive_damage("kee",factor/2+random(factor));
                target->set("resistance/kee",resist);
                target->set_temp("last_damage_from",me);
                COMBAT_D->report_status(target);
        }
        else    message_vision(YEL"$N不慌不忙，抢前半步，避开了脑门要害。\n"NOR,target);
        
        me->set("timer/polu",time());
        
} 
int help(object me)
{
        write(@HELP
指令格式 : perform polu
极毒，极狠，命中率极高的一招，为神水武功的
精华所聚。出招如鬼，收招似魅，只是由于杀气
太盛，不能与“假死“同时使用。 
HELP
        );
        return 1;
}
