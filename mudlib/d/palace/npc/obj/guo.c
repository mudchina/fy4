 inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("��ݼ���ظ�" , ({ "potion", "magic potion" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", WHT
      "����һ�������湦Ч���ϸ࣮\n"
      "���������������ļ��ޣ�\n"NOR); 
                set("unit", "��");
                set("value", 20000);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");
        }
        ::init_item();
}
int finish_eat()
{
        object me;
        int max_gin, max_kee, max_sen;
        me = this_player();
        max_gin = (int) me->query("max_gin");
        max_kee = (int) me->query("max_kee");
        max_sen = (int) me->query("max_sen");
        message_vision( HIR "$N��ȫ��ӳ��һ���⣡��\n"NOR, me);
        max_gin = max_gin * 11/10;
        max_kee = max_kee * 11/10;
        max_sen = max_sen * 11/10;
        switch(random(3)){
                case 0:
                        me->set("max_gin", max_gin);
                        break;
                case 1:
                        me->set("max_kee", max_kee);
                        break;
           case 2:
                        me->set("max_sen", max_sen);
                        break;
                        }
        destruct(this_object());
        return 1;
}   