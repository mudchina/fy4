// TIE@FY3
//modify by karry@fy4
#include <ansi.h>
inherit NPC;
void pay_him(object who, int amount);
void check_pointer();
int give_card();
int do_bet2(string arg, object me);
int can_end_round();
string showdice(int num);
void find_next();
void setup_card();
void end_the_round();
void create()
{
	set_name( "Àä¶¬Ã·", ({ "dong mei", "leng dongmei" }) );
	set("long", "ÕâÊÇÖìÉ°°ïÕÆÃÅµÜ×ÓÀäÇï»êµÄÃÃÃÃ¡£\n");
	set("attitude", "friendly");
        set("force_factor", 30);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
	set("cards", ({}));
	set("my_percentage",3);
        set("gin", 3000);
        set("kee", 99999);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);
	set("age", 33);
        set("gender", "Å®ĞÔ" );
	set("age",18);

	set("str", 35);
	set("cor", 30);
	set("cps", 25);
	set("per",5);
	set("lower_limit",1);
	set("too_late",0);
	set("whose_turn",0);
	set("last_turn",0);
	set("counter",0);
	set("max_force",400000);
	set("force_factor",250);
	set_skill("throwing",200);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set("combat_exp", 50000000);
	setup();
        carry_object(__DIR__"obj/nupao")->wear();
	carry_object(__DIR__"obj/gupai")->wield();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_take", "take");
	add_action("do_bet", "bet");
	add_action("do_leave","leave");
	add_action("do_table","table");
	add_action("do_fold", "fold");
	add_action("do_cards","cards");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "Àä¶¬Ã·Ğ¦ßäßäµØÏòÄãÅ×ÁË¸öÃÄËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob)
                                + "£¬¹ıÀ´£¬¹ıÀ´£¬æªÉíÅãÄú¶Ä¼¸ÊÖ£¡\n");
                        break;
                case 1:
                        say( "Àä¶¬Ã·½«Ì¨ÉÏµÄ÷½ÅÆÇĞÁËÇĞµÀ£º" + RANK_D->query_respect(ob)
                                + "£¬¿´Äú½ñÌìÒ»¶¨»áÄÃµ½Ìì¶Ô¶ù£¡\n");
                        break;
                case 2:
                        say( "Àä¶¬Ã·ËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob)
                                + "£¬±ğÅÂ£¡½øÀ´£¡ ²»»áÎÒ¿ÉÒÔ½ÌÄã£¡\n");
                        break;
        }



	return;

}



 
string *dice = ({
"0",
"      B"+
"      B"+
"      B"+
"[31m  ¡Ñ  [37mB"+
"      B"+
"      B"+
"      B",

"[31m  ¡Ñ  [37mB"+
"      B"+
"      B"+
"      B"+
"      B"+
"      B"+
"[31m  ¡Ñ  [37mB",

"    ¡ÑB"+
"      B"+
"      B"+
"[31m  ¡Ñ  [37mB"+
"      B"+
"      B"+
"¡Ñ    B",

"      B"+
"¡Ñ  ¡ÑB"+
"      B"+
"      B"+
"      B"+
"¡Ñ  ¡ÑB"+
"      B",

"[31m    ¡Ñ[37mB"+
"[31m  ¡Ñ  [37mB"+
"[31m¡Ñ    [37mB"+
"      B"+
"      B"+
"¡Ñ  ¡ÑB"+
"      B",

"¡Ñ  ¡ÑB"+
"      B"+
"      B"+
"¡Ñ  ¡ÑB"+
"      B"+
"      B"+
"¡Ñ  ¡ÑB",

"[31m    ¡Ñ[37mB"+
"[31m  ¡Ñ  [37mB"+
"[31m¡Ñ    [37mB"+
"      B"+
"¡Ñ  ¡ÑB"+
"      B"+
"¡Ñ  ¡ÑB",

"¡Ñ  ¡ÑB"+
"      B"+
"¡Ñ  ¡ÑB"+
"      B"+
"¡Ñ  ¡ÑB"+
"      B"+
"¡Ñ  ¡ÑB",

"¡Ñ  ¡ÑB"+
"      B"+
"¡Ñ  ¡ÑB"+
"[31m  ¡Ñ  [37mB"+
"¡Ñ  ¡ÑB"+
"      B"+
"¡Ñ  ¡ÑB",

"¡Ñ  ¡ÑB"+
"[31m  ¡Ñ  [37mB"+
"¡Ñ  ¡ÑB"+
"      B"+
"¡Ñ  ¡ÑB"+
"[31m  ¡Ñ  [37mB"+
"¡Ñ  ¡ÑB",

"¡Ñ  ¡ÑB"+
"[31m  ¡Ñ  [37mB"+
"¡Ñ  ¡ÑB"+
"      B"+
"¡Ñ  ¡ÑB"+
"¡Ñ  ¡ÑB"+
"¡Ñ  ¡ÑB",

"¡Ñ  ¡ÑB"+
"¡Ñ  ¡ÑB"+
"¡Ñ  ¡ÑB"+
"      B"+
"¡Ñ  ¡ÑB"+
"¡Ñ  ¡ÑB"+
"¡Ñ  ¡ÑB"

		});
