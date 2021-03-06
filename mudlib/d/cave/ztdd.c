 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "天中道东");
        set("long", @LONG
这里是个十字路口，西面的叉口以前可以直接通到天外天的中心，现在却被一
堵高墙挡住了。可是白天在这里依旧可以看到中心的园坛洞顶，从圆洞直射下来的
天光形成的圆柱。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"btdl",
                "south" : __DIR__"ntdl",
                "west" : __DIR__"zddm",
                "southeast" : __DIR__"ztddn",
        ]));
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-15);
        set("coor/z",-20);
        setup();
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "south" && !obj->query("vendetta/authority")){
                if (present("killer k", this_object()))
                {
                        another = present("killer k", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_k");
                        another->move(environment(obj));
                        message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                        return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
           }
        }       
        return 1;
}     
