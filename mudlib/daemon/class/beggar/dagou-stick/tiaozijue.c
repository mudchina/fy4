 //silencer@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, myexp, enemyexp, lvl;
        object weapon,hisweapon; 
        if(me->query("class")!="beggar" && userp(me))
                return notify_fail("［挑字诀］只传授给丐帮弟子！\n");
        
        lvl = (int) me->query_skill("dagou-stick",1);
        if(lvl < 100)
                return notify_fail("你的打狗棒法还不够熟练！\n");       
        
        if (me->query_skill_mapped("force") != "huntunforce")
                return notify_fail("挑字诀需要混沌心法的配合。\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［挑字诀］只能对战斗中的对手使用。\n"); 
        weapon = me->query_temp("weapon");
        hisweapon=target->query_temp("weapon");
        
        if (!hisweapon)
                return notify_fail("对方没有武器，无从使用“挑字诀“。\n");
                
        if (me->query("force")<100)     
                return notify_fail("你的内力不够。\n");
                
        myexp = (int) me->query("combat_exp");
        enemyexp= (int) target->query("combat_exp");
        
        msg = HIY"\n$N"+weapon->name()+HIY"缩回，使起“"+NOR CYN"挑"+HIY"”字诀，搭住$n"+HIY"的"+hisweapon->name()+HIY"向上甩出。\n"NOR;
        message_vision(msg,me,target); 
        if (random(enemyexp*3)<myexp && random(2)) {
           msg = HIG"\n$N只觉一股大力传来，手中的"+hisweapon->name()+"拿捏不住，直飞上天。\n\n"NOR;
                if(hisweapon->unequip()) hisweapon->move(environment(target));
        }  else 
                msg = WHT"$N"+WHT"力贯于腕，手中"+hisweapon->name()+WHT"往下一压，将"+weapon->name()+WHT"荡了开去。\n\n"NOR;
        
        message_vision(msg,target); 
        me->start_busy(1+random(2));            
        return 1;
}       
