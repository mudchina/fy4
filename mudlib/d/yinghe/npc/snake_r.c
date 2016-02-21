#include <ansi.h>
inherit NPC;
void use_poison(); 
void create()
{
    set_name("ÏìÎ²Éß", ({ "rattle snake", "snake" }) );
    set("race", "Ò°ÊÞ");
    set("age", 4);
    set("long", "Ò»Ìõ²»¶ÏÒ¡¶¯Î²°Í·¢³ö¿©¿©ÉùµÄÏìÎ²Éß¡£\n");
    set("limbs", ({ "Í·²¿", "ÉíÌå", "Î²°Í", "Æß´ç" }) );
    set("verbs", ({ "bite" }) );
//    set("attitude", "aggressive");
    set_skill("dodge", 50);
    set("combat_exp", 5000000 + random(2000000));
        set("bellicosity", 300 );
    set("chat_chance_combat", 1);
    set("chat_msg_combat", ({
            (: use_poison :),
    }) );
    setup(); 
} 
void use_poison(){
    object *enemy, ob;
    string msg; 
    enemy = query_enemy();
    if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
    tell_object(ob,
"Äã¾õµÃÁ³ÉÏ¾çÍ´£¬ÉìÊÖÒ»Ãþ·¢ÏÖÁ½¸ö¶¾ÑÀÓ¡ºÛ¡£\n");
            ob->apply_condition("snake_poison", 
            (int)this_player()->query_condition("snake_poison")
            + random(3)+3);
}       
