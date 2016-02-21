#include <ansi.h>
#include <combat.h>
inherit ITEM; 
void create()
{
    set_name(MAG"����������"NOR, ({ "handkerchief" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("long", "һ��ԼĪ�ĳ߼����İ׶��������Ľ��϶�����һ��컨���������Σ�ÿ��
���Զ�����һ�Ŵ���ɫ��Ҷ�ӣ�ӭ��΢�磬��ס�ض�����shaking����\n");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
                }
        ::init_item();
} 
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("����������ʬ�������$N�Ļ��У�\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}

void init()
{
        if(this_player()==environment())
        add_action("do_shake","shaking");
} 
int do_shake(string arg)
{
        object ob;
        object me;
        string where; 
        if (!arg) 
                return notify_fail("�����Ե�˭��\n"); 
        if (query("used")) 
                return notify_fail(this_object()->name()+"ֻ����һ�Ρ�\n");
        me=this_player();
        
        if( environment(me)->query("no_fight") || environment(me)->query("no_magic") 
                || environment(me)->query("no_spells"))
                return notify_fail("���ⲻ��͵Ϯ��\n");
                
        ob=present(arg,environment(me));
        if (!objectp(ob) || !living(ob)) 
                return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
   
        if (ob!=me)
                message_vision(GRN"\n$N��������һ���$n���˶����е�"+name()+GRN"��һ˿�������޵���������������\n"NOR,me,ob);
        else {
                message("vision",GRN"\n"+me->name()+GRN"��������һ����Լ����˶����е�"+name()+GRN"��һ˿�������޵���������������\n"NOR,environment(me),me);
                tell_object(me,GRN"\n����������һ����Լ����˶����е�"+name()+GRN"��һ˿�������޵���������������\n");
        }
        
        where=file_name(environment(ob));
        if (!userp(ob) && where[0..6]=="/d/cave") {
                 message_vision(YEL"$N��Ц��:�����С��Ҳ�������������������Ū,��ү���ö��ˣ�\n"NOR,ob);
                 message_vision(HIR"\n$N����$n���һ���������Ķ�������֪�߳�...\n"NOR,ob,me);
                 ob->kill_ob(me);
        } else {          
                if (random( me->query("cps")+me->query("int")) > random (ob->query("cps"))+random(ob->query("int"))
                && random(me->query("combat_exp")*4)> ob->query("combat_exp")|| ob==me)         {
                        if (ob!=me)
                                message_vision(MAG "\n\n$Nֻ������ǰ��ʰ�쵣�����΢����ת�˼���Ȧ�ӣ����ڵ��ϡ���\n"NOR,ob);
                        else {
                                message("vision",MAG "\n\n"+me->name()+MAG"ֻ������ǰ��ʰ�쵣�����΢����ת�˼���Ȧ�ӣ����ڵ��ϡ���\n"NOR,environment(me),me);
                                tell_object(me,MAG "\n\n��ֻ������ǰ��ʰ�쵣�����΢����ת�˼���Ȧ�ӣ����ڵ��ϡ���\n"NOR);
                        }
                        ob->unconcious();
                }else   {
                        message_vision(CYN"\n\n$N��æ�����ڱǣ���ס��������ȥ������������\n"NOR,ob);
                        message_vision(HIR"\n$N����$n���һ���������Ķ�������֪�߳ܡ���\n"NOR,ob,me);
                        ob->kill_ob(me);
                }
        }
        set("used",1);
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
}   