 inherit ITEM;
void create()
{
        set_name("Ѫ��", ({ "blood cloth", "bloodcloth"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long", "һ��������Ѫ���·���������Ѫд�˼�����Ŀ���ĵĴ��֣�
        ����磬������ɽ�����ң���
        
        С����
\n");
        }
        set("value", 0);
          set("skill", ([
                        "name":         "dagger",             
                        "exp_required": 50000,                          
                        "sen_cost":     50,                     
                        "difficulty":   50,                     
                        "max_skill":    50              
                        ]) );
        ::init_item();
}  