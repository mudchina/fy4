 // Room: /city/milin.c
inherit ROOM; 
void create()
{
        set("short", "黑暗山洞");
        set("long", @LONG
这是一个阴森可怖而且黯淡无光的山洞，一走进来，你倒吸了一口凉气，脑中
一阵晕眩，就什么也想不起来了。
LONG
        );
        set("exits", ([
                "east" : __FILE__,
                "west" : __FILE__,
        "north" : __FILE__,
        "south" : __DIR__"d5",
        ]));
        set("coor/x",3270);
        set("coor/y",50);
        set("coor/z",-30);
        setup();
        replace_program(ROOM);
}  
