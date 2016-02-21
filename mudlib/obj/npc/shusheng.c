 // teacher.c
inherit NPC; 
void create()
{
        int i,amun;
        string *order = ({"ÕÅ", "Íõ", "Àî", "ÕÔ", "Ëï", "Ğì", "Ö£", "ÖÜ", "Îâ",
"½¯", "Éò", "Ñî", "Ãç", "Òü", "½ğ", "Îº", "ÌÕ", "Óá", "Áø", "Öì"});
        string *orderr = ({"°¢·¢", "²ğ°Æ", "²Ã´ğ", "·¢¸ì", "Âèßí",
"Å·ÅÉ", "»ú¿§", "À°Âê"});
        set_name( order[random(20)] + orderr[random(8)], ({ "shusheng", "sheng" }) );
        set("title", "ÂäµÚÊéÉú");
        set("gender", "ÄĞĞÔ" );
        set("age", random(20)+20);
        set("int", 26);
        set("long",
                "ËûÒÔ½ÌÊéÎªÒµ.\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) ); 
        set("attitude", "peaceful");
        set_skill("literate", 40);
        set("combat_exp", random(50));
        set_skill("dodge", random(5));
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}      
