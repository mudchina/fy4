 // Room: earthhall.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "�յ�"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "south":__DIR__"woodroad",
        "north":__DIR__"slop",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    