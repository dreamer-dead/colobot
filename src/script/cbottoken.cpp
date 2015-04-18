/*
 * This file is part of the Colobot: Gold Edition source code
 * Copyright (C) 2001-2014, Daniel Roux, EPSITEC SA & TerranovaTeam
 * http://epsiteс.ch; http://colobot.info; http://github.com/colobot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://gnu.org/licenses
 */


#include "script/cbottoken.h"

#include "object/object.h"
#include "app/app.h"

#include <string.h>

// Returns the help file to use for the object.

std::string GetHelpFilename(CObjectType* type)
{
    std::string x = "";
    if ( type == OBJECT_BASE        )  x = "object/base.txt";
    if ( type == OBJECT_DERRICK     )  x = "object/derrick.txt";
    if ( type == OBJECT_FACTORY     )  x = "object/factory.txt";
    if ( type == OBJECT_STATION     )  x = "object/station.txt";
    if ( type == OBJECT_CONVERT     )  x = "object/convert.txt";
    if ( type == OBJECT_REPAIR      )  x = "object/repair.txt";
    if ( type == OBJECT_DESTROYER   )  x = "object/destroy.txt";
    if ( type == OBJECT_TOWER       )  x = "object/tower.txt";
    if ( type == OBJECT_NEST        )  x = "object/nest.txt";
    if ( type == OBJECT_RESEARCH    )  x = "object/research.txt";
    if ( type == OBJECT_RADAR       )  x = "object/radar.txt";
    if ( type == OBJECT_INFO        )  x = "object/exchange.txt";
    if ( type == OBJECT_ENERGY      )  x = "object/energy.txt";
    if ( type == OBJECT_LABO        )  x = "object/labo.txt";
    if ( type == OBJECT_NUCLEAR     )  x = "object/nuclear.txt";
    if ( type == OBJECT_PARA        )  x = "object/captor.txt";
    if ( type == OBJECT_SAFE        )  x = "object/safe.txt";
    if ( type == OBJECT_HUSTON      )  x = "object/huston.txt";
    if ( type == OBJECT_START       )  x = "object/start.txt";
    if ( type == OBJECT_END         )  x = "object/goal.txt";
    if ( type == OBJECT_STONE       )  x = "object/titanore.txt";
    if ( type == OBJECT_URANIUM     )  x = "object/uranore.txt";
    if ( type == OBJECT_METAL       )  x = "object/titan.txt";
    if ( type == OBJECT_POWER       )  x = "object/power.txt";
    if ( type == OBJECT_ATOMIC      )  x = "object/atomic.txt";
    if ( type == OBJECT_BULLET      )  x = "object/bullet.txt";
    if ( type == OBJECT_BBOX        )  x = "object/bbox.txt";
    if ( type == OBJECT_KEYa        )  x = "object/key.txt";
    if ( type == OBJECT_KEYb        )  x = "object/key.txt";
    if ( type == OBJECT_KEYc        )  x = "object/key.txt";
    if ( type == OBJECT_KEYd        )  x = "object/key.txt";
    if ( type == OBJECT_TNT         )  x = "object/tnt.txt";
    if ( type->GetName() == "Scrap" )  x = "object/scrap.txt";
    if ( type == OBJECT_BOMB        )  x = "object/mine.txt";
    if ( type->GetName() == "Barrier" )  x = "object/barrier.txt";
    if ( type == OBJECT_WAYPOINT    )  x = "object/waypoint.txt";
    if ( type == OBJECT_FLAGb       )  x = "object/flag.txt";
    if ( type == OBJECT_FLAGr       )  x = "object/flag.txt";
    if ( type == OBJECT_FLAGg       )  x = "object/flag.txt";
    if ( type == OBJECT_FLAGy       )  x = "object/flag.txt";
    if ( type == OBJECT_FLAGv       )  x = "object/flag.txt";
    if ( type == OBJECT_MARKPOWER   )  x = "object/enerspot.txt";
    if ( type == OBJECT_MARKSTONE   )  x = "object/stonspot.txt";
    if ( type == OBJECT_MARKURANIUM )  x = "object/uranspot.txt";
    if ( type == OBJECT_MOBILEwa    )  x = "object/botgr.txt";
    if ( type == OBJECT_MOBILEta    )  x = "object/botgc.txt";
    if ( type == OBJECT_MOBILEfa    )  x = "object/botgj.txt";
    if ( type == OBJECT_MOBILEia    )  x = "object/botgs.txt";
    if ( type == OBJECT_MOBILEws    )  x = "object/botsr.txt";
    if ( type == OBJECT_MOBILEts    )  x = "object/botsc.txt";
    if ( type == OBJECT_MOBILEfs    )  x = "object/botsj.txt";
    if ( type == OBJECT_MOBILEis    )  x = "object/botss.txt";
    if ( type == OBJECT_MOBILEwi    )  x = "object/botor.txt";
    if ( type == OBJECT_MOBILEti    )  x = "object/botoc.txt";
    if ( type == OBJECT_MOBILEfi    )  x = "object/botoj.txt";
    if ( type == OBJECT_MOBILEii    )  x = "object/botos.txt";
    if ( type == OBJECT_MOBILEwc    )  x = "object/botfr.txt";
    if ( type == OBJECT_MOBILEtc    )  x = "object/botfc.txt";
    if ( type == OBJECT_MOBILEfc    )  x = "object/botfj.txt";
    if ( type == OBJECT_MOBILEic    )  x = "object/botfs.txt";
    if ( type == OBJECT_MOBILErt    )  x = "object/bottump.txt";
    if ( type == OBJECT_MOBILErc    )  x = "object/botphaz.txt";
    if ( type == OBJECT_MOBILErr    )  x = "object/botrecy.txt";
    if ( type == OBJECT_MOBILErs    )  x = "object/botshld.txt";
    if ( type == OBJECT_MOBILEsa    )  x = "object/botsub.txt";
    if ( type == OBJECT_MOBILEwt    )  x = "object/bottr.txt";
    if ( type == OBJECT_MOBILEtg    )  x = "object/bottarg.txt";
    if ( type == OBJECT_MOBILEdr    )  x = "object/botdraw.txt";
    if ( type == OBJECT_APOLLO2     )  x = "object/lrv.txt";
    if ( type == OBJECT_HUMAN       )  x = "object/human.txt";
    if ( type == OBJECT_MOTHER      )  x = "object/mother.txt";
    if ( type == OBJECT_EGG         )  x = "object/egg.txt";
    if ( type == OBJECT_ANT         )  x = "object/ant.txt";
    if ( type == OBJECT_SPIDER      )  x = "object/spider.txt";
    if ( type == OBJECT_BEE         )  x = "object/wasp.txt";
    if ( type == OBJECT_WORM        )  x = "object/worm.txt";
    if ( type->GetName() == "Ruin"  )  x = "object/ruin.txt";
    if ( type->GetName() == "Wreck" )  x = "object/wreck.txt";

    if(!x.empty())
        return std::string("help/") + CApplication::GetInstancePointer()->GetLanguageChar() + "/" + x;
    return "";
}


