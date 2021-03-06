 // Room: foodroom.c --- by MapMaker
inherit ROOM;
void create()
{
        set("short", "谷仓");
        set("long", @LONG
这里是一个陈旧的谷仓，毛土坯做成的砖墙已渐渐剥落，一盏油灯挂在墙上，
借着昏黄的灯光你可以看清四周的景物。谷仓虽旧却还干净，地上堆放着几十个麻
包，靠墙架子上排放着一列箩筐。
LONG); 
        //{{ --- by MapMaker
        set("exits",([
                "east":__DIR__"magicroom",
                "west":__DIR__"flatfloor",
                "south":__DIR__"weapon_array",
        ]) );
        set("objects", ([
                __DIR__"obj/basket": 1,
                __DIR__"obj/sack" : 1,
        ]));
        //}}
        set("indoors", "yinghe");
        setup(); 
} 
void reset()
{
    object *inv, item1, item2, basket, sack;
    string ganguo;
    string *order = ({"zao", "lizi", "guiyuan", "baihe", "guihua"});
        ::reset();
    basket = present("basket", this_object());
    inv = all_inventory(basket);
        ganguo = order[random(5)];
        item1 = new(__DIR__"obj/"+ganguo);
        ganguo = order[random(5)];
        item2 = new(__DIR__"obj/"+ganguo);
    if( !sizeof(inv)) {
                if(objectp(item1)){
                item1->move(basket);
                }
        if(objectp(item2)){
                    item2->move(basket);
        }
    }
        sack = present("sack", this_object());
        inv = all_inventory(sack);
        if(!sizeof(inv)){
                item1 = new(__DIR__"obj/bean");
                if(objectp(item1)){
                        item1->move(sack);
                }
                item2 = new(__DIR__"obj/bean");
                if(objectp(item2)){
                        item2->move(sack);
                }
        } 
}   
