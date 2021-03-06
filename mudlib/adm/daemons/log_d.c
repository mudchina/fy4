//log_d.c
//记录玩家一生中的重要时刻。

#include <ansi.h>

inherit F_DBASE;

void create()
{
    seteuid(ROOT_UID);
    set("name", "记录精灵");
    set("id", "log_d");
}

string query_log_file( string arg)
{
    return sprintf( DATA_DIR "log/%c/%s", arg[0], arg );
}

int do_log( object me, string str )
{
    string time, file;
    time = NATURE_D->game_time();
    file = query_log_file( me->query("id") );
    assure_file( file );
    return write_file( file, sprintf(GRN "%s\n" NOR "%s\n", time, str ) );
}

int do_record( object me, string str )
{
    string age, file;
    age = chinese_number( (int)me->query("age") );
    file = query_log_file( me->query("id") );
    assure_file( file );
    return write_file ( file, sprintf( RED "%s岁备忘录：\n" NOR "%s\n", age, str) );
}

