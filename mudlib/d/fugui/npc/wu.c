#include <ansi.h>
inherit NPC;
void create()
{
        set_name("蜈蚣神", ({ "wugong shen", "shen" }) );
        set("long",
         "丑，非常丑，及其丑，能够形容他的恐怕只有这个字：丑！。\n");
        set("nickname", HIC "千手千眼"NOR); 
        set("per",2);
        set("combat_exp", 1400000);
        set("force",500);
        set("max_force",500);
        set("no_arrest",1);
        set_temp("apply/damage",50);
        set_skill("unarmed", 150);
        set_skill("force",100);
        set_skill("parry",180);
        set_skill("dodge", 200);
        set_skill("move",200);
        set_skill("spear",150);
        set_skill("xuezhan-spear",90);
        set_skill("hawk-steps",150);
        set_skill("skyforce",100);
        set_skill("dragonstrike",130);
        
        map_skill("unarmed","dragonstrike");
        map_skill("spear","xuezhan-spear");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps");
        map_skill("force","skyforce");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/spear")->wield();
} 
void init()
{
                ::init();
                add_action("do_get","get");
} 
int do_get(string arg)
{
        string what,where;
        if(!arg) return notify_fail("你想拿什么？\n");
        if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
        if((where == "fentou" || where == "坟头" ))
        {
                command("say 想拿解药，先过了我这一关再说。");
                return 1;
        }
}    
