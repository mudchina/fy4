 //XXDER@fy3
inherit ROOM;
void create()
{
        set("short", "卧室");
        set("long", @LONG
房间不大，也没有什么摆设，只是墙上长剑惹人注目，住在这里的是
莫不屈，金不畏，公孙不智，胡不愁，其中公孙不智聪明绝顶，智计天下
无双，胡愁行事超脱，出人意表，更是一时之选，所以屋虽不大，却也被?
这两人布置的井井有条。
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road2",
])); 
   set("objects", ([
      __DIR__"npc/jin": 1,
   ]) );
        set("coor/x",150);
        set("coor/y",2010);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
