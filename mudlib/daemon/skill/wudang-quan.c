 // bai-quan.c
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                     "七星拳");
        set("learn_bonus",              50);
        set("practice_bonus",   10);
        set("effective_level",  150);
        set("usage/unarmed",    1);
        set("skill_class",              "ghost");
        
        set("parry_msg",                ({
                                                "$n一招「众星寥落意难平，干戈起处惊笛音」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
                                                "$n右拳虚幌，左拳一招「铁马冰河腾烽烟，极光地火镇坤乾」，逼得$N后退三步。\n",
                                                "$n以守为攻，一招「斧气破长空，义胆昭雪国」，猛击$N握$w的手腕。\n",
                                                "$n一招「宿慧万头仰，机关神人嗔」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
                                                        })
        );
        set("unarmed_parry_msg",({
                                                "$n一招「此身已共万寒赴，斗光犹指北极星」，逼得$N中途撤招。\n",
                                                "$n脚走阴阳，一招「休言天定魁星路，爱恨生死一念间」，攻$N之必救。\n",
                                                "$n左拳击下，右拳自保，一招「叹乖时蹇命，哭碧血丹心」，将$N封于尺外。\n",
                                                "$n双拳齐出，使出一招「志高云接履，魂断雪傍身」，$N的功势入泥牛入海，消失得无影无踪。\n",
                                                        })
        );
                                           
        action = ({
                        ([      "action":               "$N使一招「众星寥落意难平，干戈起处惊笛音」，对准$n的$l「呼」地一拳",
                                "dodge":                -40,
                                "parry":                40,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N扬起拳头，一招「铁马冰河腾烽烟，极光地火镇坤乾」便往$n的$l招呼过去",
                                "dodge":                -30,
                                "parry":                30,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N左手虚晃，右拳「此身已共万寒赴，斗光犹指北极星」往$n的$l击出",
                                "dodge":                -30,
                                "parry":                30,
                           "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N步履一沉，左拳拉开，右拳使出「休言天定魁星路，爱恨生死一念间」击向$n$l",
                                "dodge":                -30,
                                "parry":                30,
                                "damage_type":  "瘀伤"
                        ]),
        });
} 
mixed hit_ob(object me, object victim, int damage_bonus) {
        if(random(damage_bonus) < 350) {
                return 0;
        }
        if(!victim->query_temp("weapon") 
                        && victim->query_skill_mapped("unarmed") == "taiji"
                        && me->query_skill("unarmed") > victim->query_skill("unarmed")) {
                switch(random(3)) {
                        case 0:
                                message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                                break;
                        case 1:
                                message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                                break;
                        case 2:
                                message_vision(HIR "\n因拳法相克，$n逐渐施展不开了！" NOR,me,victim);
                                break;
                }
                return random(me->query_skill("unarmed")) * 10;
        }
        return 0;
}       
