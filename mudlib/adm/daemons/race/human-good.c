 // human.c
 
// A normal human is at least 40 kg weight 
#define BASE_WEIGHT 40000 
 
inherit F_DBASE; 
 
mapping *combat_action = ({ 
        ([      "action":               "$N»ÓÈ­¹¥»÷$nµÄ$l", 
                "damage_type":  "ðöÉË", 
        ]), 
        ([      "action":               "$NÍù$nµÄ$lÒ»×¥", 
                "damage_type":  "×¥ÉË", 
        ]), 
        ([      "action":               "$NÍù$nµÄ$lºÝºÝµØÌßÁËÒ»½Å", 
                "damage_type":  "ðöÉË", 
        ]), 
        ([      "action":               "$NÌáÆðÈ­Í·Íù$nµÄ$l´·È¥", 
                "damage_type":  "ðöÉË", 
        ]), 
        ([      "action":               "$N¶Ô×¼$nµÄ$lÓÃÁ¦»Ó³öÒ»È­", 
                "damage_type":  "ðöÉË", 
        ]), 
}); 
 
void create() { 
        seteuid(getuid()); 
        set("unit", "Î»"); 
        set("gender", "ÄÐÐÔ"); 
        set("can_speak", 1); 
        set("attitude", "peaceful"); 
        set("limbs", ({ 
                "Í·²¿", "¾±²¿", "ÐØ¿Ú", "ááÐÄ", "×ó¼ç", "ÓÒ¼ç", "×ó±Û", 
                "ÓÒ±Û", "×óÊÖ", "ÓÒÊÖ", "Ñü¼ä", "Ð¡¸¹", "×óÍÈ", "ÓÒÍÈ", 
                "×ó½Å", "ÓÒ½Å", "×óÀß", "ÓÒÀß", "Ç°ÐØ", "ºó±³", "Ã¼ÐÄ", 
                "ºóÑü", "ºó¾±", "×ó¿è", "ÓÒ¿è", "ºóÄÔ", "×óÑÛ", "ÓÒÑÛ", 
                "×ó¼Õ", "ÓÒ¼Õ" 
        }) ); 
} 
 
void setup_human(object ob) { 
        mapping my; 
        int combat_exp, bonus; 
 
        my = ob->query_entire_dbase(); 
        combat_exp = my["combat_exp"]; 
        if(combat_exp < 100000) { 
                bonus = combat_exp * 0.005;      
        } else if(combat_exp < 1000000) { 
                bonus = combat_exp * 0.0009 + 700; 
        } else if(combat_exp < 10000000) { 
                bonus = combat_exp * 0.00025 + 1750; 
        } else { 
                bonus = 4500; 
        } 
         
         
        ob->set("default_actions", (: call_other, __FILE__, "query_action" :)); 
 
        if(undefinedp(my["national"])) my["national"] = "ºº×å"; 
         
        if(undefinedp(my["age"])) my["age"] = random(30) + 15; 
        if(undefinedp(my["str"])) my["str"] = random(25) + 5; 
        if(undefinedp(my["cor"])) my["cor"] = random(20) + 5; 
        if(undefinedp(my["int"])) my["int"] = random(5) + 20; 
        if(undefinedp(my["spi"])) my["spi"] = random(20) + 5; 
        if(undefinedp(my["cps"])) my["cps"] = random(20) + 5; 
        if(undefinedp(my["per"])) my["per"] = random(20) + 5; 
        if(undefinedp(my["con"])) my["con"] = random(20) + 5; 
        if(undefinedp(my["kar"])) my["kar"] = random(20) + 5; 
        if(undefinedp(my["agi"])) my["agi"] = random(20) + 5; 
        if(undefinedp(my["dur"])) my["dur"] = random(2) + 1; 
        if(undefinedp(my["fle"])) my["fle"] = random(20) + 5; 
        if(undefinedp(my["tol"])) my["tol"] = random(20) + 5; 
 
        if(userp(ob) || undefinedp(my["max_gin"])) { 
                if(my["age"] <= 14) { 
                        my["max_gin"] = 100 + my["spi"]*10; 
                } else if( my["age"] <= 20 ) { 
                        my["max_gin"] = 100 + (my["age"] - 14) * 20  + my["spi"]*10; 
           } else if( my["age"] <= 30 ) { 
                         my["max_gin"] = 220  + my["spi"]*10; 
                } else if( my["age"] <= 60 ) { 
                        my["max_gin"] = 220 - (my["age"] - 30) * 5  + my["spi"]*10; 
                } else { 
                        my["max_gin"] = 70  + my["spi"]*10; 
                } 
                if(my["max_atman"] > 0) { 
                        my["max_gin"] += my["max_atman"] ; 
                } 
                my["max_gin"] += my["dur"]*my["dur"]; 
                if(!userp(ob)) { 
                        my["max_gin"] += bonus / 2;              
                } 
        } 
         
        if(userp(ob) || undefinedp(my["max_kee"])) { 
                if(my["age"] <= 14) { 
                        my["max_kee"] = 100 + my["con"]*10; 
                } else if(my["age"] <= 20) { 
                        my["max_kee"] = 100 + (my["age"] - 14) * 20 + my["con"]*10; 
                } else { 
                        my["max_kee"] = 220 + my["con"]*10; 
                } 
                if(my["max_force"] > 0) { 
                        my["max_kee"] += my["max_force"] ; 
                } 
                my["max_kee"] += my["dur"]*my["dur"]; 
                if(!userp(ob)) { 
                        my["max_kee"] += bonus;  
                } 
        } 
        if(userp(ob) || undefinedp(my["max_sen"])) { 
                if(my["age"] <= 30) { 
                        my["max_sen"] = 100 + my["int"]*10; 
                } else { 
                        my["max_sen"] = 100 + (my["age"] - 30) * 5 + my["int"]*10; 
                } 
                if(my["max_mana"] > 0) { 
                        my["max_sen"] += my["max_mana"] ; 
           } 
                my["max_sen"] += my["dur"]*my["dur"]; 
                if(!userp(ob)) { 
                        my["max_sen"] += bonus / 2;      
                } 
        } 
 
        ob->set_default_object(__FILE__); 
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 200); 
} 
 
mapping query_action() 
{ 
        return combat_action[random(sizeof(combat_action))]; 
}   
