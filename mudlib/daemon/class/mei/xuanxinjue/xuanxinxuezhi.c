//ice@fy4
#include <ansi.h> 
int exert(object me, object target)
{
        int extra;
        
        if(me->query("class")!="mei")
                return notify_fail("只有松谷庵的圣女才能运用玄心奥妙决。\n");
        extra=me->query_skill("xuanxinjue",1);
        if(extra<90)
                return notify_fail("你玄心奥妙决的等级不够高。\n");
        if( me->is_fighting() )
                return notify_fail("战斗中运功放血等于自杀！\n"); 
        if(target&& me!=target)
                return notify_fail("［玄心血指］只能用在自己身上。\n");
        if( (int)me->query("kee") <= extra*2 )
                return notify_fail("你的气血不够。\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("你的内力不够。\n");
        if(me->query_temp("xuanxinaomiao"))
                return notify_fail("你已经在运功中了！！\n");

        me->add("force", -100);
		me->receive_damage("kee", extra*3/2);
        message_vision(HIR"\n$N"HIR"双膝跪地，五心向天，一滴鲜血和着真气从指尖升起...\n\n"NOR, me);
        extra=extra+random(extra);
		me->set_temp("xuanxinaomiao",1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/3);
        return 1;
}

void remove_effect(object me)
{
		me->delete_temp("xuanxinaomiao");
        tell_object(me, HIR"你指尖的血气消失了。\n"NOR);
}
