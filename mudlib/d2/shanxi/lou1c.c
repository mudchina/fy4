inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "�赶ɱ��"); 
    set("long", @long
�������ⵡ���������ɡ�������֮�ڣ�������֮�ԡ�̫����
̫�������в���ֵУ������������������������δ��������ɱ
�У����Գ������ԡ������ݡ�
long 
    ); 
    set("exits", ([ 
    	"east" : __DIR__"lou1d", 
    	"north" : __DIR__"lou1b",
    	//"west" : __DIR__"midao",
    	//"out" : __DIR__"alou4",
        ])); 
                set("objects", ([
                //__DIR__"npc/huoxiu": 1,
                
        ]));
        
        set("no_magic",1);
        
        set("indoors","shanxi"); 
set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",101);
        setup(); 
                //create_door("out", "ʯ��", "enter", DOOR_CLOSED); 

} 