int do_take(string arg)
{
	string location,money_type,c_loc;
	int amount,total;
	object me, money;
	me = this_player();
	if(me->is_busy())
	return notify_fail("ÄãÏÖÔÚÃ»¿Õ£¡\n");
        if(query("too_late") )
        return notify_fail("ÕâÆÌÀ´²»¼°ÁË£¬µÈÏÂÆÌ°É£®\n");
//	see if thisplayer already at a location already
	if(query("north/player") == me ||
	   query("south/player") == me ||
	   query("east/player") == me ||
	   query("west/player") == me  )
		return notify_fail("ÄãÒÑ¾­ÈëÁË¶Ä¾Ö£¡\n");
	if(!arg || sscanf(arg, "%s %d %s",location,amount,money_type) != 3)
                return notify_fail("take <×ùÎ»> <ÊıÁ¿> <»õ±ÒÖÖÀà>\n");
	switch(location) {
	case "north" : 
		c_loc = "±±Ê×";
		if(objectp(query("north/player"))) return notify_fail("±±Î»ÒÑ¾­ÓĞÈËÕ¼ÁË£¡\n");
		break;
        case "south" : 
		c_loc = "ÄÏÊ×";
                if(objectp(query("south/player"))) return notify_fail("ÄÏÎ»ÒÑ¾­ÓĞÈËÕ¼ÁË£¡\n");
                break;
        case "east" : 
		c_loc = "¶«Ê×";
                if(objectp(query("east/player"))) return notify_fail("¶«Î»ÒÑ¾­ÓĞÈËÕ¼ÁË£¡\n");
                break;
        case "west" : 
		c_loc = "Î÷Ê×";
                if(objectp(query("west/player"))) return notify_fail("Î÷Î»ÒÑ¾­ÓĞÈËÕ¼ÁË£¡\n");
                break;
	default :
		return notify_fail("ÄãÖ»¿ÉÒÔÑ¡north¡¢south¡¢east »ò west¡£\n");
	}
	if(amount <=0)
		return notify_fail("<ÊıÁ¿>×îÉÙÒ²ÒªÊÇÒ»Âğ£¡\n");
	money = present(money_type+"_money", me);
	if(!objectp(money)) return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÖÖ»õ±Ò¡£\n");
	if((int) money->query_amount() < amount)
	return notify_fail("ÄãÉíÉÏÃ»ÓĞÄÇ÷á¶à"+money->name()+"¡£\n");	
	total = money->value() / money->query_amount() * amount/100;
	if(query("lower_limit") > total)
	return notify_fail("ÕâÕÅÌ¨µÄ×îĞ¡¶Ä×¢ÊÇ"+chinese_number((int) query("lower_limit"))+"Á½Òø×Ó¡£\n");
// we think this player will be okey to take a seat at this moment, so, record all the info and take his money!
	set(location+"/player",me);
	add(location+"/money",total);
	money->add_amount(-amount);
	message_vision("$N´ÓÉíÉÏÄÃ³ö"+ chinese_number(amount)+money->query("base_unit")+
	money->name()+"·ÅÔÚ"+c_loc+"¡£\n",me);
	me->start_busy(1);
	if( find_call_out("rolldice") == -1)
//                call_out("rolldice",60);
		call_out("rolldice",30);
        if( find_call_out("rolldice") >30 && find_call_out("advertise") == -1)
                call_out("advertise",random(5)+1);

	return 1;
}

int do_leave()
{
	object me;
	string location ="nowhere";
	me = this_player();
if( query("north/player") == me )  location = "north";
if( query("south/player") == me )  location = "south";
if( query("east/player") == me )  location = "east";
if( query("west/player") == me )  location = "west";
if(location == "nowhere") return 0;
if(query("too_late"))
	return notify_fail("¶Ä¾ÖÕıÔÚ½øĞĞÖĞ£¬ÔõÃ´¿ÉÒÔÀë¿ª£¿\n");
if(query(location+"/money"))
{
pay_him(me,(int)query(location+"/money")*100);
message_vision("$N½«×À×ÓÉÏµÄ"+chinese_number(query(location+"/money"))+"Á½Òø×Ó"+
"´§Èë»³ÖĞµÀ£ººó»áÓĞÆÚ£¡\n",me);
}
else
message_vision("$NÕ¾ÆğÀ´¹°ÁË¹°ÊÖµÀ£ºÕâ´ËÔËÆø²»ºÃ£¡¶¼ÊäÁË£¡ºó»áÓĞÆÚ£¡\n",me);
delete(location);
return 1;
}
int do_table()
{
	int turn;
	string output;
	turn = query("whose_turn");
	output = sprintf(
	(turn%4==0 ? HIR:NOR)+ "%40s\n%44s\n"NOR,(query("north/player")? query("north/player")->name():"¿Õ¡¡Î»"),
	query("north/money")+"Á½Òø×Ó");
	output += "                          -------------------------\n";
	output += "                          |         "+
	(query("north/fold")? HIY:NOR)+"±±Ê×"+NOR+"          |\n";
	output += sprintf( (turn%4==1 ? HIR:NOR)+"%26s" +NOR + "|"+
	(query("west/fold")? HIY:NOR)+ "Î÷"+NOR+"                   "+
	(query("east/fold")? HIY:NOR)+"¶«" +NOR+"|" +
		(turn%4==3 ? HIR:NOR) + "%s\n" +NOR,
		(query("west/player")? query("west/player")->name():"¿Õ¡¡Î»"), 
		(query("east/player")? query("east/player")->name():"¿Õ¡¡Î»"));
	output += sprintf("                          |"+"%14dÁ½Òø×Ó" + "   |\n",(int)query("table/total"));
	output += sprintf( (turn%4==1 ? HIR:NOR)+"%26s" +NOR + "|"+
	(query("west/fold")? HIY:NOR)+ "Ê×"+NOR+"                   "+
	(query("east/fold")? HIY:NOR)+"Ê×"+NOR+"|" +
                (turn%4==3 ? HIR:NOR) + "%s\n" +NOR,
		query("west/money")+"Á½Òø×Ó",	query("east/money")+"Á½Òø×Ó");
	output += "                          |         "+
	(query("south/fold")? HIY:NOR)+"ÄÏÊ×"+NOR+"          |\n";
	output += "                          -------------------------\n";
        output += sprintf(
        (turn%4==2 ? HIR:NOR)+ "%40s\n%44s\n"NOR,(query("south/player")? query("south/player")->name():"¿Õ¡¡Î»"),
        query("south/money")+"Á½Òø×Ó");
	write(output);
	return 1;
}
void advertise()
{
        switch( random(3) ) {
                case 0:
message_vision("$NÏòÄãÃÄĞ¦µÀ£º¶à¶Ä¶àÓ®£¡ÕâÆÌÄã²»»á²»Ó®µÄ£¡\n",this_object());
                        break;
                case 1:
message_vision("$NËµµÀ£º¿ì£¬ÔÙ²»³ö¶Ä×¢¾ÍÀ´²»¼°ÁË£¡\n",this_object());
                        break;
                case 2:
message_vision("$NÂúÃæ´º·ç£¬ËÊÓÁ×Å´ó¼Ò£º¶¼Ñ¹ÉÏ£¡Ã»´í£¡\n",this_object());

                        break;
        }

        if( find_call_out("rolldice") >=30)
                call_out("advertise",random(4)+5);
return;
}

