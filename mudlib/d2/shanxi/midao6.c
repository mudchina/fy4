#include <ansi.h> 
inherit ROOM;
void create() 
{ 
    set("short", "�ܵ�"); 
    set("long", @long
�����ܵ�����˷�����·��Ҳ��֪����������·����ģ�����·�Ǽٵģ�
�ܵ���Щ�������ƺ�����ɱ����
long 
    ); 
    set("exits", ([ 
    	"east" : __DIR__"midao7", 
    	"south" : __DIR__"midao2",
    	"west" : __DIR__"midao",
    	"north" : __DIR__"midao3",
        ])); 
    set("indoors","shanxi"); 
set("coor/x",-470);
        set("coor/y",-260);
        set("coor/z",97);
        setup(); 
} 
int valid_leave(object obj, string dir){
        int skills,i,damage;
        string  *dirc = ({ "��", "��", "��", "��" });
        skills=obj->query_skill("perception",1);
        
        if(dir == "west" || dir == "south" || dir == "east" || dir == "north"){
        	if (random(10)>=5) {
            		message_vision(HIR"$N����������ǰ�У�ͻȻ����ಡ��������м���������"+dirc[random(4)]+"��ǽ�ڷ����������\n"NOR, obj); 
            		if( random(skills) < 50 ){
            			message_vision(HIR"�������۶�����$N���������������˸����ţ���\n"NOR,obj);
            			i = (int)obj->query("eff_kee");
        			damage = i/20;
        			obj->set("eff_kee",(int) i - damage );
        			i =  (int)obj->query("kee");
        			obj->set("kee",(int) i - damage);
        			return 1;
            		}
  			else{
  				message_vision(WHT"$N���������һ���粽����˷�������İ�����\n"NOR,obj);
  				return 1;
  			}
                }
        }       
        return 1;
}