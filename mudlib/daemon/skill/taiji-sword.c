#include <ansi.h>
inherit SKILL;
void setup() {
        set("name",                     "太极剑法");
        set("learn_bonus",              0);
        set("practice_bonus",   -200);
        set("black_white_ness", 40);
        set("effective_level",  250);
        set("usage/sword",              1);
        set("usage/parry",              1);
        set("unarmed_parry_msg",({
                "$n一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$N的$l\n",
                "$n一招「却步抽剑」，左脚跃步落地，$v回抽，反手勾向$N的$l\n",
                "$n使出「狮子摇头」，$v由右向左划出一个大８字，将$N圈在其中\n",
                "$n一招「迎风掸尘」，$v看似随意地一挥，$N却陡觉一股劲气迎面袭来。\n",
                "$n右腿半屈般蹲，一招「如封似闭」，便将$N的攻势化解了\n",        
        }) );           
        set("parry_msg",        ({
                "$n一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$N的$w\n",
                "$n一招「却步抽剑」，左脚跃步落地，$v回抽，反手勾向$N的$w\n",
                "$n使出「狮子摇头」，$v由右向左划出一个大８字，将$N的$w圈在其中\n",
                "$n一招「迎风掸尘」，$v看似随意地一挥，$N却陡觉一股劲气迎面袭来。\n",
                "$n右腿半屈般蹲，一招「如封似闭」，便将$N的攻势化解了\n",                       
        }) );
        
        set("skill_class",              "wudang");
action = ({
([      "action" : "$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l",
        "force" : 60,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 45,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「指南针」直刺$n的$l",
        "force" : 70,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 50,
        "lvl" : 4,
        "damage_type" : "刺伤"
]),
([      "action" : "$N身形往右一挫，左手剑诀，右手$w使出一式「大魁星」刺向$n的$l",
        "force" : 80,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 50,
        "lvl" : 9,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双膝下沉，右手$w使出一式「探海式」，由下而上疾刺$n的$l",
        "force" : 90,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 50,
        "lvl" : 14,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「燕子掠波」，$w自上而下划出一个大弧，平平地向$n的$l挥
去",
        "force" : 100,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 60,
        "lvl" : 19,
        "damage_type" : "刺伤"
]),
([      "action" : "$N上身往左侧一拧，一招「乌龙摆尾」，右手$w反手向$n的$l挥去",
        "force" : 110,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 70,
        "lvl" : 24,
        "damage_type" : "刺伤"
]),  
([      "action" : "$N左腿提膝，手中$w斜指，一招「宿鸟投林」刺向$n的$l",
        "force" : 130,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 70,
        "lvl" : 34,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「青龙出水」，$w自下而上划出一个大弧，平平地挥向$n的$l",
        "force" : 140,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 71,
        "lvl" : 39,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「三环套月」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n
的$l",
        "force" : 150,
        "dodge" : 10,
        "parry" : 20,
        "damage" : 73,
        "lvl" : 44,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「风卷荷叶」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 75,
        "lvl" : 49,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「虎抱头」，$w划出一个左低右高的大弧，斜斜地斩向$n的$l",
        "force" : 170,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 77,
        "lvl" : 54,
        "damage_type" : "刺伤"
]), 
([      "action" : "$N左脚踏实，右脚虚点，一招「仙人指路」，右手$w带着一团剑花，
逼向$n的$l",
        "force" : 190,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 81,
        "lvl" : 64,
        "damage_type" : "刺伤"
]),
([      "action" : "$N轻轻跃起，一招「野马跳涧」，$w在半空中化为一圈银芒，落向$n
的$l",
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 83,
        "lvl" : 69,
        "damage_type" : "刺伤"
]),
([      "action" : "$N两腿前箭后弓，一招「射雁式」，右手$w直刺$n的$l",
        "force" : 210,
        "dodge" : 20,
        "parry" : 20,
        "damage" : 85,
        "lvl" : 74,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「小魁星」，身形往左一挫，左手剑诀，右手$w平平地向$n的
$l挥去",
        "force" : 220,
        "dodge" : 40,
        "parry" : 20,
        "damage" : 87,
        "lvl" : 79,
        "damage_type" : "刺伤"
]),
([      "action" : "$N猱身扑上，一招「白猿献果」，手中$w斜斜地向$n的$l挥去",
        "force" : 230,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 89,
        "lvl" : 84,
        "damage_type" : "刺伤"
]),  
([      "action" : "$N一招「顺水推舟」，$w自上而下划出一个大弧，平平地向$n的$l挥
去。",
        "force" : 250,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 93,
        "lvl" : 94,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「流星赶月」，$w疾刺$n的$l",
        "force" : 260,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 95,
        "lvl" : 99,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然盘蹲下身来，一招「海底捞月」，$w自下而上地向$n的$l挥去",
        "force" : 270,
        "dodge" : 25,
        "parry" : 25,
        "damage" : 97,
        "lvl" : 104,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「挑帘式」，$w自下而上徐徐划出一个大弧，平平地向$n的$l
挥去",
        "force" : 280,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 99,
        "lvl" : 109,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「黄蜂入洞」，$w自上而下划出一个大弧，平平地向$n的$l挥
去",
        "force" : 290,
        "dodge" : 40,
        "parry" : 25,
        "damage" : 102,
        "lvl" : 114,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「大鹏展翅」，身形跃起，右手$w刺向$n的$l",
        "force" : 300,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 106,
        "lvl" : 119,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「车轮剑」，$w化作一片银盘，平平地向$n的$l卷去",
        "force" : 310,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 120,
        "lvl" : 124,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚轻点地面，身形往前一扑，一招「天马行空」，$w向$n的$l挥
去",
        "force" : 320,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 125,
        "lvl" : 129,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「风扫梅花」，身体跃在半空，手中$w扫向$n的$l",
        "force" : 330,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 130,
        "lvl" : 90,
        "damage_type" : "刺伤"
]),  
([  "action" : "$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l",
        "force" : 380,
        "dodge" : 35,
        "parry" : 30,
        "damage" : 160,
        "lvl" : 149,
        "damage_type" : "刺伤"
]),
}); 
}
int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够，没有办法练太极剑法。\n"); 
        if( (string)me->query_skill_mapped("force")!= "taijiforce")
                return notify_fail("太极剑法必须配合太极内功心法才能练。\n"); 
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n"); 
        return 1;
}  
int practice_skill(object me)
{       object ob; 
        if (me->query_skill("taiji-sword",1)>100)
                return notify_fail("太极剑法极为深奥，再往上得向师傅请教才行。\n");
        
        if( (string)me->query_skill_mapped("force")!= "taijiforce")
                return notify_fail("太极剑法必须配合太极内功心法才能练。\n");
        
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 20 )
                return notify_fail("你的内力或气不够，没有办法练习太极剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -20);
        write("你按著所学练了一遍太极剑法。\n");
        return 1;
} 
/*
string *parry_msg = ({
        "$n一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$N的$w\n",
        "$n一招「却步抽剑」，左脚跃步落地，$v回抽，反手勾向$N的$w\n",
                "$n使出「狮子摇头」，$v由右向左划出一个大８字，将$N的$w圈在其中\n",
                "$n一招「迎风掸尘」，$v看似随意地一挥，$N却陡觉一股劲气迎面袭来。\n",
                "$N右腿半屈般蹲，一招「如封似闭」，便将$N的攻势化解了\n",
}); 
string *unarmed_parry_msg = ({
        "$n一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$N的$l\n",
        "$n一招「却步抽剑」，左脚跃步落地，$v回抽，反手勾向$N的$l\n",
                "$n使出「狮子摇头」，$v由右向左划出一个大８字，将$N圈在其中\n",
                "$n一招「迎风掸尘」，$v看似随意地一挥，$N却陡觉一股劲气迎面袭来。\n",
                "$N右腿半屈般蹲，一招「如封似闭」，便将$N的攻势化解了\n",        
}); 
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
} 
int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return -200;
}
int black_white_ness()
{
        return 40;
} 
string perform_action_file(string action)
{
        return CLASS_D("wudang") + "/taiji-sword/" + action;
}
*/
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int myexp,urexp;
           myexp=me->query("combat_exp");
                urexp=victim->query("combat_exp")*victim->query("cps")/20;
                if (!victim->is_busy())
                if (random(myexp+urexp)>urexp && me->query_skill("taiji-sword",1)>100)
                {
                        victim->start_busy(2);
                        return HIW "$n被$N的剑势所缠，速度不由得放慢下来。\n"NOR;
                }   
}   