void rolldice()
{
	int num_of_head=0;
	string sen;
	string sen2;
// we have to have at least two people to gamble, right? //
	if(objectp(query("north/player"))) num_of_head++;
        if(objectp(query("south/player"))) num_of_head++;
        if(objectp(query("east/player"))) num_of_head++;
        if(objectp(query("west/player"))) num_of_head++;

	if(num_of_head < 2) {
	call_out("rolldice",45);
	call_out("advertise",random(30)+2);
	return;
	}
//Also  need to setup the table,
        set("table/total",0);
        set("table/round_high",1);
        set("table/north",0);
        set("table/south",0);
        set("table/east",0);
        set("table/west",0);
        set("table/r_north",0);
        set("table/r_south",0);
        set("table/r_east",0);
        set("table/r_west",0);
	set("table/status",0);
	set("last_turn",-1);
	set("counter",0);
	setup_card();
//setup heartbeat
	set_heart_beat(1);
// okey, let's start the game
 	sen="say ºÃ£¡ ´ó¼ÒÏÈ¸÷³öÎÆÒø"+chinese_number(query("lower_limit"))+"Á½£¬¿ª¾Ö£¡";
	if(objectp(query("north/player"))) {
	sen += "±±Ê×¡ª"+query("north/player")->name() +"£¬";
	(query("north/player"))->set_temp("no_quit",1);
	add("table/total",(int)query("lower_limit"));
	add("north/money",-(int)query("lower_limit"));
	add("table/north",(int)query("lower_limit"));
	if(query("north/money"))
	{
        set("whose_turn",0); 
	sen2 = "Çë"+query("north/player")->name()+"ÏÈÏÂ¶Ä×¢£¡\n";}
	}
        if(objectp(query("west/player"))){
	sen += "Î÷Ê×¡ª"+query("west/player")->name() +"£¬";
        (query("west/player"))->set_temp("no_quit",1);
        add("table/total",(int)query("lower_limit"));
        add("west/money",-(int)query("lower_limit"));
        add("table/west",(int)query("lower_limit"));
        if(query("west/money"))
        {
        set("whose_turn",1);
        sen2 = "Çë"+query("west/player")->name()+"ÏÈÏÂ¶Ä×¢£¡\n";}
	}
        if(objectp(query("south/player"))) {
	sen += "ÄÏÊ×¡ª"+query("south/player")->name() +"£¬";
	(query("south/player"))->set_temp("no_quit",1);
	set("whose_turn",2); 
        add("table/total",(int)query("lower_limit"));
        add("south/money",-(int)query("lower_limit"));
        add("table/south",(int)query("lower_limit"));
        if(query("south/money"))
        {
        set("whose_turn",2); 
        sen2 = "Çë"+query("south/player")->name()+"ÏÈÏÂ¶Ä×¢£¡\n";}
	}
        if(objectp(query("east/player"))) {
	sen += "¶«Ê×¡ª"+query("east/player")->name() +"£¬";
	(query("east/player"))->set_temp("no_quit",1);
        add("table/total",(int)query("lower_limit"));
        add("east/money",-(int)query("lower_limit"));
        add("table/east",(int)query("lower_limit"));
        if(query("east/money"))
        {
        set("whose_turn",3);
        sen2 = "Çë"+query("east/player")->name()+"ÏÈÏÂ¶Ä×¢£¡\n";}
	}
	set("too_late",1); 
	command(sen+"\n");
	if(stringp(sen2))command("say " + sen2);
// game might just end from here!
	check_pointer();
return;
}
int do_bet(string arg)
{
// bet means we agree to either follow to raise or throw in whatever we have
        object me;
	int mynum;
	int turn,amt,min;
	string str_amt;
        string location ="nowhere";
	if(!query("too_late"))
	return notify_fail("»¹Ã»¿ª¾ÖÄØ£¡\n");
        me = this_player();
	if(me->is_busy())
	return notify_fail("ÄãÏÖÔÚÃ»¿Õ£¡\n");
	return do_bet2(arg, me);
}
int do_bet2(string arg, object me)
{
        int mynum;
        int turn,amt,min;
        string str_amt;
        string location ="nowhere";
// There must be better way to find out who is doing a bet, well...
if( query("north/player") == me ){
location = "north"; mynum=0;}
if( query("south/player") == me ){
location = "south"; mynum=2;}
if( query("east/player") == me ){
location = "east"; mynum=3;}
if( query("west/player") == me ){
location = "west"; mynum=1;}
if(location == "nowhere") return 0;
// see if already fold or out of money
if(query(location+"/fold")) return notify_fail("ÕâÆÌÄãÒÑ¾­ÆúÈ¨ÁË£¡\n");
if(!query(location+"/money")) return notify_fail("ÄãµÄÒø×ÓÒÑ¾­È«²¿ÓÃ¹âÁË£¡\n");
turn = (int) query("whose_turn");
if(turn%4 != mynum) return notify_fail("»¹Ã»ÓĞÂÖµ½ÄãÄÄ£¡\n");
// no argument means we just "follow" hehe
min = (int)query("table/round_high") - (int)query("table/r_"+location);
if(!arg || arg=="" || arg == " ")
	amt = min;
else
if (arg=="all")
	amt=(int)query(location+"/money");
else

	if(sscanf(arg,"%d",amt) != 1 )
		return notify_fail("bet <|ÊıÁ¿|all>\n");
if(amt < min){
// we only allow this if our leftover money is less than min
	if(query(location+"/money") < min)
	{
	if(amt < query(location+"/money"))
	return notify_fail("ÄãÒªÃ´²»¸ú£¬ÒªÃ´µÃ°ÑÄãÃæÇ°µÄÒø×Ó¶¼¶Ä³öÈ¥£¡\n");
	else
//add it to table
	add("table/total",query(location+"/money"));
// add it to your money in table
	add("table/"+location,query(location+"/money"));
// add it to this round
	add("table/r_"+location,query(location+"/money"));
// deduct it from your pocket
	message_vision("$N²»¶¯ÉùÉ«µØ°ÑÃæÇ°µÄ"+chinese_number(query(location+"/money"))+"Á½Òø×ÓÈ«²¿ÍÆÁË³öÈ¥¡£\n",me);
	set(location+"/money",0);
	}
	else return notify_fail("Äã×îÉÙÒªÏÂ"+chinese_number(min)+"Á½Òø×ÓµÄ¶Ä×¢¡£\n");

}
else
{
	if(query(location+"/money") <= amt)
	{
//add it to table
        add("table/total",query(location+"/money"));
// add it to your money in table
        add("table/"+location,query(location+"/money"));
// add it to this round
        add("table/r_"+location,query(location+"/money"));
// deduct it from your pocket
        message_vision("$N²»¶¯ÉùÉ«µØ°ÑÃæÇ°µÄ"+chinese_number(query(location+"/money"))+"Á½Òø×ÓÈ«²¿ÍÆÁË³öÈ¥¡£\n",me);
        add("table/round_high",amt-min);
        set(location+"/money",0);
	}
	else
	{
//hopefully this is where normal people fall into
//add it to table
        add("table/total",amt);
// add it to your money in table
        add("table/"+location,amt);
// add it to this round
        add("table/r_"+location,amt);
// deduct it from your pocket
        message_vision("$N½«ÃæÇ°µÄ"+chinese_number(amt)+"Á½Òø×ÓÍÆµ½ÁË×À×ÓÖĞ¼ä¡£\n",me);
        add(location+"/money",-amt);
	add("table/round_high",amt-min);
	}
}
// always have to do this, right?
add("whose_turn",1);
me->start_busy(1);
check_pointer();
return 1;
}
int do_fold()
{
// sometimes, we are just out of luck, ormaybe we are smart?!
        object me;
        int mynum;
	int turn;
        string location ="nowhere";
        if(!query("too_late"))
        return notify_fail("»¹Ã»¿ª¾ÖÄØ£¡\n");
        me = this_player();
        if(me->is_busy())
        return notify_fail("ÄãÏÖÔÚÃ»¿Õ£¡\n");
// There must be better way to find out who is doing a bet, well...
if( query("north/player") == me ){
location = "north"; mynum=0;}
if( query("south/player") == me ){
location = "south"; mynum=2;}
if( query("east/player") == me ){
location = "east"; mynum=3;}
if( query("west/player") == me ){
location = "west"; mynum=1;}
if(location == "nowhere") return 0;
if(query(location+"/fold")) return notify_fail("ÕâÆÌÄãÒÑ¾­ÆúÈ¨ÁË£¡\n");
if(!query(location+"/money")) return notify_fail("ÄãµÄÒø×ÓÒÑ¾­È«²¿ÓÃ¹âÁË£¡\n");
turn = (int) query("whose_turn");
if(turn%4 != mynum) return notify_fail("»¹Ã»ÓĞÂÖµ½ÄãÄÄ£¡\n");
set(location+"/fold",1);
message_vision("$NËµµÀ£º£¢ÕâÆÌÎÒ²»¸úÁË£¡£¢\n",me);
add("whose_turn",1);
me->start_busy(1);
check_pointer();
return 1;

}
void end_the_round()
{
	string *good_ones = ({});
	string *tmp = ({});
	int total;
	int percent;
	int i,j,k;
	string *locss = ({"north","south","east","west"});
	int mm;
// sometimes the highest card holder out of money first, hehe
// Let's start withe person who put out the least, hopefully he/she can get his/her share
// He is either fold or out of money before it ends;
	if(query("table/status") == -1) return;
	set("table/status",-1);
	total = (int)query("table/total");
	for(mm=0;mm<sizeof(locss);mm++)
	if(query(locss[mm]+"/first") == query(locss[mm]+"/second"))
		set("table/R_"+locss[mm],(int)query(locss[mm]+"/first") * 10000);
	else
		set("table/R_"+locss[mm], ((int)query(locss[mm]+"/first") > (int)query(locss[mm]+"/second")? 
		(int)query(locss[mm]+"/first")*100+(int)query(locss[mm]+"/second") :
		(int)query(locss[mm]+"/second")*100+(int)query(locss[mm]+"/first")));
/*
	command("say "+sprintf("north %d, south %d, east %d, west %d\n",
		query("table/R_north"),
                query("table/R_south"),
                query("table/R_east"),
                query("table/R_west")));
*/
// put them in array good_ones according to money take out! skip those 0's
if(query("table/north") != 0  && !query("north/fold")){ tmp += ({ "north" });}
if(query("table/west") != 0 && !query("west/fold"))  { tmp += ({ "west" });}
if(query("table/south") != 0 && !query("south/fold")) { tmp += ({ "south" });}
if(query("table/east") != 0 && !query("east/fold")) { tmp += ({ "east" });}

good_ones = sort_array(tmp,"sort_it",this_object());
// let's start with the lowest
	for(i=0;i<sizeof(good_ones);i++)
	{
	int history=0;
	int num_of_share=0;
	int sum=0;
		for(j=0;j<sizeof(good_ones);j++)
		{
// we assume we are the biggest and the only one
			if((int)query("table/R_"+good_ones[j])> (int)query("table/R_"+good_ones[i]))
// we found someone who is bigger and last longer :) well, this guy is history
			history=1;
			else if((int)query("table/R_"+good_ones[j])== (int)query("table/R_"+good_ones[i]))
				num_of_share++;
		}
		if(!history)
		{
// we can get something back!
		int mylevel;
		string *locs = ({"north","south","east","west"});
		int m;
		mylevel = (int)query("table/"+good_ones[i]);
		for(m=0;m<sizeof(locs);m++)
		if(query("table/"+locs[m])>mylevel)
			{
				add("table/"+locs[m],-mylevel);
				sum += mylevel;

			}
			else
			{
				sum += query("table/"+locs[m]);
				set("table/"+locs[m],0);

			}
		for(j=0;j<sizeof(good_ones);j++)
		if((int)query("table/R_"+good_ones[j])== (int)query("table/R_"+good_ones[i]))
			add("table/output_"+good_ones[j],sum/num_of_share);

// already got chance!
		set("table/R_"+good_ones[i],-1);
		}// !history

	}// i loop
// now casino takes query("my_percentage")%
	percent = (int) query("my_percentage");
		add("table/output_north",-(int)query("table/output_north") * percent/100);
                add("table/output_south",-(int)query("table/output_south") * percent/100);
                add("table/output_east",-(int)query("table/output_east") * percent/100);
                add("table/output_west",-(int)query("table/output_west") * percent/100);
	{
                string *locs = ({"north","south","east","west"});
                int m;
		string msg ;
		for(m=0;m<sizeof(locs);m++)
			if(!(int)query(locs[m]+"/fold") && objectp(query(locs[m]+"/player"))
				&& query(locs[m]+"/first") && query(locs[m]+"/second"))
		{
				msg = "say "+(query(locs[m]+"/player"))->name()+"£­£­"+
                        chinese_number((int)query(locs[m]+"/first"))+"¡¢"+
                        chinese_number((int)query(locs[m]+"/second"))+ "\n";
			command(msg);
		}
		for(m=0;m<sizeof(locs);m++)
			if((int)query("table/output_"+locs[m]))
			{
			add(locs[m]+"/money",(int)query("table/output_"+locs[m]));
				msg = "say "+ (query(locs[m]+"/player"))->name()+
			"Ó®ÁË"+chinese_number((int)query("table/output_"+locs[m]))+"Á½ÎÆÒø¡£\n";

		command(msg);
			}
// kick out link dead; and kick out 0-money people
	delete("table");
	set("table/status",-1);
		for(m=0;m<sizeof(locs);m++)
		{
			object ob;
// they can quit or leave now
			if(objectp(ob=query(locs[m]+"/player")))
			ob->delete_temp("no_quit");
			delete(locs[m]+"/fold");
			delete(locs[m]+"/first");
			delete(locs[m]+"/second");
                        if( objectp(ob=query(locs[m]+"/player")) && (int)query(locs[m]+"/money") <= 0)
// out of money
			{
				message_vision("$N¶Ô$nËµµÀ£º£¢Äú¶¼Êä¹âÁË£¬ÏÂ´ËÔÙÀ´°É£¡£¢\n",this_object(),ob);
				delete(locs[m]);	
			}
			if( objectp(ob=query(locs[m]+"/player")) && ob->query_temp("netdead"))
//link dead
			{
				pay_him(ob, (int)query(locs[m]+"/money")*100);
				delete(locs[m]);
			}			

		}	


	}
                command("say ÖîÎ»ÉÔµÈÆ¬¿Ì£¬ÈÃÎÒÏ´Ï´ÅÆ£¬ÔÙ¿ªÊ¼£¡\n");
		set("too_late",0);
		call_out("rolldice",10);
return;
}
void pay_him(object who, int amount)
{
        object ob;
        object cash, tencash, gold, silver, coin;

        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}
