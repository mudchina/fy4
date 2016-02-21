 // heaven_soldier.c
#include <ansi.h> 
inherit NPC;
//void backattack();
void create()
{ 
        set_name("ÊÌÎÀ", ({ "shiwei", "guard" }) );
        set("long", "ÕâÊÇÒ»Î»³¯Í¢µÄ´øµ¶ÊÌÎÀ£¬Ìı´Ó³¯Í¢Ãü¹ÙµÄÖ¸»Ó¡£\n");
        set("attitude", "friendly");
//      set("vendetta_mark","authority");
        set("title","³¯Í¢Ãü¹Ù ÆßÆ·´øµ¶ÊÌÎÀ");
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100); 
        set("combat_exp", 100000);
        set_skill("blade", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 70);
        set_skill("fall-steps",70);
        set_skill("shortsong-blade",70);
        map_skill("blade","shortsong-blade");
        map_skill("parry","shortsong-blade");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps"); 
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();
} 
void leave()
{
        object owner,*pros;
        message("vision",
                 name() + "ÉÁÁËÉÁ¾ÍÏûÊ§²»¼ûÁË¡£\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
                   pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        destruct(this_object());
}  
void init()
{
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
        add_action("do_kill","kill");
        add_action("do_dismiss","dismiss");     
}  
void heart_beat()
{
        object leader;
        
        ::heart_beat();
        
        if(query_temp("is_unconcious")||is_busy())
                return ;
        if(query("possessed"))
        {
                leader=query("possessed");
                if(environment(leader)!=environment()&&(!leader->is_ghost()))
                {
                        message_vision("$N´Ò´ÒÀëÈ¥¡£\n",this_object());
                        this_object()->move(environment(leader));
                        message_vision("$N×ßÁË¹ıÀ´¡£\n",this_object());
                        delete("leave_room");
                }
        }
        
        else
        {
                if(!query("leave_room"))
                        set("leave_room",1);
                else
                        add("leave_room",1);
                if(query("leave_room")==5)
                        leave();
   }
} 
int do_dismiss(string arg)
{
        object who,obj;
        
        if(!arg) return 0;
        if(!obj=present(arg,environment()))
                return 0;
        if(obj!=this_object()) return 0;
        who=this_player();
        if(who->query("sen")<200)
        {
                tell_object(who,"ÄãµÄĞÄÉñ²»¹»£¬ÎŞ·¨¶Ô±øÊ¿ÏÂÃüÁî¡£\n");
                return 1;
        }
        if(who!=query("possessed")) return 0;
        who->add("sen",-200);
        message_vision("$N¶Ô$nËµµÀ£º¡°ÕâÀï²»ĞèÒªÄãÁË£¬ÏÂÈ¥°É¡£¡£¡£¡±\n",who,obj);
        obj->ccommand("inn "+who->query("id"));
        call_out("leave",1);
        return 1;
}  
int do_kill(string arg)
{
        object victim,who;
        
        who=this_player();
        if(!arg) return 0;
        if(environment()->query("no_fight"))
                return 0;
        victim=present(arg,environment());
        if(!victim) return 0;
        if(victim==who) return 0;
        if(victim->query("possessed")==who)
        {
                tell_object(who,"Äã²»ÄÜÉ±×Ô¼ºµÄ»¤ÎÀ£¬·ñÔò²¿ÏÂ»áÀëĞÄÀëµÂµÄ¡£\n");
                return 1;
        }
        if(victim==query("possessed")||victim->query("possessed")==query("possessed"))
   if(who->query("vendetta_mark")!="authority")
        {
                message_vision("$NºÈµÀ£º¡°´óµ¨·ËÍ½£¬¾¹È»¸Ò¼Óº¦³¯Í¢Ãü¹Ù£¡£¡¡±\n",this_object());
                kill_ob(who);
        }
        if(who==query("possessed")&&victim->query("vendetta_mark")!="authority")
        {
                message_vision("$N¶Ô"+victim->query("name")+"ºÈµÀ£º¡°´óµ¨·ËÍ½£¬»¹²»ËÙËÙÊøÊÖ¾ÍÇÜ£¿¡±\n",this_object());
                kill_ob(victim);
        }
        return 0;
} 
string *lname = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ","½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ğí","ºÎ","ÂÀ","Ê©","ÕÅ",
"¿×","²Ü","ÑÏ","»ª","½ğ","Îº","ÌÕ","½ª","Æİ","Ğ»","×Ş","Ó÷","°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ğ","ŞÉ","·¶","Åí","ÀÉ",
"Â³","Î¤","²ı","Âí","Ãç","·ï","»¨","·½","Éµ","ÈÎ","Ô¬","Áø","µË","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ",
"ÌÙ","Òó","ÂŞ","»ª","ºÂ","Úù","°²","³£","ÀÖ","´ô","Ê±","¸¶","Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","Ó¯","Æ½","»Æ",
"ºÍ","ÄÂ","Ğ¤","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ","Ã×","±´","Ã÷","²Ø","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ",
"ĞÜ","¼Í","Êæ","Çü","Ïî","×£","¶­","Áº","·®","ºú","Áè","»ô","Óİ","Íò","Ö§","¿Â","êÃ","¹Ü","Â¬","Ó¢","Íò","ºò","Ë¾Âí",
"ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ğ","ÎÅÈË","¶«·½","ºÕÁ¬","»Ê¸¦","Î¾³Ù","¹«Ñò","å£Ì¨","¹«ÖÎ",
"×ÚÕş","å§Ñô","´¾ÓÚ","µ¥ÓÚ","Ì«Êå","ÉêÍÀ","¹«Ëï","ÖÙËï","Ô¯Ğù","Áîºü","ÖÓÀë","ÓîÎÄ",
"³¤Ëï","Ä»Èİ","Ë¾Í½","Ê¦¿Õ","ò§¿×","¶ËÄ¾","Î×Âí","¹«Î÷","Æáµñ","ÀÖÕı","ÈÀæá","¹«Á¼",
"ÍØÖº","¼Ğ¹È","Ô×¸¸","¹ÈÁº","³ş½ú","ÑÖ·¨","ÈêÛ³","Í¿ÇÕ","¶ÎÇ§","°ÙÀï","¶«¹ù","ÄÏ¹ù",
"ºôÑÓ","¹éº£","ÑòÉà","Î¢Éú","ÔÀ","Ë§","çÃ","¿º","¿ö","ºó","ÓĞ","ÇÙ","ÁºÇğ","×óÇğ","¶«ÃÅ","Î÷ÃÅ",
    }); 
