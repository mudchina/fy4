 inherit NPC;
#include <ansi.h>
int proceed(); 
void create()
{
        set_name("百里长青", ({ "baili", "baili changqing"}) );
        set("nickname", HIC "辽东大侠"NOR);
        set("gender", "男性" );
        set("age", 54);
        set("per", 25);
        set("int", 28);
        set("attitude","friendly");
        
        set("force_factor", 30);
        set("max_force", 1000);
        set("force", 1000);
        set("attitude", "peaceful");
        
        set("combat_exp", 2800000);
        set("score", 90000);
        
        set_skill("perception",150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("dragonstrike", 180);
        set_skill("cloudsforce", 200);
        set_skill("tie-steps", 150);
                
        map_skill("unarmed", "draginstrike");
        map_skill("force", "cloudsforce");
        map_skill("dodge", "tie-steps");
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/kee",30);
                }
   
        set("inquiry",  ([
                        "gui dong jing" : (: proceed :),
                        "gui dongjing" :(: proceed :),
                        "guidongjing":(: proceed :),
                        "归东景":(: proceed :),
                ]) );
        set("chat_chance",1);
        set("chat_msg",({
                "百里长青对邓定候道：“我本不想出手杀你，但是......\n\n出招吧......”\n",       
        }));    
        set("long",
                "此人身材高大魁伟，双目精光爆射。乃是威名远播的长青镖局的主人。"
                );
        setup();
    carry_object("/obj/armor/cloth")->wear();
} 
void init()
{
        object me;
        ::init();
        me = this_player();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
        if(!NATURE_D->is_day_time() && me && environment(me) == environment() && !me->is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 2, me);
        }
} 
int greeting(object me)
{
        object room;
        if(!me || environment(me) != environment() || me->is_fighting()) return 1;
        if( userp(me) )
        {
                if( !me->query("m_success/镖局内奸") )
                {
                        command("say 这位" + RANK_D->query_respect(me)+"，老夫正要与这个奸细，但又是我最好的朋友决一死战......\n也好，就请你来做个见证吧。\n");
                } else {
                        command("say 这位" +RANK_D->query_respect(me)+"，这里将有一场恶战，地方狭小，你还是去安全的地方吧。\n");
                        message_vision("$N大袖一挥，一股柔和的劲风将$n从塔顶送出，缓缓落下。\n",this_object(),me);
                   room = find_object("/d/bawang/undertower2");
                        if(!room) room=load_object("/d/bawang/undertower2");
                        me->move(room);
                        message("vision", me->name()+"从塔上面缓缓落了下来，\n", environment(me), me);
                }
        }
        return 1;
} 
int proceed()
{
        object me;
        object room;
        object note;
        me = this_player();
        if(NATURE_D->is_day_time()){
                return 1;
        }
        if (me->is_fighting()) return 1;
        command("say 这位" + RANK_D->query_respect(me)+"，怀疑这“开花五犬旗”的内奸是归东景？\n");
        command("consider");
        command("say 老夫也觉得这件事好像很蹊跷，看来我和邓兄弟都是上了
归东景这内奸的当了。他让我二人拼个两败具伤，他好坐收鱼利。\n\n\n");
        if(!me->query("m_success/镖局内奸") ){
                me->set("m_success/镖局内奸",1);
                me->add("score",100);
        }
        message_vision(HIR"从五层突然传来一阵冷笑：“让你多嘴，死去吧！”\n"NOR, me);
        message_vision(HIW"一片银光闪闪的暗器，以无与伦比的速度向$N射来！
$N已经无法躲避，只好闭目等死。。。\n"NOR, me);
        message_vision(HIR"\n只听见$N一声爆喝：“快走！”\n$n只觉得一股排山倒海般的掌力当胸击至。“碰！”$n被击得破壁而出，
不由得鲜血狂喷，一下子晕了过去。\n"NOR,this_object(),me);
        message_vision("迷迷糊糊中，$N身体象一片树叶般向塔下飘落，似乎又有一根绳索套
住了$N的腰。。。\n",me);
        room = find_object("/d/bawang/undertower2");
        if(!room) room=load_object("/d/bawang/undertower2");
        me->unconcious();
        me->move(room);
        message("vision", "断塔顶突然传来一声大喝，“嘭！”的一声，只见"+me->name()+"的身体从塔顶破壁而出，
随即一根绳索从塔顶飞出，套住了"+me->name()+"的腰，使"+me->name()+"的身体缓缓地落在你身边的草地上。\n", environment(me), me);
        message("vision", "断塔中不断传来“嘭！啪！”的巨响夹杂着怒喝和低叱，震得断塔摇摇欲坠。
丛五层到二层，不断地有大块的砖石和碎木飞出。在底层，又是一声惊天
动地的巨响，断塔竟然倒塌下来。尘土飞扬中，几条黑影似乎向西南方向
飞奔而去。\n", environment(me), me);
        message("vision", "又有一人从废墟中纵身到"+me->name()+"身边，匆匆写就一张纸条，塞在"+me->name()+"手中，
随即也追向西南而去。\n", environment(me), me);
        note = new(__DIR__"obj/dingxi_note");
        if (note) note->move(me);
        return 1;
}       
