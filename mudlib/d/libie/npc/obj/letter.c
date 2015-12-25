#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("给蓝一尘的信", ({ "letter", "信"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("value", 0);
                                set("long",
"这是封浸满汗水和血水的牛皮信，以火漆封口。似乎可以撕开(tear)，上书：
      恭呈 蓝一尘 蓝大侠启"NOR);
        }
        ::init_item();
} 
void init()
{
  if(this_player()==environment()){
        add_action("do_tear","tear"); 
        }
} 
int do_tear(string arg)
{
        object          me, ob;
        if(  arg != "letter" )
                return 0;
        me = this_player();
        ob = this_object();
        message_vision("$N将$n的封口撕开，取出了其中的信笺\n", me, ob);
        set_name("被撕开的信", ({ "letter", "信"}) );
        set("long","一封已经开了封的信封，里面的信笺上写着：\n
        “蓝大侠 启
    梅林竹溪一战，伤大侠一肢，铮以为报得父仇；后磨刀老人告知实情，愧无可当，侠
之大义，高山仰止。铮此去击杀大贼狄青麟。若成，必断臂以报。”\n");
        remove_action("do_tear","tear");
        if(ob->query("送信人")==me)
        {
                me->set("marks/离别钩","失败");
           me->add("score",-2000);
        }
        return 1;
}      
