 // earth-warp.c
#include <ansi.h>
#include <command.h>
#include <login.h> 
inherit F_CLEAN_UP; 
int scribe(object me, object sheet, string arg)
{
         string err;
         int extra;
         
        if(me->query("class")!="taoist")
                return notify_fail("只有三清宫弟子才可以画符。\n"); 
        if(me->query("have_mission"))
                return notify_fail("你有组织任务在身，不能画符。\n");  
        if(me->query("mission_over"))
                return notify_fail("你只能用修仙术飞到组织那里领取奖励。\n");        
        if((int)me->query_skill("scratmancy",1) < 58)
                return notify_fail("你的符之术不够高！\n"); 
        if( sheet->name() != "桃符纸" )
                return notify_fail("遁天符要画在桃符纸上！\n");
        
        if( (int)me->query("mana") < 100 ) 
                return notify_fail("你的法力不够了！\n");
        write("你要在符上写什么？");
        input_to( (: call_other, __FILE__, "select_target", me,sheet :)); 
        return 1;
} 
void select_target(object me, object sheet,string name)
{
        object ob,newsheet;
        string fplace;
        
        if( !name || name=="" ) {
                write("中止写符。\n");
                return;
        } 
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/item/magic_seal");
        newsheet->set_name(YEL "遁天符" NOR, 
                ({ "drift-warp sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->set("burn_person",me);
        newsheet->move(me);
        me->add("mana", -50);
        me->save();
        switch(name)    {
                case "taoguan":
                case "三清道观":
                        fplace="三清道观";
                        break;
                case "guanwai":
                case "大昭寺":
                        fplace="大昭寺";
                        break;
                case "chenghuang":
                case "城隍古庙":
                        fplace="城隍古庙";
                        break;
                case "songgu":
                case "松谷庵":
                        fplace="松谷庵";
                        break;
                case "daimiao":
                case "岱庙":
                        fplace="岱庙";
                        break;
                case "bat":
                case "蝙蝠岛":
                        fplace="蝙蝠岛";
                        break;
                case "xinjiang":
                case "新疆":
                	fplace="新疆";
                	break;
                case "baiyun":
                case "白云岛":
                	fplace="白云岛";
                	break;
        }
        
        if(stringp(fplace))
        {
                newsheet->set("long","一张道家的遁天符，上面用篆文写着"+fplace+"几个字。\n");
                newsheet->set("flying_place",fplace);
        }
        else newsheet->set("long","一张道家的遁天符。\n");
        message_vision("$N写了一道遁天符。\n" NOR, me);
                
        return ;
} 
int do_warp(object sheet)
{
        object env, me;
        string fplace;
        me=this_player();
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty"))
                return notify_fail("此地不能使用遁天符。\n");  
        me->start_busy(2+random(2));
        fplace=(string)sheet->query("flying_place");
        env = environment(me);
        message("vision",me->name()+WHT"脚踏天罡步，凝神祭起一张遁天符。 \n"NOR, env,me);
        message("vision",YEL "平地涌起一阵迷茫的烟雾，"+me->name()+YEL"的身影隐没在烟雾中... \n"NOR,env,me);
        if(sheet->query("burn_person")==this_player())
                call_out("move_him",1+random(4),this_player(),fplace);
        else
                message_vision("结果什么都没有发生。\n",this_player());
        return 1;
}
int move_him(object me,string fplace)
{
        string place;           
        message("vision", "WHT 烟雾慢慢散去，$N已经消失得无影无踪。  \n"NOR
                ,me,({me}));
        message("vision",
                MAG "周围的景色如飞般向后掠去，你不禁有点头晕目眩。 \n"
YEL "你感到周围的景色终于凝顿下来，你已经来到了另一个地方。 \n"NOR, me);
        switch(fplace) {
                case "三清道观":
                        place="/d/taoguan/da_dian";
                        break;
                case "大昭寺":
                        place="/d/guanwai/templeyard";
                        break;
                case "松谷庵":
                        place="/d/huangshan/songgu";
                        break;
                case "岱庙":
                        place="/d/daimiao/tongting";
                        break;
                case "城隍古庙":
                        place="/d/fy/hiretem";
                   	break;
                case "蝙蝠岛":
                        place="/d/bat/room2";
                        break;
                case "新疆":
                	place="/d/xinjiang/qianfo";
                	break;
                case "白云岛":
                	place="/d/baiyun/baiyunentrance";
                	break;
                	
        }
        if(!stringp(place))
                place="/d/taoguan/da_dian";
        me->move(place);
        message("vision",YEL "你周围忽然起了一阵怪风，"+me->name()+"的身影似乎从风中凝结般出现在眼前。 \n"NOR,
                place, ({me}) );
      
        return 1;
        
}
   
