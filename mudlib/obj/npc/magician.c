 // TIE@FY3
inherit NPC;
#include <ansi.h>
#define COST 100
void create()
{
        set_name("黑袍人", ({ "blackfigure" }) );
        set("gender", "男性" );
        set("age", 65);
        set("title", HIG "无形" NOR);
        set("str", 56);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
        set("intellgent",1);
        set("attitude", "peaceful");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("arrive_msg","身形一晃，突然出现在你的面前");
        set("leave_msg","象个幽灵似的消失不见了");
        set("long",     "你根本看不清他的真面目\n");  
        set("combat_exp", 9999999); 
        set_skill("unarmed", 220);
        setup();
} 
void init()
{       if(interactive(this_player()))
        add_action("do_vigor","vigor");
} 
int do_vigor(string arg)
{
   object me,ob;
        string name, attr;
        me = this_player();
        if( !arg)
        {
        command("say 你要我帮你什么？\n");
        return 1;
        } 
        if(sscanf(arg,"%s %s",name,attr) != 2)
        {
        command("say 你要我帮你什么？\n");
        return 1;
        }
        if( !objectp(ob = present(name, me)) )
        {
        command("say 你要我帮你什么？\n");
        return 1;
        }
        if(me->is_busy())
        {
        command("say 你要我帮你什么？\n");
        return 1;
        }
        if( ob->query("equipped") )
        {
        command("say 你要我帮你什么？\n");
        return 1;
        }
        if( me->query("score") < COST)
        {
        command("say 你要我帮你什么？\n");
        return 1;
        }
        switch(attr) {
        case "才智" :
        case "caizhi" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/intelligence",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/intelligence",1);
                break;
        case "体质" :
        case "tizhi" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/constitution",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/constitution",1);
                break;
        case "灵性" :
        case "lingxing" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/spirituality",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/spirituality",1);
                break;
        case "魅力" :
        case "meili" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/personality",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/personality",1);
                break;
        case "勇气" :
        case "yongqi" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/courage",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/courage",1);
                break;
        case "力量" :
        case "liliang" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/strength",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/strength",1);
                break;
        case "耐力" :
        case "naili" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/durability",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/durability",1);
                break;
        case "韧性" :
        case "renxing" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/flexibility",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/flexibility",1);
                break;
        case "速度" :
        case "sudu" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/agility",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/agility",1);
                break;
        case "气量" :
        case "qiliang" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/tolerance",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/tolerance",1);
                break;
        case "运气" :
        case "yunqi" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/karma",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/karma",1);
                break;
        case "定力" :
        case "dingli" :
                if(ob->query("armor_prop") ) ob->add("armor_prop/composure",1);
                if(ob->query("weapon_prop")) ob->add("weapon_prop/composure",1);
                break;
        default:
                        command("say 你要我帮你什么？\n");
                        return 1;
        }
//okey successfully, save and let player know
                ob->save();
                me->add("score",-COST);
                command("say 好的，好自为之吧！\n");
                return 1;
} 
