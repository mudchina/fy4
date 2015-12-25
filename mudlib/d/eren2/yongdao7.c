 inherit ROOM;
void create()
{
        set("short", "石桥");
        set("long", @LONG
转过弯是一座石桥，横跨在地下河上，河水很绿，很黑，泛出死人般的颜色。
过了桥后，甬路一分为三，中间一条黑漆漆的没有一丝灯火，似乎已被废弃，右
边通向几间破旧的小石窟，左边的路面竟然是用彩石铺成，灯光下映出妖异的光芒。
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"yard1",
                "north" : __DIR__"jailroad1",
                "northwest" : __DIR__"court1",
                "southup" : __DIR__"yongdao5",
        ]));
        set("item_desc", ([
                "河水": "这是一条地下的暗河，离桥面约有三丈，望下去黑漆漆的，隐隐有些绿光闪动。\n",
                "river": "这是一条地下的暗河，离桥面约有三丈，望下去黑漆漆的，隐隐有些绿光闪动。\n",
                
        ]) );
        set("objects", ([
                __DIR__"npc/guardb" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