int accept_object(object who, object ob)
{
	int bet_type;
	string message;
	
                if( ob->value() >= 10000) {
                        say("Àä¶¬Ã·ÏòÄãµÀÁË¸öÍò¸££¬Ğ¦µÀ£ºĞ»ÉÍ...\n");
                        return 1;
                } else {
                    say("Àä¶¬Ã·ËµµÀ£ºÕâµãÇ®Äã»¹ÊÇ×Ô¼ºÓÃ°É£¡\n");
                        return 0;
                }
        return 0;
}

void check_pointer()
{
// 3 things to check in here:
//  a. phase of this round
//  b. phase of this hand
//  c. conclude or not?
	string location="nowhere";
	int whohasmoney=0;
	int whohasnotfold=0;
	int last_bet=0;
        if(objectp(query("north/player")) && query("north/money") && !query("north/fold")) {whohasmoney++;location="north";}
        if(objectp(query("south/player")) && query("south/money") && !query("south/fold")) {whohasmoney++;location="south";}
        if(objectp(query("east/player")) && query("east/money") && !query("east/fold")) {whohasmoney++;location="east";}
        if(objectp(query("west/player")) && query("west/money") && !query("west/fold")) {whohasmoney++;location="west";}
        if(objectp(query("north/player")) && !query("north/fold")) whohasnotfold++;
        if(objectp(query("south/player")) && !query("south/fold")) whohasnotfold++;
        if(objectp(query("east/player")) && !query("east/fold")) whohasnotfold++;
        if(objectp(query("west/player")) && !query("west/fold")) whohasnotfold++;
        if((whohasmoney<=1 && query("table/r_"+location) >= query("table/round_high")) ||
        (whohasmoney<=1 && !query("table/r_north") && !query("table/r_south") &&
         !query("table/r_east") && !query("table/r_west"))
        )
        last_bet=1;
// step1: if everyone has put in as much as round high, expcept those alrady out of money
	if( last_bet==1 || whohasnotfold <=1 ||
((int)query("table/r_north") == (int)query("table/round_high") ||
 (int)query("north/money") == 0 || (int)query("north/fold")) 
 &&
((int)query("table/r_south") == (int)query("table/round_high") ||
 (int)query("south/money") == 0 || (int)query("south/fold")) 
 &&
((int)query("table/r_east") == (int)query("table/round_high") ||
 (int)query("east/money") == 0 || (int)query("east/fold")) 
 &&
((int)query("table/r_west") == (int)query("table/round_high") ||
 (int)query("west/money") == 0 || (int)query("west/fold")) 
	)
{
// see if we can end this game at this time, we can if only one person left,right?
if(can_end_round()) end_the_round();
else
{
switch((int)query("table/status"))
{
	int number;
	case 0:
// time to give 1st card and clear round_high and r_X:
message_vision("\n\n$NÊìÁ·ÒÑ¼«µØ½«×ÀÉÏµÄÏóÑÀ÷½ÅÆÔÚÊÖÀïÒ»×ª£¬¿ªÊ¼¸ø´ó¼Ò·¢µÚÒ»ÕÅÅÆ¡£\n\n",this_object());
// anyone who did not fold deserve a card!	
if(objectp(query("north/player")) && !(int)query("north/fold"))
{
	number = give_card();
tell_object(query("north/player"),name()+"½«Ò»ÕÅ¾§Ó¨ÌŞÍ¸µÄ÷½ÅÆÍÆµ½ÄãÃæÇ°¡£\n");
tell_object(query("north/player"),"Äã·­¿ªÒ»¿´£º\n"+showdice(number)+"\n");
	set("north/first",number);
}
if(objectp(query("west/player")) && !(int)query("west/fold"))
{
        number = give_card();
tell_object(query("west/player"),name()+"½«Ò»ÕÅ¾§Ó¨ÌŞÍ¸µÄ÷½ÅÆÍÆµ½ÄãÃæÇ°¡£\n");
tell_object(query("west/player"),"Äã·­¿ªÒ»¿´£º\n"+showdice(number)+"\n");
        set("west/first",number);
}
if(objectp(query("south/player")) && !(int)query("south/fold"))
{
        number = give_card();
tell_object(query("south/player"),name()+"½«Ò»ÕÅ¾§Ó¨ÌŞÍ¸µÄ÷½ÅÆÍÆµ½ÄãÃæÇ°¡£\n");
tell_object(query("south/player"),"Äã·­¿ªÒ»¿´£º\n"+showdice(number)+"\n");
        set("south/first",number);
}
if(objectp(query("east/player")) && !(int)query("east/fold"))
{
        number = give_card();
tell_object(query("east/player"),name()+"½«Ò»ÕÅ¾§Ó¨ÌŞÍ¸µÄ÷½ÅÆÍÆµ½ÄãÃæÇ°¡£\n");
tell_object(query("east/player"),"Äã·­¿ªÒ»¿´£º\n"+showdice(number)+"\n");
        set("east/first",number);
}
//clear some parameters
	set("table/r_north",0);
	set("table/r_south",0);
	set("table/r_east",0);
	set("table/r_west",0);
	set("table/round_high",1);
	add("table/status",1);
	find_next();
	break;
        case 1:
// time to give 2nd card and clear round_high and r_X:
message_vision("\n\n$N½«×ÀÉÏÊ£ÏÂµÄÏóÑÀ÷½ÅÆÍÆÁËÍÆ£¬¿ªÊ¼¸ø´ó¼Ò·¢µÚ¶şÕÅÅÆ¡£\n\n",this_object());
// anyone who did not fold deserve a card!
if(objectp(query("north/player")) && !(int)query("north/fold"))
{
        number = give_card();
tell_object(query("north/player"),name()+"½«Ò»ÕÅ¾§Ó¨ÌŞÍ¸µÄ÷½ÅÆÍÆµ½ÄãÃæÇ°¡£\n");
tell_object(query("north/player"),"Äã·­¿ªÒ»¿´£º\n"+showdice(number)+"\n");
        set("north/second",number);
}
if(objectp(query("west/player")) && !(int)query("west/fold"))
{
        number = give_card();
tell_object(query("west/player"),name()+"½«Ò»ÕÅ¾§Ó¨ÌŞÍ¸µÄ÷½ÅÆÍÆµ½ÄãÃæÇ°¡£\n");
tell_object(query("west/player"),"Äã·­¿ªÒ»¿´£º\n"+showdice(number)+"\n");
        set("west/second",number);
}
if(objectp(query("south/player")) && !(int)query("south/fold"))
{
        number = give_card();
tell_object(query("south/player"),name()+"½«Ò»ÕÅ¾§Ó¨ÌŞÍ¸µÄ÷½ÅÆÍÆµ½ÄãÃæÇ°¡£\n");
tell_object(query("south/player"),"Äã·­¿ªÒ»¿´£º\n"+showdice(number)+"\n");
        set("south/second",number);
}
if(objectp(query("east/player")) && !(int)query("east/fold"))
{
        number = give_card();
tell_object(query("east/player"),name()+"½«Ò»ÕÅ¾§Ó¨ÌŞÍ¸µÄ÷½ÅÆÍÆµ½ÄãÃæÇ°¡£\n");
tell_object(query("east/player"),"Äã·­¿ªÒ»¿´£º\n"+showdice(number)+"\n");
        set("east/second",number);
}
//clear some parameters
        set("table/r_north",0);
	set("table/r_south",0);
	set("table/r_east",0);
	set("table/r_west",0);
        set("table/round_high",1);
	add("table/status",1);
	find_next();
        break;

}


}

return ;
}
else
{
// this round is not done yet, just check counter or increment to next person 
find_next();
}
return ;
}
void setup_card()
{
	set("cards",({ 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,
		      14,15,16,17,18,19,20,21,22,23,24,25,
		      27,28,29,30,31,32,33,34,35,36,37,38,
		      40,41,42,43,44,45,46,47,48,49,50,51
		}));	

}
int give_card()
{
// Using daniel's suggestion here, 
int output;
int *cards;
	cards = query("cards");
	output = cards[random(sizeof(cards))];
	cards -= ({ output });
	set("cards", cards);
	return output%13;	
}

