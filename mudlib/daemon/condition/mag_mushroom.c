 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
    me->receive_wound("kee", 20);
    me->receive_wound("gin", 20);
    me->receive_wound("sen", 20);
    me->apply_condition("mag_mushroom", duration - 1);
        if( duration < 1 )
    tell_object(me, YEL "你吐出一口浊气，终于感觉舒坦了许多！\n" NOR );
        else
    tell_object(me, HIM "你胃里一阵绞痛，脸上紫气郁结，冒出豆大的黑紫色汗珠！\n" NOR );
    message("vision", me->name() + "右手按住胃部，脸上紫气郁结，头上冒出豆大的黑紫色汗滴！\n", 
                        environment(me), me);
        if( duration < 1 ) 
                return 0;
        return 1;
}   
