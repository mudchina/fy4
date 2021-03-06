 inherit NPC;
void create()
{
        set_name("商人", ({ "trader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位从关外来的商人。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("env/wimpy", 30);
        set_skill("blade", 30);
        set_skill("shortsong-blade", 10);
        set_skill("fall-steps", 30);
        set_skill("dodge", 100);
        set_skill("parry", 20);
        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");
        set("chat_chance", 2);
        set("chat_msg", ({
                "商人问道：大漠流沙真的那么可怕吗？！\n",
                (: random_move :),
        }) );
        setup();
        add_money("coin", 50);
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/hu-blade")->wield();
        carry_object(__DIR__"obj/perfume");
        carry_object(__DIR__"obj/fake-tooth");
} 