int can_end_round()
{
	int not_fold = 0;
// if we are in stage2 and reach an equibilium, then we can end this game
	if((int)query("table/status") >=2) return 1;
	if(objectp(query("north/player")) && !query("north/fold")) not_fold++;
        if(objectp(query("south/player")) && !query("south/fold")) not_fold++;
        if(objectp(query("east/player")) && !query("east/fold")) not_fold++;
        if(objectp(query("west/player")) && !query("west/fold")) not_fold++;
if(not_fold <=1) return 1;
return 0;
}
void find_next()
{
        string location="nowhere";
        int whohasmoney=0;
        int whohasnotfold=0;
        int last_bet=0;
        if(objectp(query("north/player")) && query("north/money") && !query("north/fold")) {whohasmoney++;location="north";}
        if(objectp(query("south/player")) && query("south/money") && !query("south/fold")) {whohasmoney++;location="south";}
        if(objectp(query("east/player")) && query("east/money") && !query("east/fold")) {whohasmoney++;location="east";}
        if(objectp(query("west/player")) && query("west/money") && !query("west/fold")) {whohasmoney++;location="west";}
        if(objectp(query("north/player")) && !query("north/fold")) whohasnotfold++;
        if(objectp(query("south/player")) && !query("south/fold")) whohasnotfold++;
        if(objectp(query("east/player")) && !query("east/fold")) whohasnotfold++;
        if(objectp(query("west/player")) && !query("west/fold")) whohasnotfold++;
        if((whohasmoney<=1 && query("table/r_"+location) >= query("table/round_high")) ||
	( whohasmoney <=1 && !query("table/r_north") && !query("table/r_south") &&
	 !query("table/r_east") && !query("table/r_west"))
	)
        last_bet=1;

        if( last_bet==1 || whohasnotfold <=1 ||
((int)query("table/r_north") == (int)query("table/round_high") ||
 (int)query("north/money") == 0 || (int)query("north/fold")) 
 &&
((int)query("table/r_south") == (int)query("table/round_high") ||
 (int)query("south/money") == 0 || (int)query("south/fold")) 
 &&
((int)query("table/r_east") == (int)query("table/round_high") ||
 (int)query("east/money") == 0 || (int)query("east/fold")) 
 &&
((int)query("table/r_west") == (int)query("table/round_high") ||
 (int)query("west/money") == 0 || (int)query("west/fold")) 
        )

	check_pointer();
switch ((int)query("whose_turn")%4)
{
        case 0: 
                if(objectp(query("north/player")) &&
                (int)query("north/money") > 0 &&
                !(int)query("north/fold")) 
tell_object(query("north/player"),name()+"¶Ô×Å"+
"ÄãËµµÀ£º£¢ÕâÎ»"+ RANK_D->query_respect(query("north/player"))+
"ÂÖµ½ÄúËµ»°ÁË¡££¢\n");
                else
                {
                        add("whose_turn",1);
                        check_pointer();
                }
                return;
        case 1: 
                if(objectp(query("west/player")) &&
                (int)query("west/money") > 0 &&
                !(int)query("west/fold")) 
tell_object(query("west/player"),name()+"¶Ô×Å"+
"ÄãËµµÀ£º£¢ÕâÎ»"+ RANK_D->query_respect(query("west/player"))+
"ÂÖµ½ÄúËµ»°ÁË¡££¢\n");
                else
                {
                        add("whose_turn",1);
                        check_pointer();
                }
                return;
        case 2: 
                if(objectp(query("south/player")) &&
                (int)query("south/money") > 0 &&
                !(int)query("south/fold")) 
tell_object(query("south/player"),name()+"¶Ô×Å"+
"ÄãËµµÀ£º£¢ÕâÎ»"+ RANK_D->query_respect(query("south/player"))+
"ÂÖµ½ÄúËµ»°ÁË¡££¢\n");
                else
                {
                        add("whose_turn",1);
                        check_pointer();
                }
                return;
        case 3: 
                if(objectp(query("east/player")) &&
                (int)query("east/money") > 0 &&
                !(int)query("east/fold")) 
tell_object(query("east/player"),name()+"¶Ô×Å"+
"ÄãËµµÀ£º£¢ÕâÎ»"+ RANK_D->query_respect(query("east/player"))+
"ÂÖµ½ÄúËµ»°ÁË¡££¢\n");
                else
                {
                        add("whose_turn",1);
                        check_pointer();
                }
                return;

}
}
int sort_it(string a, string b)
{
return (int)query("table/"+a)-(int)query("table/"+b);
}

