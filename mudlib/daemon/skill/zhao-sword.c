 // zhao-sword.c 五展梅剑法
inherit SKILL; 
void setup() {
        set("name",                                     "五展梅剑法");
        set("usage/sword",                      1);
        set("usage/parry",                      1);
        set("practice_damage",          40);
        set("effective_level",          150);
        set("skill_class",                      "quanli");
        set("unarmed_parry_msg",        ({
                        "$n使出一招「吹梅笛怨」，用手中的$v急削$N的五指。\n",
                        "$n左脚踏前一步，一招「梅花雪落覆白苹」，手中的$v从侧面飘向$N之必救。\n",
                        "$n手中的$v一抖，挽出一片剑花，一招「砌下落梅如雪乱」，撒向$N的全身。\n",
                        "$n微退一步，手中的$v划出一条光弧，一招「云破月来花弄影」，将$N的全身围住。\n",
                        "$n使出一招「花开堪折直须折」，用手中的$v急砍$N。\n",
                        "$n左脚踏前踏，一招「寒山一带伤心碧」，手中的$v挥向$N之必救。\n",
                        "$n手中的$v一抖，一招「红颜未老恩先绝」，奔向$N。\n",
                        "$n手中的$v划出一招「虚妄笑红」，将$N的全身围住。\n",
                        })
        );
        action = ({
                ([      "action":"\n$N一式「梅花孤峭」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
                "force" : 160,
                "dodge" : 5,
                "damage": 30,
                "damage_type":  "刺伤"
                ]),
                ([      "action":"$N纵身轻轻跃起，一式「梅花点点枝头」，剑光如水，一泻千里，洒向$n全身",
                "force" : 180,
                "dodge" : 10,
                "damage": 35,
                "damage_type":  "割伤"
                ]),
                ([      "action":"$N手中$w一沉，一式「无限清爽」，无声无息地滑向$n的$l",
                "force" : 250,
                "dodge" : 15,
                "damage": 40,
                "damage_type":  "割伤"
                ]),
                ([      "action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「恩怨缠绵」刺向$n的咽喉",
           "force" : 320,
                "dodge" : 15,
                "damage": 55,
                "damage_type":  "刺伤"
                ]),
                ([      "action":"\n$N呼的一声拔地而起，一式「如雪飞落」，$w幻出万道光影，将$n团团围住",
                "force" : 420,
                "dodge" : 15,
                "damage": 70,
                "damage_type":  "内伤"
                ]),
                ([      "action":"$N随风轻轻飘落，一式「雾里看花」，手中$w平指，缓缓拍向$n脸颊",
                "force" : 450,
                "dodge" : 15,
                "damage": 80,
                "damage_type":  "内伤"
                ]),
                ([      "action" : "$N募的使一招「绝代风华」，顿时剑光中几朵血花洒向$n全身",
                "force" : 500,
                "dodge" : 25,
                "damage": 100,
                "damage_type":  "内伤"
                ]),
        });
} 
int valid_learn(object me) {
        object ob;
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query("max_force") < 100) {
                return notify_fail("你的内力不够。\n");
        }
        if ((int)me->query_skill("wuchenforce", 1) < 20) {
                return notify_fail("你的无尘心法火候太浅。\n");
        }
        if ((int)me->query_skill("force", 1) < 20) {
                return notify_fail("你的基本内功火候太浅。\n");
        }
   return 1;
}
