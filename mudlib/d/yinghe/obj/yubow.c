#include <ansi.h>
inherit ITEM;
int shoot(object me);
void create()
{
        set_name(HIC"截玉伏弩"NOR, ({ "crossbow", "jade bow", "yu bow" }) );
        set_weight(70000);
        set("no_shown", 1);
        set("no_get", 1);
        set("no_drop", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个似弓似弩的怪东西，似乎是猎人用来扑捉动物的。
也许可以安装（ｉｎｓｔａｌｌ）试试。\n");
                set("value", 1000);
        set("material", "metal");
    }
        ::init_item();
} 
void init(){
        object me;
        
        me = this_player();
        if(this_player()==environment()) {
        add_action("do_install", "install");
    }
        add_action("do_search", "search");
        if(query("installed") && environment(me) == environment(this_object())){
                call_out("shoot", 1, me);        
        }
} 
int do_install(string arg){
        object me, arrow;
        int i;
        
        me = this_player();
        if(!arg || arg != "bow" && arg != "crossbow"){
                return notify_fail("你要装什么？\n");
   }
        if(present("installed bow", environment(me)) || environment(me)->query("no_fight")){
                return notify_fail("你没找到合适的地方。\n");
        }
        arrow = present("small arrow", me);
        if(!objectp(arrow)){
                return notify_fail("缺少箭头，没有办法安装。\n");
        } else {
                i = arrow->query_amount();
                if(i < 10){
                        return notify_fail("缺少箭头，没有办法安装。\n");
                }
        }
        if(me->query("kee") < 100) {
                return notify_fail("你实在太累了，先休息一下吧。\n");
        }
        if(query("installed")){
                delete("installed");
                tell_object(me, HIG"你找了个隐蔽角落仔细把弓安装好。\n"NOR);
                this_object()->move(environment(me));
                set("owner", me->query("id"));
                me->receive_damage("kee", 50);
                this_object()->set("installed");
                return 1;
        }       
        if(me->query_str() > 45 ) {
                tell_object(me, HIG"你找了个隐蔽角落，奋起神力，缓缓把弓拉满，又仔细的安装上了箭头。\n"NOR);
                set("long", "一个似弓似弩的怪东西，似乎是猎人用来扑捉动物的。\n");
        } else {
                message_vision("$N用力拉弓，神弓却丝毫不动。\n", me);
                return 1;
        }
        arrow->set_amount(i-10);
        this_object()->move(environment(me));
        set("owner", me->query("id"));
        set("installed", 1);
        me->receive_damage("kee", 50);
        return 1;
} 
int do_search(){
   object me, bow;
        int i;
        
        me = this_player();
        i = me->query_skill("perception");
        if(!present("jade bow", environment(me))){
                return 0;
        }
        tell_object(me, "你仔细在这里搜索了一遍.\n");
        
        if(random(i) < 20) {
                tell_object(me, "你什么都没有找到。\n");
        } else {
                tell_object(me, "你在一个隐蔽的角落找到一个截玉伏弩。\n");
                this_object()->move(me);
        }
        return 1;
} 
int shoot(object me){
        int kee, i, j;
        string *limbs, limb, output, msg;
        i = me->query_skill("perception");
        if(me->query("id") == query("owner")){
                return 0;
        }
        if(environment(me) != environment(this_object())){
                return 0;
        }
        limbs = me->query("limbs");
        message_vision("一阵阵破空之声传来。。。\n", me);
        for(j=0; j<10; j++){
                message_vision(CYN"只听耳边嗤嗤声响，一支暗箭射向$N。\n"NOR, me);
                if( random(i) < 20 ){
                        if(!random(8)) {
                                message_vision(YEL"箭头失去准头，刚好从$N身旁擦过。\n"NOR, me);
                        } else {
                                limb = limbs[random(sizeof(limbs))];
                                msg = HIR"$N躲避不及暗箭正中$N的$l。\n"NOR;
                                output = replace_string(msg, "$l", limb);
                                message_vision(output, me);
                           kee = me->query("eff_kee");
                                me->receive_wound("kee", kee/20, me);
                                COMBAT_D->report_status(me);
                        }
                } else {
                        message_vision("$N耳闻破风之声，一个转身及时避开。\n", me);
                }
        } 
        delete("installed");
        set("long", "一个似弓似弩的怪东西，似乎是猎人用来扑捉动物的。
也许可以安装（ｉｎｓｔａｌｌ）试试。\n");
        return 1;
}      
