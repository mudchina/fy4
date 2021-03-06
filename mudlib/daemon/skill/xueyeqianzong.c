 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "雪野潜踪");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 190);
        set("learn_bonus", 10);
        set("practice_bonus", -10);
        set("skill_class", "wolf");
        set("dodge_msg", ({
                "$n脚下游移不定，轻飘飘，不费力地闪在一旁。 \n",
                "$n用一种近似漂浮的动作滑开数步，躲开了$N的攻击。 \n",
                "$n侧身斜纵，远远跳开，同时回头紧盯$N招式的破绽。 \n",
                "$n左右闪动，迷惑了$N的视线，令$N的招式落空。 \n"
        }) );
} 
int practice_skill(object me)
{
        if( (int)me->query("force") < 5 ){
            return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        return 1;
}     
