#include <ansi.h>
inherit NPC;
void create()
{
    set_name("小黄雀", ({ "yellow bird", "bird" }) );
    set("race", "野兽");
    set("age", 1);
    set("gender", "雌性");
    set("long", "这是一只小黄雀，原本美丽的羽毛凌乱不堪。
看起来已经受伤，你似乎可以帮它包扎一下。（baozha）。\n");
    set("attitude","peaceful");
    set("limbs", ({ "头部", "身体","尾巴" }) );
    set("verbs", ({ "bite","claw" }) );
//    set("unique_amount", 1);  
//    ITEM_D->setup_unique(this_object());  
    set("eff_kee", 1);
        set("weight", 200);
        set("no_get", 1);
        set("no_give", 1);
        set("no_drop", 1);
    setup();
}  
int kill_ob(object me){   
    message_vision("$N抽搐了几下，就静止不动了。 \n",this_object());
    me->set("marks/kill_bird", 1);
    ::die();
    return 1;
}
void init() {
    ::init();

        add_action("do_heal", "baozha");
        call_out("not_cured", 60);
} 
void not_cured(){
//    if(!userp(environment(this_object()))){
        if(query("eff_kee") == 1){
                message_vision("$N抽搐了几下，就一动不动了。 \n",this_object());
                   set("long", "这是一只小黄雀，原本美丽的羽毛凌乱不堪。\n");
                ::die();
        }
} 

int do_heal(string arg) {
        object me, bird;
        
        me = this_player();
        bird = present("yellow bird", environment(me));
        if(!arg || (arg != "yellow bird" && arg != "bird")) {
                return 0;
        }
        if(!present("yellow bird", environment(me))){
                return 0;
        }
        message_vision(HIW"\n$N轻轻把$n的伤口包扎了起来。\n"NOR, me, bird); 
        message_vision(HIW"$n挣扎了几下，在$N头顶盘旋了三圈，\n然后恋恋不舍地穿云而去。\n"NOR, me, this_object());
				if(!me->query("marks/黄雀")) 
				me->set("marks/黄雀", 1);
        destruct(this_object()); 
        
        return 1;
}
