 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");
        if((int)me->query("force")< 100 )
                return notify_fail("�������������\n"); 
        write( HIW "��ȫ�����ɣ���������ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + 
"�������˹����ˣ�����һ���һ��ף����ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n" 
NOR,
                environment(me), me); 
        me->receive_curing("kee", 20 + (int)me->query_skill("bibo-force",1)*3);
        me->add("force", -50);
        me->set("force_factor", 0);
        return 1;
}
     