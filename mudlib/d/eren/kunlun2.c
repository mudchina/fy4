 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "������ʲ��");
        set("long", @LONG
���ٺӹ����ĺ�ˮ�������µĲ����·��Ź⡣�������Σ���ˮ˫�֣������һ
֧����������ʲ�ӣ�ˮ�������Ƹ�������վ��������˱��ڵ��˻�������������ʲ
���������ߣ������������������������������������ش�˵������ɽ����
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"kunlun3",
                "east" : __DIR__"kunlun1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1000);
        set("coor/y",140);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      