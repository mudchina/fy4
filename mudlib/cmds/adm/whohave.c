 // whohave.c
inherit F_CLEAN_UP; 
mixed main(object me, string arg, int remote)
{
        object *ulist, *ilist;
        int i, j; 
        if (! arg)
                return notify_fail ("指令格式 whohave <id>\n"); 
        //ulist = users();
        ulist = livings();
        i = sizeof(ulist);
        while (i--) {
                if (! present (arg,ulist[i]))
                        continue;
                write ("  "+ulist[i]->query("name")+":");
                ilist = all_inventory(ulist[i]);
                j = sizeof(ilist);
                while (j--) {
                        object ob = ilist[j];
                        string *ids = ob->parse_command_id_list();
                        if (member_array(arg, ids) == -1)
                                continue;
                        write (" "+ob->short());
                }
                write ("\n");
        }
        return 1;
} 
int help (object me)
{
        write(@HELP
指令格式 : whohave <id>
 
可列出目前携带某个物品的玩家。
 
 
HELP
);
        return 1;
}
