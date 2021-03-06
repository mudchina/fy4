#include <ansi.h>
inherit NPC;
void smart_fight(); 
int stone();
int stone1();
int stone2();
int stone3();
int stone4();
int stone5(); 
void create()
{
        set_name("言小小", ({ "bad kid" }) );
        set("title",WHT"阴阳童子"NOR);
        set("gender", "男性" );
        set("age", 1+ random(10));
        set("long", "这个童子身材矮小，却长着一张成人的脸，充满了阴鹜之气。\n");
        set("combat_exp", 3500000);
        set("class","shenshui");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("str",36);
        set("cor",40);
        set("no_busy",5);
        set("resistance/kee",30);
        set("resistance/gin",random(70));
        set("resistance/sen",50);
        
        set("atman",1200);
        set("max_atman",1200);
        set("mana",1000);
        set("max_mana",1200);
        set("force",1200);
        set("max_force",1200);
        set("force_factor", 90);
        
        set("inquiry", ([
                "stone" : (: stone :),
                "五彩灵石" : (: stone :),
                "天灵翡翠" : (: stone1:),
                "碧海蓝心" : (: stone2:),
           "幽冥紫晶" : (: stone3:),
                "蛰龙赤丹" : (: stone4:),
                "凝露黄石" : (: stone5:),
                "春之痕" : (: stone1:),
                "海之角" : (: stone2:),
                "风之云" : (: stone3:),
                "沙之底" : (: stone4:),
                "天之涯" : (: stone5:),
        ]));
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
                     
        set_skill("unarmed", 180);
        set_skill("force", 180);
        set_skill("longlife-force", 140);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("move", 180);
        set_skill("literate",120);
        set_skill("nine-moon-steps", 200);
        set_skill("nine-moon-claw", 180);
        set_skill("perception", 100);
        set_skill("kwan-yin-spells",130);
        set_skill("spells", 150); 
        map_skill("move","nine-moon-steps");
        map_skill("spells","kwan-yin-spells");       
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "longlife-force"); 
                
        setup();
        add_money("gold", random(5));
        carry_object("/obj/armor/cloth")->wear();
        if (!random(3)) carry_object(__DIR__"obj/hesan");
} 
smart_fight()
{
   int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie3");
                return;
        }
        return;
}    
int stone(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
                message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
                return 1;
        }
        message_vision(YEL"$N说：“太古时，共工撞倒撑天的不周山，女娲炼五彩灵石以补苍天，曾
令五灵神将在天之涯、海之角、风之云、沙之底、春之痕各处收集这五色灵石，
这五彩灵石分别是：天灵翡翠、碧海蓝心、幽冥紫晶、蛰龙赤丹、凝露黄石。
传说任何人如果能得到其中的一种，都能从中得到神奇的灵异力量。” \n"NOR,ob);
        message_vision(YEL"$N说：“这个书上写的明明白白。。。”\n",ob);
        command("heihei");
        me->delete_temp("badkid/bribe");
        return 1;
} 
int stone1(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
                message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"言小小说：“天灵翡翠在春之痕，这个风云里好多人都知道了。。。” \n"NOR);
        tell_object(me,YEL"言小小说：“记着，好运气有时是从天上掉下来的，有时却得爬在地上找。”\n"NOR);
   me->delete_temp("badkid/bribe");
        return 1;
} 
int stone2(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
                message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"言小小说：“碧海蓝心在海之角，这个海。。。” \n"NOR);
        tell_object(me,YEL"言小小吟道：“谁知十斛鲛人泪，不化明珠化血痕。”\n"NOR);
        tell_object(me,YEL"言小小说：“所以这个海边会有人，而且还是个美人。”\n"NOR);
        me->delete_temp("badkid/bribe");
        return 1;
} 
int stone3(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
                message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"言小小说：“幽冥紫晶在风之云，风之云就是风云。” \n"NOR);
        tell_object(me,YEL"言小小说：“这个东西很伤脑筋，很伤脑筋，我就不成。”\n"NOR);
        me->delete_temp("badkid/bribe");
        command("sigh");
        return 1;
} 
int stone4(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
                message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
           return 1;
        }
        tell_object(me,YEL"言小小说：“蛰龙赤丹在沙之底。” \n"NOR);
        tell_object(me,YEL"言小小耐心地向你解释道：“在地下的龙，叫做‘蛰龙’，就像蛇到了冬天，便要
蛰在地下一样，到了惊蛰以后，天上雷响，它才出来。”\n"NOR);
        me->delete_temp("badkid/bribe");
        return 1;
} 
int stone5(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
                message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"言小小说：“凝露黄石在天之涯。” \n"NOR);
        tell_object(me,YEL"言小小说：“这个天之涯指的是跑路，当年我登黄山，游风云，西至关外，东临
桃源，等了三天三夜，最后功亏一篑，那个火儿大呀。。。”\n"NOR);
        me->delete_temp("badkid/bribe");
        command("hit");
        return 1;
}  
int accept_object(object who, object ob)
{
        if (ob->value()>=100000) {
                command("giggle");
                command("say 有问题就问吧。");
                who->set_temp("badkid/bribe",1);
                return 1;
        } 
        
        command("say 这么点。。开玩笑吧。");    
        return 0;
        
}     
