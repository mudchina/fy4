 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "甘露台");
        set("long", @LONG
据说跋陀译经，天降甘露，所以名为甘露台，台顶两株古柏，台下
几棵古树，把甘露台团团包住。甘露台中成凹形，汇聚了一洼清水，且
终年不干枯。
LONG
        );
        set("exits", ([ 
        "eastdown" : __DIR__"tayuan",   
        ]));
        set("objects", ([
                __DIR__"npc/master_21" : 1,
       ]) );
        set("resource/water", 1);
        set("liquid/container", "甘露台");
        set("outdoors", "shaolin");
        set("coor/x",-230);
        set("coor/y",260);
        set("coor/z",60);
        setup();
        create_door("eastdown", "木门", "westup", DOOR_CLOSED);
}        
