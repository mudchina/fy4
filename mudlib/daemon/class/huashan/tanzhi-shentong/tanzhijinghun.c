 // tanzhijinghun.c
#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target) {
        
        string msg;
        int bonus, damage_bonus, damage, level, lvl;
        
        if(!objectp(target)) target = offensive_target(me);
        
        if (me->query_skill("tanzhi-shentong",1)<80) 
                return notify_fail("你的「弹指神通」不够熟练！\n");
        
        if( !target ) target = offensive_target(me);
        if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
                return notify_fail("「弹指惊魂」只能对战斗中的对手使用。\n");
        }
        
        if (target->query("step_less")==1) 
                return notify_fail(HIW"此人身势灵活，功力深湛，不会被此技能迷惑的。\n"NOR);
        
        if(target->is_busy()) {
                return notify_fail("对方已经不能动弹了。。。\n");
        }
        
        if (me->query("class") != "emei")
        {
               bonus = (int) me->query_skill("tanzhi-shentong",1);
        }else        {    
        	bonus = (int) me->query_skill("tanzhi-shentong",1);
                lvl = (int) me->query_skill("changelaw",1);
        	bonus = bonus+lvl*2;    
        
        }
        msg = HIG"$N"+HIG"身影如旋风般舞动，指风破空之声嗤嗤不绝袭向"+"$n"+HIG"各处要穴。\n"NOR;
        bonus = ((int) random(me->query("combat_exp")/40*bonus)+me->query("combat_exp")/4)/((int) target->query("combat_exp")+1);
        //if (me->query("class") != "huashan") bonus=bonus/2;
        if(bonus >= 1) {
                msg += HIG"$n"+HIG"只觉胸口膻中穴一麻，登时动弹不得。\n" NOR;           
                damage = me->query_skill("throwing")>=420?420:me->query_skill("throwing");
                damage_bonus=me->query("combat_exp")/3000*damage/1000;
                if (damage_bonus>damage*3/2) damage_bonus= damage*3/2; 
                damage = damage+ damage_bonus;
                target->receive_damage("kee", damage, me);
                target->start_busy(3);
                /*if(me->query_skill_mapped("force") != "hanmei-force") {
                        me->start_busy(2);
                }
           else {*/
                        msg += WHT"$N"+WHT"内力流转，身法居然少见滞涩！\n\n"NOR;
                        me->start_busy(1);
                //}       
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
        } else {
                msg += YEL"$n"+YEL"就地一滚堪堪躲过了$P"+YEL"的指风！！\n"NOR;
                message_vision(msg, me, target);
                me->start_busy(2);
        }
        return 1;
}   