void invocation(object who, int level)
{
        int i;
        object *enemy,*pros;
        
        set_name(lname[random(sizeof(lname))]+"ÊÌÎÀ",({ "shiwei", "guard" }) );
        set("str",30+random(level/7));
        set("agi",30+random(level/7));
        set("cor",30+random(30));
        set("max_kee",1000+random(level*level/30));
        set("eff_kee",query("max_kee"));
        set("kee",query("max_kee"));
        set_skill("blade", 70 + random(level/2));
        set_skill("parry", 70 + random(level/2));
        set_skill("dodge", 70 + random(level/2));
   set_skill("move", 70 + random(level/2));
        set_skill("shortsong-blade",50+random(level/4));
        set_skill("fall-steps",50+random(level/2)); 
        
        set("combat_exp", 100000 + level*level*10+random(level*level*level/16));
        set("max_force",1000+random(level*level/10));
        set("force",query("max_force"));
        set("force_factor",50+random(level/8));
        set("possessed",who);
        pros = who->query_temp("protectors");
        if(sizeof(pros))
                pros += ({ this_object() });
        else
                pros = ({ this_object() });
        who->set_temp("protectors",pros);
}
/*
void backattack()
{
        int i;
        object owner, *enemy;
        if(objectp(owner=this_object()->query("possessed")))
        {
                enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        } 
        } 
}
*/
void die()
{
        object owner,*pros;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        ::die();
} 
/*
        message("vision",
                 name() + "ºÈµÀ£º´óµ¨£¡¾¹¸ÒºÍ³¯Í¢Ãü¹Ù¹ı²»È¥£¡\n"NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
*/ 
int attack()
{
        object opponent,owner;
        int exp,extra;           
        opponent = select_opponent();
        if(objectp(opponent)) {
                set_temp("last_opponent", opponent);
        owner=query("possessed");
        if(opponent==owner)
        {
                this_object()->ccommand("ah");
                message_vision("$N¶Ô$nËµµÀ£º¡°²»ÖªÊÇ´óÈË£¬Ğ¡ÈË¸Õ²Å¶à¶àÃ°·¸ÁË£¬»¹Çë´óÈËË¡×ï¡£¡±\n",this_object(),owner);
                this_object()->ccommand("escape");
                leave();
                return 1;
        }
        
        exp=opponent->query("combat_exp");                              
        extra=owner->query_skill("leadership",1);
        if(random(extra/10) ) 
           COMBAT_D->fight(this_object(), opponent);
        else 
                if(random(exp)>extra*extra*extra)
                {
                        message_vision("$N´óÉùº°µÀ£º¡°ÔôÈËÊÆ´ó£¬»¹ÊÇ±£ÃüÎªÏÈ°É¡£¡±\n",this_object());
                        this_object()->ccommand("escape");
                        leave();
                }
        return 1;
        } else
                return 0;
}  