string showdice(int num)
{
	string out;
	string *outs;
	string output="\n";
	int i;
	out = dice[num];
	outs = explode(out,"B");
	for(i=0;i<sizeof(outs);i++)
		output	+= "          "+outs[i]+"\n";
	return output;
}
string showdice2(int num1, int num2)
{
        string out1,out2;
        string *outs1,*outs2;
        string output="\n";
        int i;
        out1 = dice[num1];
	out2 = dice[num2];
	
        outs1 = explode(out1,"B");
	outs2 = explode(out2,"B");
        for(i=0;i<sizeof(outs1);i++)
                output  += "          "+outs1[i]+"               "+outs2[i]+"\n";
        return output;
}


int do_cards()
{
        object me;
        string location ="nowhere";
        me = this_player();
if( query("north/player") == me )  location = "north";
if( query("south/player") == me )  location = "south";
if( query("east/player") == me )  location = "east";
if( query("west/player") == me )  location = "west";
if(location == "nowhere") return 0;
if(query(location+"/first") && ! query(location+"/second"))
	tell_object(me,"ÄãÊÖÀïµÄ÷»ÅÆÊÇ£º\n"+showdice((int)query(location+"/first")));
else
if(query(location+"/first") &&  query(location+"/second"))
        tell_object(me,"ÄãÊÖÀïµÄ÷»ÅÆÊÇ£º\n"+showdice2((int)query(location+"/first"),(int)query(location+"/second")));
else tell_object(me,"ÄãÊÖÀï»¹Ã»ÓĞÅÆÄØ£¡\n");
return 1;
}
void heart_beat()
{
	object player;
:: heart_beat();
// to help link-dead people
if( query("too_late") &&
	query("last_turn") == query("whose_turn") &&
	query("counter") >= 30)
{
	set("counter",0);
switch((int)query("whose_turn")%4)
{
	case 0: 
		if(objectp(player=query("north/player")))
		{

			message_vision("$N¶Ô$nËµµÀ£ºÄúË¯×ÅÀ²£¿ÄÇÎÒ¾ÍÌæÄú¸úÁË°É£¡\n",this_object(),player);
			do_bet2("",player);
		}
		return;
        case 1: 
                if(objectp(player=query("west/player")))
                {

                        message_vision("$N¶Ô$nËµµÀ£ºÄúË¯×ÅÀ²£¿ÄÇÎÒ¾ÍÌæÄú¸úÁË°É£¡\n",this_object(),player);
                        do_bet2("",player);
                }
                return;
        case 2: 
                if(objectp(player=query("south/player")))
                {

                        message_vision("$N¶Ô$nËµµÀ£ºÄúË¯×ÅÀ²£¿ÄÇÎÒ¾ÍÌæÄú¸úÁË°É£¡\n",this_object(),player);
                        do_bet2("",player);
                }
                return;
        case 3: 
                if(objectp(player=query("east/player")))
                {

                        message_vision("$N¶Ô$nËµµÀ£ºÄúË¯×ÅÀ²£¿ÄÇÎÒ¾ÍÌæÄú¸úÁË°É£¡\n",this_object(),player);
                        do_bet2("",player);
                }
                return;


}
}

else
	if(query("last_turn") == query("whose_turn"))
	add("counter",1);
else
	{
	set("last_turn",query("whose_turn"));
	set("counter",0);
	}
return;
}
