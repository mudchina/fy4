#include <ansi.h>
#include <combat.h>
inherit SSERVER;
static object *enemy = ({});
int perform(object me, object target1,object target2)
{
        string msg;                                
        int extra;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("ill-quan",1);
        if ( extra < 50) return notify_fail("你的病维摩拳还不够纯熟！\n");
        
        
        enemy=me->query_enemy();
        if (sizeof(enemy)<2) return notify_fail("你必须同时和两个以上的敌手战斗才能使用乾坤挪移！\n");
        if( !target1 && target2) return notify_fail("你必须同时指定两个对手\n");
        if( !target2 && target1) return notify_fail("你必须同时指定两个对手\n");
        if(!target1 && !target2)
        {
           target1=enemy[0];
           target2=enemy[1];
         }
        if( !target1 || !target2
        ||      !target1->is_character() || !target2->is_character()
        ||      !me->is_fighting(target1) || !me->is_fighting(target2))
                return notify_fail("［乾坤挪移］只能对战斗中的对手使用。\n");
        if (me->query("force")<=100) return notify_fail("你的内力不足，无法带动敌人攻势！\n");
        me->add("force",-100);
        message_vision("$N使出病维摩拳的不传之秘「乾坤挪移」\n",me);
                
        if (random(me->query("combat_exp")*(extra/30+1))>target1->query("combat_exp/30") && (target1->query("ill_boss") < 2))
        {
        	
          message_vision(HIY "$N伸手带动$n的攻势，使之攻向"+target2->name()+"！\n" NOR,me,target1);
          COMBAT_D->do_attack(target1,target2, TYPE_PERFORM, 0);  
          target1->receive_damage("kee",1000,me);
          target1->start_busy(1);
        }
        else
        {
          message_vision("但$n看破$N的意图，趁势发动攻击！\n",me,target1);
          COMBAT_D->do_attack(target1,me,TYPE_PERFORM, 0);
        }
        
              
        if (random(me->query("combat_exp")*(extra/30+1))>target2->query("combat_exp/30")&&(target1->query("ill_boss") < 2))
        {
        	
          message_vision(HIY "$N伸手带动$n的攻势，使之攻向"+target1->name()+"！\n" NOR,me,target2);
          COMBAT_D->do_attack(target2,target1, TYPE_PERFORM, 0);  
          target2->receive_damage("kee",1000,me);
          target2->start_busy(1);
        }
        else
        {
          message_vision("但$n看破$N的意图，趁势发动攻击！\n",me,target2);
          COMBAT_D->do_attack(target2,me,TYPE_PERFORM, 0);
        }
        return 1;
}      
