 // five-steps.c
inherit SKILL;
void setup() {
        set("name", "五行身法");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 200);
        set("learn_bonus", 10);
        set("skill_class", "wudang");   
        set("practice_bonus", -5);
        set("black_white_ness", -5);
        set("dodge_msg", ({
        "但是$n身形有如流水，轻轻一闪，一式水字决中的「抽刀断水」，举重若轻的避开这一击。\n",
        "$n身随意转，脚踩五行，一式五行「木字决」，倏地从木门挪开了三尺，避过了这一招。\n",
        "可是$n侧身一让，使出五行身法中的「金字决」，$N这一招扑了个空。\n",
        "却见$n足不点地，幻出五个身影，从火门往旁窜开数尺，躲了开去。\n",
        "$n身形微晃，使出五行「土字决」，土遁到了$N的身后。\n",
        }) );
}
int valid_learn(object me)
{
if((int)me->query_skill("changelaw", 1) < (int)(me->query_skill("five-steps", 1)/2)) {
                return notify_fail("你对易经的了解还不够高深，无法学习五行身法。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("five-steps",1) > 100)
                return notify_fail("练习已经不能加深你的领悟，你的五行身法只能通过演变「八阵图」来提高了。\n");
        if((int)me->query("force") < 10) {
                return notify_fail("你的内力不够，不能练五行身法。\n");
        }
        me->add("force", -10);
        return ::practice_skill(me);
}     
