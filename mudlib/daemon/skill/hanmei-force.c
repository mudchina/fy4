 // iceforce.c2
inherit SKILL;
void setup() {
        set("name", "寒梅心法");
        set("usage/force", 1);
        set("skill_class", "huashan");
        set("effective_level", 100);
        set("learn_bonus", 0);
        set("practice_bonus", 10);
        set("black_white_ness", 0);     
}  
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
        
        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(me->query_skill("hanmei-force")) > (damage_bonus + foo) ) {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        return "$N的招式挟著一股寒气使得$n不禁打了个寒噤。\n";
                }
        }
        return foo;
}
    
