#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "ÓðÌì°×",
                "quest_type":           "É±",
                "exp_bonus":            80,
        ]),
        ([      "quest":               HIG"Ð¡Â¥Ò»Ò¹Ìý´ºÓê"NOR,
                "quest_type":           "Ñ°",
                "exp_bonus":            80,
        ]),
        ([      "quest":               HIW"°×ÓðÅÛ"NOR,
                "quest_type":           "Ñ°",
                "exp_bonus":            80,
        ]),
        ([      "quest":                "¶¨°î´óÊ¦",
                "quest_type":           "É±",
                "exp_bonus":            80,
        ]),
        ([      "quest":               "½ð¸ÕèÆ" ,
                "quest_type":           "Ñ°",
                "exp_bonus":            80,
        ]),
        ([      "quest":                "ÔÆ¿Õ",
                "quest_type":           "É±",
                "exp_bonus":            80,
        ]),
        ([      "quest":                "ÔÆÃ÷",
                "quest_type":           "É±",
                "exp_bonus":            80,
        ]),
        ([      "quest":               "×ÏÍ­ìøÕÈ" ,
                "quest_type":           "Ñ°",
                "exp_bonus":            80,
        ]),  
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}    
