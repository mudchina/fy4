#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, bonus;
        
        extra = me->query_skill("anxiang-steps",1);
        bonus = me->query_skill("cloud-dance",1);
        
        if ( extra < 50) return notify_fail("你的［暗香浮影］还不够纯熟！\n");
        if (me->query_skill_mapped("move") != "anxiang-steps")
                return notify_fail("幻风飘云舞的辅助攻击需要「暗香浮影」的轻功基础。\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("『夜雪初积』只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
        
        if (target->query("step_less")==2|| target->query("big_boss")) 
                return notify_fail(HIW"此人身势灵活，功力深湛，不会被此步法迷惑的。\n"NOR);
        
        message_vision(WHT"$N"+WHT"的身影忽然变得朦胧不定，似乎化作了如梦如幻的飘云。\n"NOR, me); 
        message_vision(WHT"如夜雪在寒梅间飘落，雪花舞动之间，有冷冷的幽香浮动。\n"NOR, me); 
        myexp = me->query("combat_exp")/2+ random(me->query("combat_exp"))/85*(bonus+extra);
        if (target->query("combat_exp")>5100000)
                myexp = me->query("combat_exp")/2+ random(me->query("combat_exp"))/100*(bonus+extra);
        if (me->query("class")!="huashan") myexp = me->query("combat_exp")*2/5+random(me->query("combat_exp") / 100 * extra);
        if(myexp > target->query("combat_exp"))
        {
                message_vision(HIW"\n$N"+HIW"觉得身法越来越滞塞，好似陷入迷茫的雾雪里。\n"NOR, target); 
                message_vision(HIG"在缕缕暗香中，$N"+HIG"不禁有些痴迷起来。\n"NOR, target); 
                target->receive_damage("gin", 40,me);
                target->start_busy(3);
        }
        else{
           message_vision(HIY"\n$N"+HIY"守心归一，不为$n"+HIY"身法所惑。一步踏出，正是$n"+HIY"的空门！\n"NOR, target, me); 
                me->start_busy(2);
        }
        return 1;
}    
