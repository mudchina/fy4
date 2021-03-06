 // eagle-claw.c
inherit SKILL;
#include <ansi.h> 
void setup() {
    set("name", "鹰爪功");
        set("usage/unarmed", 1);
        set("effective_level", 150);
        set("practice_bonus", -5);
        set("practice_damage", 30);
        set("learn_bonus", 10);
        set("skill_class", "fugui");
        set("parry_msg", ({
        "$n一招「金雕擒兔」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
        "$n右拳虚晃，左拳一招「迎风振翅」，逼得$N后退三步。\n",
        "$n以攻为守，一招「拔翅横飞」，猛击$N握$w的手腕。\n",
        "$n一招「雄鹰现爪」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n一招「金雕擒兔」，逼得$N中途撤招。\n",
        "$n脚走阴阳，一招「拔翅横飞」，攻$N之必救。\n",
        "$n左拳击下，右拳自保，一招「迎风振翅」，将$N封于尺外。\n",
        "$n双拳齐出，使出一招「雄鹰现爪」，$N的攻势如泥牛入海，消失得无影无踪。\n", 
        }) );
        action = ({
                ([  "action" : "$N拔地而起，半空中一个筋斗，一式「凶鹰袭兔」，迅猛地抓向$n的$l",
                    "force" : 100,
                    "dodge" : 250,
                    "parry" : 250,
                    "damage_type" : "内伤"
                ]),
                ([  "action" : "$N单腿直立，双臂平伸，一式「雄鹰展翅」，双爪拢向$n的$l",
                    "force" : 120,
                    "dodge" : 200,
                    "parry" : 400,
                    "damage": 5,
                    "damage_type" : "内伤"
                ]),
                ([  "action" : "$N一式「拔翅横飞」，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头",
                    "force" : 150,
                    "dodge" : 200,
               "parry" : 400,
                    "damage": 10,
                    "damage_type" : "内伤"
                ]),
                ([  "action" : "$N双爪交错上举，使一式「迎风振翼」，一拔身，分别袭向$n左右腋空门",
                    "force" : 190,
                    "dodge" : 150,
                    "parry" : 450,
                    "damage": 10,
                    "damage_type" : "内伤"
                ]),
                ([  "action" : "$N全身滚动上前，一式「飞龙献爪」，右爪突出，鬼魅般抓向$n的胸口",
                    "force" : 150,
                    "dodge" : 500,
                    "parry" : 400,
                    "damage": 15,
                    "damage_type" : "内伤"
                ]),
                ([  "action" : "$N伏地滑行，一式「拨云瞻日」，上手袭向膻中大穴，下手反抓$n的裆部",
                    "force" : 110,
                    "dodge" : 265,
                    "parry" : 365,
                    "damage": 20,
                    "damage_type" : "内伤"
                ]),
                ([  "action" : "$N左右手掌爪互逆，一式「搏击长空」，无数道劲气破空而出，迅疾无比地击向$n",
                    "force" : 180,
                    "dodge" : 375,
                    "parry" : 575,
                    "damage": 25,
                    "damage_type" : "内伤"
                ]),
                ([  "action" : "$N腾空高飞三丈，一式「鹰扬万里」，天空中顿时显出一个巨灵爪影，缓缓罩向$n",
                    "force" : 170,
                    "dodge" : 800,
                    "parry" : 400,
                    "damage": 20,
                    "damage_type" : "内伤"
                ])
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练鹰爪功。\n");
        return 1;
} 
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 20) {
                return notify_fail("你的内力不够练鹰爪功。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}     
