 // painting.c
inherit SKILL;
void setup() {
        set("name", "画道");
        set("usage/force", 1);
        set("skill_class", "baiyun");
        set("effective_level", 250);
        set("learn_bonus", -30);
        set("practice_bonus", -30);
        set("black_white_ness", 30);
        set("parry_msg",  ({
        "$n凝神静气，暗合弈道要旨，刹那间对$N的攻势了如指掌。\n",
        }) );
}   