// Returns the help file to use for instruction.

std::string GetHelpFilename(const char *token)
{
    std::string x = "";
    if ( strcmp(token, "if"            ) == 0 )  x = "cbot/if.txt";
    if ( strcmp(token, "else"          ) == 0 )  x = "cbot/if.txt";
    if ( strcmp(token, "for"           ) == 0 )  x = "cbot/for.txt";
    if ( strcmp(token, "while"         ) == 0 )  x = "cbot/while.txt";
    if ( strcmp(token, "do"            ) == 0 )  x = "cbot/do.txt";
    if ( strcmp(token, "break"         ) == 0 )  x = "cbot/break.txt";
    if ( strcmp(token, "continue"      ) == 0 )  x = "cbot/continue.txt";
    if ( strcmp(token, "return"        ) == 0 )  x = "cbot/return.txt";
    if ( strcmp(token, "sizeof"        ) == 0 )  x = "cbot/sizeof.txt";
    if ( strcmp(token, "int"           ) == 0 )  x = "cbot/int.txt";
    if ( strcmp(token, "float"         ) == 0 )  x = "cbot/float.txt";
    if ( strcmp(token, "bool"          ) == 0 )  x = "cbot/bool.txt";
    if ( strcmp(token, "string"        ) == 0 )  x = "cbot/string.txt";
    if ( strcmp(token, "point"         ) == 0 )  x = "cbot/point.txt";
    if ( strcmp(token, "object"        ) == 0 )  x = "cbot/object.txt";
    if ( strcmp(token, "file"          ) == 0 )  x = "cbot/file.txt";
    if ( strcmp(token, "void"          ) == 0 )  x = "cbot/void.txt";
    if ( strcmp(token, "null"          ) == 0 )  x = "cbot/null.txt";
    if ( strcmp(token, "nan"           ) == 0 )  x = "cbot/nan.txt";
    if ( strcmp(token, "true"          ) == 0 )  x = "cbot/true.txt";
    if ( strcmp(token, "false"         ) == 0 )  x = "cbot/false.txt";
    if ( strcmp(token, "sin"           ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "cos"           ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "tan"           ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "asin"          ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "acos"          ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "atan"          ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "sqrt"          ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "pow"           ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "rand"          ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "abs"           ) == 0 )  x = "cbot/expr.txt";
    if ( strcmp(token, "getbuild"      ) == 0 )  x = "cbot/getbuild.txt";
    if ( strcmp(token, "getresearchenable" ) == 0 )  x = "cbot/getresen.txt";
    if ( strcmp(token, "getresearchdone"   ) == 0 )  x = "cbot/getresdo.txt";
    if ( strcmp(token, "retobject"     ) == 0 )  x = "cbot/retobj.txt";
    if ( strcmp(token, "errmode"       ) == 0 )  x = "cbot/errmode.txt";
    if ( strcmp(token, "progfunc"      ) == 0 )  x = "cbot/factory.txt";
    if ( strcmp(token, "busy"          ) == 0 )  x = "cbot/busy.txt";
    if ( strcmp(token, "takeoff"       ) == 0 )  x = "cbot/takeoff.txt";
    if ( strcmp(token, "research"      ) == 0 )  x = "cbot/research.txt";
    if ( strcmp(token, "factory"       ) == 0 )  x = "cbot/factory.txt";
    if ( strcmp(token, "destroy"       ) == 0 )  x = "cbot/destroy.txt";
    if ( strcmp(token, "search"        ) == 0 )  x = "cbot/search.txt";
    if ( strcmp(token, "radar"         ) == 0 )  x = "cbot/radar.txt";
    if ( strcmp(token, "direction"     ) == 0 )  x = "cbot/direct.txt";
    if ( strcmp(token, "distance"      ) == 0 )  x = "cbot/dist.txt";
    if ( strcmp(token, "distance2d"    ) == 0 )  x = "cbot/dist2d.txt";
    if ( strcmp(token, "space"         ) == 0 )  x = "cbot/space.txt";
    if ( strcmp(token, "flatground"    ) == 0 )  x = "cbot/flatgrnd.txt";
    if ( strcmp(token, "wait"          ) == 0 )  x = "cbot/wait.txt";
    if ( strcmp(token, "move"          ) == 0 )  x = "cbot/move.txt";
    if ( strcmp(token, "turn"          ) == 0 )  x = "cbot/turn.txt";
    if ( strcmp(token, "goto"          ) == 0 )  x = "cbot/goto.txt";
    if ( strcmp(token, "grab"          ) == 0 )  x = "cbot/grab.txt";
    if ( strcmp(token, "canbuild"      ) == 0 )  x = "cbot/canbuild.txt";
    if ( strcmp(token, "build"         ) == 0 )  x = "cbot/build.txt";
    if ( strcmp(token, "drop"          ) == 0 )  x = "cbot/drop.txt";
    if ( strcmp(token, "sniff"         ) == 0 )  x = "cbot/sniff.txt";
    if ( strcmp(token, "receive"       ) == 0 )  x = "cbot/receive.txt";
    if ( strcmp(token, "send"          ) == 0 )  x = "cbot/send.txt";
    if ( strcmp(token, "deleteinfo"    ) == 0 )  x = "cbot/delinfo.txt";
    if ( strcmp(token, "testinfo"      ) == 0 )  x = "cbot/testinfo.txt";
    if ( strcmp(token, "thump"         ) == 0 )  x = "cbot/thump.txt";
    if ( strcmp(token, "recycle"       ) == 0 )  x = "cbot/recycle.txt";
    if ( strcmp(token, "shield"        ) == 0 )  x = "cbot/shield.txt";
    if ( strcmp(token, "fire"          ) == 0 )  x = "cbot/fire.txt";
    if ( strcmp(token, "antfire"       ) == 0 )  x = "cbot/antfire.txt";
    if ( strcmp(token, "aim"           ) == 0 )  x = "cbot/aim.txt";
    if ( strcmp(token, "motor"         ) == 0 )  x = "cbot/motor.txt";
    if ( strcmp(token, "jet"           ) == 0 )  x = "cbot/jet.txt";
    if ( strcmp(token, "topo"          ) == 0 )  x = "cbot/topo.txt";
    if ( strcmp(token, "message"       ) == 0 )  x = "cbot/message.txt";
    if ( strcmp(token, "abstime"       ) == 0 )  x = "cbot/abstime.txt";
    if ( strcmp(token, "BlackArrow"    ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "RedArrow"      ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "White"         ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Black"         ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Gray"          ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "LightGray"     ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Red"           ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Pink"          ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Purple"        ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Orange"        ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Yellow"        ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Beige"         ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Brown"         ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Skin"          ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Green"         ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "LightGreen"    ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "Blue"          ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "LightBlue"     ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "InFront"       ) == 0 )  x = "cbot/grab.txt";
    if ( strcmp(token, "Behind"        ) == 0 )  x = "cbot/grab.txt";
    if ( strcmp(token, "EnergyCell"    ) == 0 )  x = "cbot/grab.txt";
    if ( strcmp(token, "DisplayError"  ) == 0 )  x = "cbot/message.txt";
    if ( strcmp(token, "DisplayWarning") == 0 )  x = "cbot/message.txt";
    if ( strcmp(token, "DisplayInfo"   ) == 0 )  x = "cbot/message.txt";
    if ( strcmp(token, "DisplayMessage") == 0 )  x = "cbot/message.txt";
    if ( strcmp(token, "strlen"        ) == 0 )  x = "cbot/string.txt";
    if ( strcmp(token, "strleft"       ) == 0 )  x = "cbot/string.txt";
    if ( strcmp(token, "strright"      ) == 0 )  x = "cbot/string.txt";
    if ( strcmp(token, "strmid"        ) == 0 )  x = "cbot/string.txt";
    if ( strcmp(token, "strval"        ) == 0 )  x = "cbot/string.txt";
    if ( strcmp(token, "strfind"       ) == 0 )  x = "cbot/string.txt";
    if ( strcmp(token, "strlower"      ) == 0 )  x = "cbot/string.txt";
    if ( strcmp(token, "strupper"      ) == 0 )  x = "cbot/string.txt";
    if ( strcmp(token, "open"          ) == 0 )  x = "cbot/open.txt";
    if ( strcmp(token, "close"         ) == 0 )  x = "cbot/close.txt";
    if ( strcmp(token, "writeln"       ) == 0 )  x = "cbot/writeln.txt";
    if ( strcmp(token, "readln "       ) == 0 )  x = "cbot/readln.txt";
    if ( strcmp(token, "eof"           ) == 0 )  x = "cbot/eof.txt";
    if ( strcmp(token, "deletefile"    ) == 0 )  x = "cbot/deletef.txt";
    if ( strcmp(token, "openfile"      ) == 0 )  x = "cbot/openfile.txt";
    if ( strcmp(token, "pendown"       ) == 0 )  x = "cbot/pendown.txt";
    if ( strcmp(token, "penup"         ) == 0 )  x = "cbot/penup.txt";
    if ( strcmp(token, "pencolor"      ) == 0 )  x = "cbot/pencolor.txt";
    if ( strcmp(token, "penwidth"      ) == 0 )  x = "cbot/penwidth.txt";
    if ( strcmp(token, "camerafocus"   ) == 0 )  x = "cbot/camerafocus.txt";
    if ( strcmp(token, "extern"        ) == 0 )  x = "cbot/extern.txt";
    if ( strcmp(token, "class"         ) == 0 )  x = "cbot/class.txt";
    if ( strcmp(token, "static"        ) == 0 )  x = "cbot/static.txt";
    if ( strcmp(token, "public"        ) == 0 )  x = "cbot/public.txt";
    if ( strcmp(token, "private"       ) == 0 )  x = "cbot/private.txt";
    if ( strcmp(token, "synchronized"  ) == 0 )  x = "cbot/synchro.txt";
    if ( strcmp(token, "new"           ) == 0 )  x = "cbot/new.txt";
    if ( strcmp(token, "this"          ) == 0 )  x = "cbot/this.txt";

    if(!x.empty())
        return std::string("help/") + CApplication::GetInstancePointer()->GetLanguageChar() + "/" + x;
    return "";
}


// Test if a keyword is a type of variable.

bool IsType(const char *token)
{
    if ( strcmp(token, "void"   ) == 0 )  return true;
    if ( strcmp(token, "int"    ) == 0 )  return true;
    if ( strcmp(token, "float"  ) == 0 )  return true;
    if ( strcmp(token, "bool"   ) == 0 )  return true;
    if ( strcmp(token, "string" ) == 0 )  return true;
    if ( strcmp(token, "point"  ) == 0 )  return true;
    if ( strcmp(token, "object" ) == 0 )  return true;
    if ( strcmp(token, "file"   ) == 0 )  return true;
    if ( strcmp(token, "this"   ) == 0 )  return true;
    return false;
}

// Test if a keyword is a function.

bool IsFunction(const char *token)
{
    if ( strcmp(token, "sin"          ) == 0 )  return true;
    if ( strcmp(token, "cos"          ) == 0 )  return true;
    if ( strcmp(token, "tan"          ) == 0 )  return true;
    if ( strcmp(token, "asin"         ) == 0 )  return true;
    if ( strcmp(token, "acos"         ) == 0 )  return true;
    if ( strcmp(token, "atan"         ) == 0 )  return true;
    if ( strcmp(token, "sqrt"         ) == 0 )  return true;
    if ( strcmp(token, "pow"          ) == 0 )  return true;
    if ( strcmp(token, "rand"         ) == 0 )  return true;
    if ( strcmp(token, "abs"          ) == 0 )  return true;
    if ( strcmp(token, "getbuild"     ) == 0 )  return true;
    if ( strcmp(token, "getresearchenable" ) == 0 )  return true;
    if ( strcmp(token, "getresearchdone"   ) == 0 )  return true;
    if ( strcmp(token, "retobjectbyid") == 0 )  return true;
    if ( strcmp(token, "retobject"    ) == 0 )  return true;
    if ( strcmp(token, "progfunc"     ) == 0 )  return true;
    if ( strcmp(token, "busy"         ) == 0 )  return true;
    if ( strcmp(token, "factory"      ) == 0 )  return true;
    if ( strcmp(token, "research"     ) == 0 )  return true;
    if ( strcmp(token, "takeoff"      ) == 0 )  return true;
    if ( strcmp(token, "destroy"      ) == 0 )  return true;
    if ( strcmp(token, "search"       ) == 0 )  return true;
    if ( strcmp(token, "radar"        ) == 0 )  return true;
    if ( strcmp(token, "detect"       ) == 0 )  return true;
    if ( strcmp(token, "direction"    ) == 0 )  return true;
    if ( strcmp(token, "distance"     ) == 0 )  return true;
    if ( strcmp(token, "distance2d"   ) == 0 )  return true;
    if ( strcmp(token, "space"        ) == 0 )  return true;
    if ( strcmp(token, "flatground"   ) == 0 )  return true;
    if ( strcmp(token, "wait"         ) == 0 )  return true;
    if ( strcmp(token, "move"         ) == 0 )  return true;
    if ( strcmp(token, "turn"         ) == 0 )  return true;
    if ( strcmp(token, "goto"         ) == 0 )  return true;
    if ( strcmp(token, "grab"         ) == 0 )  return true;
    if ( strcmp(token, "canbuild"     ) == 0 )  return true;
    if ( strcmp(token, "build"        ) == 0 )  return true;
    if ( strcmp(token, "drop"         ) == 0 )  return true;
    if ( strcmp(token, "sniff"        ) == 0 )  return true;
    if ( strcmp(token, "receive"      ) == 0 )  return true;
    if ( strcmp(token, "send"         ) == 0 )  return true;
    if ( strcmp(token, "deleteinfo"   ) == 0 )  return true;
    if ( strcmp(token, "testinfo"     ) == 0 )  return true;
    if ( strcmp(token, "thump"        ) == 0 )  return true;
    if ( strcmp(token, "recycle"      ) == 0 )  return true;
    if ( strcmp(token, "shield"       ) == 0 )  return true;
    if ( strcmp(token, "fire"         ) == 0 )  return true;
    if ( strcmp(token, "antfire"      ) == 0 )  return true;
    if ( strcmp(token, "aim"          ) == 0 )  return true;
    if ( strcmp(token, "motor"        ) == 0 )  return true;
    if ( strcmp(token, "jet"          ) == 0 )  return true;
    if ( strcmp(token, "topo"         ) == 0 )  return true;
    if ( strcmp(token, "message"      ) == 0 )  return true;
    if ( strcmp(token, "abstime"      ) == 0 )  return true;
    if ( strcmp(token, "ismovie"      ) == 0 )  return true;
    if ( strcmp(token, "errmode"      ) == 0 )  return true;
    if ( strcmp(token, "ipf"          ) == 0 )  return true;
    if ( strcmp(token, "strlen"       ) == 0 )  return true;
    if ( strcmp(token, "strleft"      ) == 0 )  return true;
    if ( strcmp(token, "strright"     ) == 0 )  return true;
    if ( strcmp(token, "strmid"       ) == 0 )  return true;
    if ( strcmp(token, "strval"       ) == 0 )  return true;
    if ( strcmp(token, "strfind"      ) == 0 )  return true;
    if ( strcmp(token, "strlower"     ) == 0 )  return true;
    if ( strcmp(token, "strupper"     ) == 0 )  return true;
    if ( strcmp(token, "open"         ) == 0 )  return true;
    if ( strcmp(token, "close"        ) == 0 )  return true;
    if ( strcmp(token, "writeln"      ) == 0 )  return true;
    if ( strcmp(token, "readln"       ) == 0 )  return true;
    if ( strcmp(token, "eof"          ) == 0 )  return true;
    if ( strcmp(token, "deletefile"   ) == 0 )  return true;
    if ( strcmp(token, "openfile"     ) == 0 )  return true;
    if ( strcmp(token, "pendown"      ) == 0 )  return true;
    if ( strcmp(token, "penup"        ) == 0 )  return true;
    if ( strcmp(token, "pencolor"     ) == 0 )  return true;
    if ( strcmp(token, "penwidth"     ) == 0 )  return true;
    if ( strcmp(token, "camerafocus"  ) == 0 )  return true;
    if ( strcmp(token, "sizeof"       ) == 0 )  return true;
    return false;
}


// Returns using a compact instruction.

const char* GetHelpText(const char *token)
{
    if ( strcmp(token, "if"        ) == 0 )  return "if ( condition ) { bloc }";
    if ( strcmp(token, "else"      ) == 0 )  return "else { bloc }";
    if ( strcmp(token, "for"       ) == 0 )  return "for ( before ; condition ; end )";
    if ( strcmp(token, "while"     ) == 0 )  return "while ( condition ) { bloc }";
    if ( strcmp(token, "do"        ) == 0 )  return "do { bloc } while ( condition );";
    if ( strcmp(token, "break"     ) == 0 )  return "break;";
    if ( strcmp(token, "continue"  ) == 0 )  return "continue;";
    if ( strcmp(token, "return"    ) == 0 )  return "return;";
    if ( strcmp(token, "sizeof"    ) == 0 )  return "sizeof( array );";
    if ( strcmp(token, "int"       ) == 0 )  return "int";
    if ( strcmp(token, "sin"       ) == 0 )  return "sin ( angle );";
    if ( strcmp(token, "cos"       ) == 0 )  return "cos ( angle );";
    if ( strcmp(token, "tan"       ) == 0 )  return "tan ( angle );";
    if ( strcmp(token, "asin"      ) == 0 )  return "asin ( value );";
    if ( strcmp(token, "acos"      ) == 0 )  return "acos ( value );";
    if ( strcmp(token, "atan"      ) == 0 )  return "atan ( value );";
    if ( strcmp(token, "sqrt"      ) == 0 )  return "sqrt ( value );";
    if ( strcmp(token, "pow"       ) == 0 )  return "pow ( x, y );";
    if ( strcmp(token, "rand"      ) == 0 )  return "rand ( );";
    if ( strcmp(token, "abs"       ) == 0 )  return "abs ( value );";
    if ( strcmp(token, "getbuild"  ) == 0 )  return "getbuild ( );";
    if ( strcmp(token, "getresearchenable" ) == 0 )  return "getresearchenable ( );";
    if ( strcmp(token, "getresearchdone" ) == 0 )  return "getresearchdone ( );";
    if ( strcmp(token, "retobject" ) == 0 )  return "retobject ( rank );";
    if ( strcmp(token, "retobjectbyid") == 0 )  return "retobjectbyid ( rank );";
    if ( strcmp(token, "progfunc"  ) == 0 )  return "progfunc ( funcname );";
    if ( strcmp(token, "busy"      ) == 0 )  return "object.busy ( );";
    if ( strcmp(token, "factory"   ) == 0 )  return "object.factory ( cat, program );";
    if ( strcmp(token, "research"  ) == 0 )  return "object.research ( type );";
    if ( strcmp(token, "takeoff"   ) == 0 )  return "object.takeoff ( );";
    if ( strcmp(token, "destroy"   ) == 0 )  return "object.destroy ( );";
    if ( strcmp(token, "search"    ) == 0 )  return "search ( );";
    if ( strcmp(token, "radar"     ) == 0 )  return "radar ( cat, angle, focus, min, max, sens );";
    if ( strcmp(token, "detect"    ) == 0 )  return "detect ( cat );";
    if ( strcmp(token, "direction" ) == 0 )  return "direction ( position );";
    if ( strcmp(token, "distance2d") == 0 )  return "distance2d ( p1, p2 );";
    if ( strcmp(token, "distance"  ) == 0 )  return "distance ( p1, p2 );";
    if ( strcmp(token, "space"     ) == 0 )  return "space ( center, rmin, rmax, dist );";
    if ( strcmp(token, "flatground") == 0 )  return "flatground ( center, rmax );";
    if ( strcmp(token, "wait"      ) == 0 )  return "wait ( time );";
    if ( strcmp(token, "move"      ) == 0 )  return "move ( distance );";
    if ( strcmp(token, "turn"      ) == 0 )  return "turn ( angle );";
    if ( strcmp(token, "goto"      ) == 0 )  return "goto ( position, altitude );";
    if ( strcmp(token, "grab"      ) == 0 )  return "grab ( order );";
    if ( strcmp(token, "canbuild"  ) == 0 )  return "canbuild ( category );";
    if ( strcmp(token, "build"     ) == 0 )  return "build ( category );";
    if ( strcmp(token, "drop"      ) == 0 )  return "drop ( order );";
    if ( strcmp(token, "sniff"     ) == 0 )  return "sniff ( );";
    if ( strcmp(token, "receive"   ) == 0 )  return "receive ( name, power );";
    if ( strcmp(token, "send"      ) == 0 )  return "send ( name, value, power );";
    if ( strcmp(token, "deleteinfo") == 0 )  return "deleteinfo ( name, power );";
    if ( strcmp(token, "testinfo"  ) == 0 )  return "testinfo ( name, power );";
    if ( strcmp(token, "thump"     ) == 0 )  return "thump ( );";
    if ( strcmp(token, "recycle"   ) == 0 )  return "recycle ( );";
    if ( strcmp(token, "shield"    ) == 0 )  return "shield ( oper, radius );";
    if ( strcmp(token, "fire"      ) == 0 )  return "fire ( time );";
    //if ( strcmp(token, "antfire"   ) == 0 )  return "antfire ( );";
    if ( strcmp(token, "aim"       ) == 0 )  return "aim ( x, y );";
    if ( strcmp(token, "motor"     ) == 0 )  return "motor ( left, right );";
    if ( strcmp(token, "jet"       ) == 0 )  return "jet ( power );";
    if ( strcmp(token, "topo"      ) == 0 )  return "topo ( position );";
    if ( strcmp(token, "message"   ) == 0 )  return "message ( string, type );";
    if ( strcmp(token, "abstime"   ) == 0 )  return "abstime ( );";
    if ( strcmp(token, "ismovie"   ) == 0 )  return "ismovie ( );";
    if ( strcmp(token, "errmode"   ) == 0 )  return "errmode ( mode );";
    if ( strcmp(token, "ipf"       ) == 0 )  return "ipf ( number );";
    if ( strcmp(token, "strlen"    ) == 0 )  return "strlen ( string );";
    if ( strcmp(token, "strleft"   ) == 0 )  return "strleft ( string, len );";
    if ( strcmp(token, "strright"  ) == 0 )  return "strright ( string, len );";
    if ( strcmp(token, "strmid"    ) == 0 )  return "strmid ( string, pos, len );";
    if ( strcmp(token, "strval"    ) == 0 )  return "strval ( string );";
    if ( strcmp(token, "strfind"   ) == 0 )  return "strfind ( string, substring );";
    if ( strcmp(token, "strlower"  ) == 0 )  return "strlower ( string );";
    if ( strcmp(token, "strupper"  ) == 0 )  return "strupper ( string );";
    if ( strcmp(token, "open"      ) == 0 )  return "open ( filename, mode );";
    if ( strcmp(token, "close"     ) == 0 )  return "close ( );";
    if ( strcmp(token, "writeln"   ) == 0 )  return "writeln ( string );";
    if ( strcmp(token, "readln"    ) == 0 )  return "readln ( );";
    if ( strcmp(token, "eof"       ) == 0 )  return "eof ( );";
    if ( strcmp(token, "deletefile") == 0 )  return "deletefile ( filename );";
    if ( strcmp(token, "openfile"  ) == 0 )  return "openfile ( filename, mode );";
    if ( strcmp(token, "pendown"   ) == 0 )  return "pendown ( color, width );";
    if ( strcmp(token, "penup"     ) == 0 )  return "penup ( );";
    if ( strcmp(token, "pencolor"  ) == 0 )  return "pencolor ( color );";
    if ( strcmp(token, "penwidth"  ) == 0 )  return "penwidth ( width );";
    if ( strcmp(token, "camerafocus") == 0 )  return "camerafocus ( object );";
    return "";
}

