 inherit ROOM;
void create()
{
        set("short", "西天街");
        set("long", @LONG
一条灯火通明的长廊，似乎原先本是繁华的街道，两旁是一些寺院民宅，后
来快活王占据这古楼兰的地下王国后，便将大大小小的民宅修葺改建，以供手下
酒色财气四使、急风三十六骑以及众多嫔妃佳人和一干下人居住。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"weststrt2",
                "west" : __DIR__"westtower",
        ]));
        set("indoors", "loulan"); 
        set("coor/x",-1030);
        set("coor/y",200);
        set("coor/z",-100);
        setup();
}
