 inherit ITEM;
void create()
{
        set_name("ϸ�ɲ豭", ({ "tea cup", "�豭"}) );
        set_weight(40);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "ֻ");
            set("long", "һֻϸ�ɲ豭��\n");
            set("value", 100);
        }
        ::init_item();  
} 
