#include <ansi.h>
#include <command.h> 
inherit "/d/taiping/npc/smart_npc"; 
void create()
{ 
        set_name("°×ÒÂ´óºº",({"white cloth man","man"}));
        set("title",WHT"Àî¼Ò×¯"NOR);
        set("long", "°×ÒÂ´óººÒ»ÊÖÕÆµÆ£¬Ò»ÊÖÎÕµ¶£¬×·Ñ²ÔÚ×¯ÄÚ¡£Ñ©°×µÄÒÂÉÀÖ®ÉÏÏÊÑª°ß²µ£¬µ¶ÓëµÆ»Ô
Ó³£¬µ¶¹âÖÐÉÁ×ÅÑª¹â¡£ËûÃÇµÄÑÛÍ«Òà·ÂÈçÊÉÑª£¬ËÄÏÂËÑË÷£¬ËÆºõÒâÓÌÎ´¾¡¡£\n");
        set("age",40);
        set("combat_exp", 9500000);
                
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set_skill("iron-cloth",150);
        set_skill("xisui",80);
        map_skill("iron-cloth","xisui");
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
   
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("xuebin",250,200,1,"/obj/weapon/","fighter_w","random",2);
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
}      
