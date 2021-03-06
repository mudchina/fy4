#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int force_convert();
int leave();
void create() 
{
    set_name("枯梅大师", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
这是一个白发苍苍的老妇，一张干枯瘦削的脸上满是伤疤，耳朵缺了半个，
眼睛也少了一只，剩下的一只眼睛半开半合，开合之间，精光暴射，无论谁也
不敢逼视。她身子很瘦小，但却有种说不出来的威严，无论谁人只要瞧上她 
一眼，连说话的声音都会压低些。
\n"
        );
    set("nickname", HIW "铁仙姑"NOR);
    set("gender", "女性");
    set("class","huashan");
    create_family("华山派", 16, "掌门");
    set("rank_nogen",1);
    set("student_title","弟子");
    set("reward_npc", 1);
    set("difficulty", 5);
    set("age", 59);
    set("int", 30);
    set("per", 3);
    set("con", 25);
    set("str",28);
    
    set("force", 1000);
    set("max_force", 1000);
    set("force_factor", 70);
    set("combat_exp", 3200000);
    set("attitude", "friendly"); 
    set_skill("unarmed", 140);
    set_skill("zhaixin-claw",100);
    set_skill("move", 140);
    set_skill("dodge", 140);
    set_skill("parry", 140);
    set_skill("literate", 140);
    set_skill("force", 180);
    set_skill("dugu-sword", 100);
    set_skill("sword", 150);
    set_skill("anxiang-steps", 140);
    set_skill("tanzhi-shentong", 120);
    set_skill("throwing", 150);
    set_skill("hanmei-force", 120);
    set_skill("qingfeng-sword", 150);
    set_skill("perception", 100); 
    map_skill("force", "hanmei-force");
    map_skill("move", "anxiang-steps");
    map_skill("parry", "dugu-sword");
    map_skill("sword", "qingfeng-sword");
    map_skill("dodge", "anxiang-steps");
    map_skill("unarmed", "zhaixin-claw");
    map_skill("throwing", "tanzhi-shentong");
    map_skill("sword", "qingfeng-sword");
        
        set("inquiry", ([
//              "hanmei-force" : (: force_convert :),
//              "寒梅心法" : (: force_convert :),
                "leave" : (: leave :),
        ])); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                 (: perform_action, "throwing.mantianhuayu" :),
        }) ); 
        
        
    set("ranks",({"弟子","小侠","少侠","大侠","奇侠",WHT"狂侠"NOR,WHT"侠圣"NOR,HIW"隐侠"NOR}));
    setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/cloth", 
                ([      "name"  :       HIB "蓝缎袍"NOR,
                        "long"  :       0 ])
                )->wear();
}  
void attempt_apprentice(object ob)
{
    if (ob->query("gender")=="男性") {
           command("say 华山只收女子为徒。\n");
        return;
    }   
    if (ob->query_skill("sword",1) < 19) {
         command("say  你对剑术所知甚少，竟然想来拜我！");
                return;
    }
    if ((int)ob->query_skill("move",1) < 19 ) {
        command("say 阁下的身法似乎不能学武啊！");
                return;
    }
/*    if ((int)ob->query("age") > 15 ) {
        command("say 所谓少壮不努力，老大徒伤悲，我看阁下于武学一道没什么前途。");
                return;
    }*/ 
    command("recruit " + ob->query("id"));
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
           if(id_class == "huashan"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：贫尼的徒弟，容不得阁下来管教！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int force_convert(){
        object me;
        int level;
        me = this_player();
        message_vision("$N郑重地说：“寒梅心法乃华山之宝，我也是刚领悟到其中的奥妙。\n", this_object());
        if (me ->query("class")!= "huashan") return 1;
        if (!me->query_skill("wuzheng-force")) return 1;
        me->start_busy(4);
        level= me->query_skill("wuzheng-force");
        me->delete_skill("wuzheng-force");
        me->set_skill("hanmei-force",level);
        message_vision("$N说：为师今日就传你这一心法的口诀。\n",this_object());
        message_vision("$N一手按在$n的背心，轻声地默念着什么。。。。\n",this_object(),me);
        tell_object(me,HIW"你觉得一股寒流从枯梅大师的掌心传了过来。\n"NOR);
        call_out("convert_done", 5, me);
        return 1;
}  
int convert_done(object me) {
        tell_object(me,HIW"寒流在你的周身流动，许久，你渐渐平静下来。\n"NOR);
        message_vision("$N对$n说：好了，你去慢慢体会吧，为师要休息了。\n",this_object(),me);
        return 1;
} 
int leave() {
        if (this_player()->query("class")!="huashan") return 0;
        message_vision(CYN"$N冷笑一声，“华山竟然有这样的弟子。“\n"NOR, this_object());
        message_vision(CYN"$N说：寒梅心法和摘心手的秘诀你得留下。\n"NOR,this_object());
        return 1;
}  
