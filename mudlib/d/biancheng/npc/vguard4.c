#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("��ʮ",({"ma shi","ma","shi"}));
        set("title","������");
        set("long","����Ⱥ������������û�����֣�ֻ�д��š�\n");
        set("gender","����");
        set("age",42);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
       
    set_skill("move", 110);
    set_skill("dodge", 110);
    set_skill("force", 110);
    set_skill("literate", 140);
    set_skill("unarmed",110);
    set_skill("puti-steps",110);
    set_skill("dabei-strike",110);
    set_skill("zen",130);
    set_skill("chanting",110);
    set_skill("xiaochengforce",110);
    set_skill("staff",220);
    set("class","shaolin");
    set_skill("parry",110);
    set_skill("fumostaff",150);
    set_skill("blade",110);
    set_skill("liuxing-hammer",110);
    set_skill("hammer",110);
    map_skill("hammer","liuxing-hammer");
    set_skill("lianxin-blade",110);
//  set_skill("xingyi-stick",110);
    map_skill("staff","fumostaff");
    map_skill("parry","fumostaff");
    map_skill("dodge", "puti-steps");
    map_skill("force", "xiaochengforce");
    map_skill("unarmed", "dabei-strike");
    map_skill("blade","lianxin-blade");
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: perform_action, "staff.hequhecong" :),
        
            }) );

        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",2200000);  
        set("attitude", "friendly");
        
        
        //set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        
        set("chat_chance",1);
        set("chat_msg",({
//                "��������ɫ������ϴ������Ԫ������������ϴ���õġ���\n"
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//   auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    carry_object("/obj/weapon/staff")->wield();    
}     