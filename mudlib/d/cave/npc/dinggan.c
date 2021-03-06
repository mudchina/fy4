#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
    set_name("丁干", ({"ding gan","ding"}) );
    set("gender", "男性" );
    set("nickname", CYN"七巧手"NOR);
    set("title", "青龙会 刺客");
    set("long", "一个很高大的人，高大的有些臃肿，但一双手却灵巧得很，谁又会知道
这双灵巧的手竟可以瞬息之间撕裂猎物的咽喉。。\n");
        set("class","wolfmount");
        set("attitude", "friendly");
        set("age", 35);
        set("cor", 25);
        set("cps", 25);
        set("per", 11);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 50);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("combat_exp", 3000000);
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/kee",30);
                }
                
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("wolf-claw", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("xueyeqianzong",150);
        
        map_skill("unarmed", "wolf-claw");
        map_skill("dodge","xueyeqianzong");
        map_skill("move","xueyeqianzong");
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "丁干仔仔细细修理着指甲，目中突然露出一种残酷的笑容。\n",
        }) ); 
        setup();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
                else add_money("gold", random(3));
        carry_object(__DIR__"obj/xiuzhiblade");
        carry_object("obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/waternut");
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        if (!ob->query("vendetta/authority")){
            message_vision("$N嘿嘿道：够胆量！私闯青龙会的地头，拿命来吧！\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
   }
        return;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query("kee")>4000)
                        {
                                this_object()->smart_busy();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("unarmed.ningxie");
}
smart_attack() {
        this_object()->perform_action("unarmed.shiden");        
        }    
