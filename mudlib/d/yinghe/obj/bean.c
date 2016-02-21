 inherit ITEM;
void create(){
        string *order=({"ºì¶¹", "ÂÌ¶¹", "»Æ¶¹", "ºÚ¶¹", "»¨¶¹", "ÔÓ¶¹"});
        set_name(order[random(6)], ({"bean", "dou zi" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Ð©¶¹×Ó¡£\n");
                set("unit", "Ð©");
                set("value", 10);
        }
    ::init_item();
}
