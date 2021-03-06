 // TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
string *skill_level_desc = ({
        BLU "不堪一击" NOR,
        BLU "毫不足虑" NOR,
        BLU "不足挂齿" NOR,
        BLU "初学乍练" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "普普通通" NOR,
        HIB "平平淡淡" NOR,
        HIB "平淡无奇" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIB "略有小成" NOR,
        HIB "已有小成" NOR,
        HIB "驾轻就熟" NOR,
        CYN "心领神会" NOR,
        CYN "了然於胸" NOR,
        CYN "略有大成" NOR,
        CYN "已有大成" NOR,
        CYN "豁然贯通" NOR,
        CYN "出类拔萃" NOR,
        CYN "无可匹敌" NOR,
        CYN "技冠群雄" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        CYN "傲视群雄" NOR,
        HIC "登峰造极" NOR,
        HIC "所向披靡" NOR,
        HIC "一代宗师" NOR,
        HIC "神功盖世" NOR,
        HIC "举世无双" NOR,
        HIC "惊世骇俗" NOR,
        HIC "震古铄今" NOR,
        HIC "深藏不露" NOR,
        HIR "深不可测" NOR
});
string *knowledge_level_desc = ({
        BLU "不堪一击" NOR,
        BLU "毫不足虑" NOR,
        BLU "不足挂齿" NOR,
        BLU "初学乍练" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "普普通通" NOR,
        HIB "平平淡淡" NOR,
        HIB "平淡无奇" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIB "略有小成" NOR,
        HIB "已有小成" NOR,
        HIB "驾轻就熟" NOR,
        CYN "心领神会" NOR,
        CYN "了然於胸" NOR,
        CYN "略有大成" NOR,
        CYN "已有大成" NOR,
        CYN "豁然贯通" NOR,
        CYN "出类拔萃" NOR,
        CYN "无可匹敌" NOR,
        CYN "技冠群雄" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        CYN "傲视群雄" NOR,
        HIC "登峰造极" NOR,
        HIC "所向披靡" NOR,
        HIC "一代宗师" NOR,
        HIC "神功盖世" NOR,
        HIC "举世无双" NOR,
        HIC "惊世骇俗" NOR,
        HIC "震古铄今" NOR,
        HIC "深藏不露" NOR,
        HIR "深不可测" NOR
});
string skill_level(string, int);
int main(object me, string arg)
{
   object ob, man, *all;
        mapping fam, skl, lrn, map;
        string *sname, *mapped;
        int sp, dp;
        int i, cost;
        seteuid(getuid());
        all = all_inventory(environment(me));
        for(i=0; i<sizeof(all); i++) {
                if( living(all[i]) && !userp(all[i]) ) man = all[i];
        } 
        if (me->query("class")!="beggar")
                return notify_fail("只有丐帮弟子才能打探别人的技能！\n"); 
        if ( !objectp(man) )
                return notify_fail("周围没人能帮你去发现别人的技能！\n");
        if ( !arg )
                return notify_fail("你要打听谁的技能？\n");
        ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要打听谁的技能？\n"); 
        if ( ob == me )
                return notify_fail("请输入指令ｓｋｉｌｌｓ\n");
        if ( present(ob, environment(me)) )
                return notify_fail("你要打听的人就在这儿！\n");
        cost = me->query("max_gin")/(me->query_skill("begging",1)/10 + 1); 
        if ( me->query("gin") <= cost )
                return notify_fail("现在你太累了，无法去打听别人的技能。\n"); 
        tell_object(me, "你决定向" + man->name() + "打听关于" + ob->name() + "的武功情况。\n\n");
        message("vision", "只见" + me->name() + "交头接耳地跟" + man->name() + "说着话，好象在打听些什么。\n\n", 
                environment(me), ({ me, man }) ); 
        sp = me->query_skill("begging")*10 + me->query("kar")*5 + me->query("gin") + man->query("gin");
        dp = ob->query("kar")*10 + ob->query("gin")*3;
        
        if ( random(sp) < random(dp) )
                return notify_fail( man->name() + "摇了摇头，说道：这事我可不清楚，"
                        + RANK_D->query_respect(me) + "还是去向别人打听一下吧！\n"); 
        me->receive_damage("gin", cost ); 
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( man->name() + "告诉你： " + ob->name() + "什么都不会！\n");
                return 1;
   }
        write( man->name() + "告诉你： " + ob->name() +"目前所学过的技能：\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({}); 
        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        i = random(sizeof(skl)); 
        printf("%s%s%-40s" NOR " - %-10s \n", 
                (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                (member_array(sname[i], mapped)==-1? "  ": "□"),
                to_chinese(sname[i]) + " (" + sname[i] + ")",
                skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
        ); 
        write("\n");
        return 1;
} 
string skill_level(string type, int level)
{
        int grade; 
        grade = level / 10; 
        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
} 
int help(object me)
{
        write(@HELP
指令格式 : inquire <某人> 
这个指令可以让你打听别人所学过的技能。  
此命令为丐帮弟子专用，并需学习打听之术。 
HELP
    );
    return 1;
}   
