 //
inherit NPC;
inherit F_VENDOR;
int bamboo();
void create()
{
        set_name("小担贩", ({ "danfan", "dan fan" }) );
        set("gender", "男性" );
        set("age", 25);
        set("long",
                "一个挑着担子（ｄａｎｚｉ）到处贩卖的小贩，担子放在他身旁的地上两头摆满
各色货品，他正在兜卖游人食品货物，价钱虽然稍贵了些，但是东西还不错。\n");
        set("combat_exp", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "小担贩摇动着手中的拨浪鼓。\n",
        }) );
                set("inquiry", ([
                        "竹筒" : (: bamboo :),
                        "zhutong" : (: bamboo :),
                ]));
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/dumpling" : 10,
                        __DIR__"obj/chicken_leg":10,
                        "/d/fy/npc/obj/yanzhi" : 3,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{
        ::init();
        add_action("do_vendor_list", "list");
} 
int bamboo(){
        object me, ob;
        
        me = this_player();
        if(me->query("marks/慷慨") && environment(this_object())->query("item_bamboo")){
           message_vision("$N对$n道：“既然这位" + RANK_D->query_respect(me) + "喜欢，就送给你把。”\n",
                                this_object(), me);
                message_vision("$N弯腰拿起一个小竹筒递给$n。\n", this_object(), me);
                ob = new(__DIR__"obj/bamboo_cont");
                if(objectp(ob)){
                        ob->move(me);
                }
                environment(this_object())->set("item_bamboo", 0);
        } else {
                message_vision("$N抬头看看$n道：“这位客官还是看看别的物品吧。”\n", this_object(),me);
        }
        return 1;
}   
