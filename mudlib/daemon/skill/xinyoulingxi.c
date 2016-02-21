#include <ansi.h>
inherit SSERVER;
void remove_effect(object me,int amount);
int perform(object me, object target)
{
        int skill; 
                if (target==me) return notify_fail("“心有灵犀”只能对对手使用。\n");
                if (!target) target=offensive_target(me);
                if (!target||!target->is_character()||!me->is_fighting(target))
                        return notify_fail("“心有灵犀”只能对战斗中的对手使用。\n");
                
                skill=me->query_skill("lingxi-zhi",1);
                if (skill<150)
                        return notify_fail("你的灵犀一指还不够熟练，不能出“心有灵犀”。\n");
                if (me->query_temp("xinyoulingxi"))
                        return notify_fail("你已经在施展“心有灵犀”了。\n");
                
        tell_object(me,HIR"你的脑海中豁然一片空明，对方一举一动无不被你算中。\n"NOR);
                me->set_temp("xinyoulingxi", 1); 
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), 10); 
        me->start_busy(2); 
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/defense", - amount); 
        tell_object(me, "你“心有灵犀的”功效已经过去了。\n");
}
  
