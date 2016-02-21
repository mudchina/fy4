 // yoga.c
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                             "è¤çì");
        set("effective_level",          50);
}
        
void skill_improved(object me) {
        int s;
        
        s = me->query_skill("yoga", 1);
        if( s%10==9 && (int)me->query("dur") < s/5) {
                tell_object(me, HIW "ÓÉì¶ÄãÇÚÁ·è¤çì£¬ÄãµÄÄÍÁ¦Ìá¸ßÁË¡£\n" NOR);
//              me->add("dur", 2);
                me->set("dur",(s+1)/5);
        }
}       
