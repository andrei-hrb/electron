#ifndef NEWPROJECTMENU_H
#define NEWPROJECTMENU_H

#include <graphics.h>
#include <winbgim.h>
#include <windows.h>

#include "Electronic Components/Electronics.h"
#include "UI/UI.h"
#include "Data Structures/Changes.h"
#include "Data Structures/Snapshot.h"

#include "Helper.h"
#include "Enums.h"

class NewProjectMenu
{
    public:
        NewProjectMenu();

        Button save, capacitors, diodes, logicGates, measurements, resistors, sources, switches, transistors, other, exit;
        Button rotate_l, rotate_r, flip_h, flip_v;
        Button undo, redo;
        Button inc, dec;
        Button box;

        Changes changes;
        Snapshot currentSnapshot;

        NameFile nameFileMenu;

        bool iscurrentSnapshotelected;
        ElectronicComponent selectedComponent;

        int window_code;
        std::string filepath;
        //boundaries
        double rl,rt,rr,rb;

        bool wiring = false;
        double lastCursorX = -1, lastCursorY = -1;

        void Show();
        void WatchClick();

        void drawWiresForComponent(std::string thisComponentCode, bool eraseMode);
        void implementChangeUndo();
        void implementChangeRedo();
};

#endif // NEWPROJECTMENU_H
