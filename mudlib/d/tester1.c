 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("新手导师", ({ "man"}) );
        set("gender", "男性" );
        set("age", 65);
        set("per", 27);
        set("attitude", "peaceful");
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("long",     "新手到到到到打算\n");
        set("combat_exp", 999999);
        setup();
}
private void get_encoding(string arg, object ob);
void init()
{
        object me;
        me = this_player();
        ::init(); 
		write("黄衣人说道：你好，欢迎来到风云的世界，这里是新手训练室，\n");
        write("你将会在新手导师的提示下逐步了解如何操作这个游戏。\n");
        write("风云是一个文字MUD游戏，所有的动作、吃喝、行走、战斗、学习、聊天、都是由你输入指令去完成的。\n");
        write("下面由我教你怎么去“看”这个未知的世界。\n");
        write("“看”使用指令look，可以缩写为“l”。当你输入“look”或者缩写“l”的时候，");
		write("你可以“看”到你所在的场景的信息。\n");
        write("下面，你尝试输入指令：“look”或者缩写“l”，看看你现在处在一个什么样的场景内吧。\n");
		get_encoding("", me);
} 
private void get_encoding(string arg, object ob) {
	    object me, room;
		me = this_player();
	    if(arg == "look man" || arg == "l man") {
                write("输入正确了。\n");
				room = load_object("/d/fy/ecloud1");
                this_player()->move(room);
        } 
		else {
                write("请输入指令：look man\n");
                input_to((: get_encoding :), ob);
                return;
        }
}
//int ask_him(object me)
//{
//        if(environment(me) == environment())
//			   tell_object(me,name()+"喝道：你是不是萧十一郎的朋友？（answer yes/no）\n");
//               return 1;
//}

//int do_answer(string arg)
//{
//if(!arg || arg != "yes"){
//command("say 好！既然你是他的朋友，我就不妨多杀一个！\n");
//command("say 输入正确了。\n");
//}
//else {
//	command("say 输入不正确\n");
//	command("say 重新输入。look\n");
//};
//}
