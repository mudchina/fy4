 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("严人英", ({ "yan renying","yan" }) );
        set("gender", "男性" );
        set("title", "峨嵋派 少侠" );
        set("nickname", HIC"三英四秀之"NOR );
        set("long",
       "一个眼睛布满血丝的年轻人，细长有力的手紧握刀柄。刀柄上密密的缠著一层柔丝，\n好让手握在上面时更容易使力，还可以吸于掌心因紧张而沁出的汗。\n"
                );
        set("attitude", "peaceful");
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 300000);
        
        set("force", 500);
        set("max_force", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 20);
        set("inquiry",  ([
                "叶孤城" : "我也是听说叶孤城躲在这儿，便寻了过来，可是除了一条浸\n血渍的布条外，便什么也没有了。。\n",
                "master ye" : "我也是听说叶孤城躲在这儿，便寻了过来，可是除了一条浸\n血渍的布条外，便什么也没有了。。\n",
                "西门吹雪" : "西门。。他抢走我心爱的师妹，杀我师弟，还。。杀了我师傅，这血海深仇\n我就是拼了命也要报。\n",
                "master ximen" : "西门。。他抢走我心爱的师妹，杀我师弟，还。。杀了我师傅，这血海深仇\n我就是拼了命也要报。\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 5);
        set("chat_msg", ({
                "严人英踌躇道：南海白云岛乃叶孤城的老巢，他莫非怕了西门吹雪，逃回去了？\n",
                "严人英握紧拳头道：叶孤城。。叶孤城，你在哪里？只有找到你才可能找到西门那凶手。。。 \n",
                }) ); 
        set_skill("blade", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("move", 50);
        set_skill("shenji-blade", 50);
        set_skill("shenji-steps", 50);                
        map_skill("parry", "shenji-blade");
        map_skill("blade", "shenji-blade");
        map_skill("move", "shenji-steps");
        map_skill("dodge", "shenji-steps");
        setup(); 
        carry_object("/obj/weapon/blade")->wield();
        add_money("gold",5);
        carry_object("/obj/armor/cloth")->wear();
}      
