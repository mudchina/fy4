#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("白衣武士", ({ "wu shi" }) );
        set("gender", "男性");
        set("age", 35);
        set("long",
"
这是位蝙蝠岛岛主座前白衣武士，身披钢甲，手执长剑，双目精光炯炯，
警惕地巡视着四周的情形。
\n"
    );
       set("combat_exp", 2500000);
        set("attitude", "heroism");
        set("class","huashan");
        set("con", 40);
        set("int",40);
        set("agi", 40);
        set("str",30);
        set("force", 400);
        set("max_force",400);
        set("force_factor",80); 
        set_temp("apply/attack",  40);
        set_temp("apply/dodge", 40);
        set_temp("apply/parry", 40); 
        set_skill("sword", 200);
        set_skill("move", 200);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force",100);
        set_skill("hanmei-force",100);
        set_skill("qingfeng-sword",160);
        set_skill("pyrobat-steps",200);
        map_skill("force","hanmei-force");
        map_skill("dodge","pyrobat-steps");
        map_skill("sword","qingfeng-sword");
        map_skill("parry","qingfeng-sword"); 
        setup(); 
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/armor_steel")->wear();
}    
