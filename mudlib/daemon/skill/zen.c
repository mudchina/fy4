 // buddhism.c
inherit SKILL; 
void setup() {
        set("name",                     "禅道");
        set("type",                     "knowledge");
        set("learn_bonus",              -400);
        set("practice_bonus",           -40);
        set("black_white_ness",         50);
        set("effective_level",          200);
        set("usage/literate",           1);
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("你的杀气太重，无法修炼禅道。\n");
        return 1;
} 
int learn_bonus() {
        
        if(this_player()->query_skill("zen",1)<=165)
                return -50;
        return -400;
}        
