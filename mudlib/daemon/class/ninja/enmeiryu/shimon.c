 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［四门-朱雀］只能对战斗中的对手使用。\n");
        if((int)me->query("kee")*100/(int)me->query("max_kee") > 20
                && (int)me->query("eff_kee")*100/(int)me->query("max_kee") > 20
                && (int)me->query("sen")*100/(int)me->query("max_sen") > 20
                && (int)me->query("eff_sen")*100/(int)me->query("max_sen") > 20)
                return notify_fail("还不到使这招的时候。\n");
        extra = me->query_skill("unarmed") ;
        if(extra <= 200 ) return notify_fail("你的陆奥圆明流拳术不够熟练，还不能出四门-朱雀！\n");
        msg = HIR "$N口中喃喃说道：“只有那一招了。”，绝望中$N使出了最后的一招「四门.朱雀」!
$n一时以为自己眼花，居然看到四个$N的身影!
$n身后的一个$N猛地冲向$n，用膝部顶住$n的腰，单手揪住$n
的头，用力向地面磕去，同时肘部击向$n的眉心。" NOR;
        weapon = me->query_temp("weapon");
        extra=extra-150;
        me->add_temp("apply/damage",extra*10);
        me->add_temp("apply/attack",extra*4);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*10);
        me->add_temp("apply/attack",-extra*4);
        if (me->query_busy()<3) 
                me->start_busy(3);
        return 1;
}  
