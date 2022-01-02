#include "UI/MainMenu.h"
#include "Helper.h"

#define BUTTON_HEIGHT 30

MainMenu::MainMenu()
{
}

void MainMenu::WatchClick()
{
    int ok = 1;

    clearmouseclick(WM_LBUTTONDOWN);
    while (ok)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            if (newProject.isCursorPointInButton())
            {
                NewProjectMenu newProjectMenu;
                newProjectMenu.Show();
                newProjectMenu.WatchClick();
            }
            else if (openProject.isCursorPointInButton())
            {
                // open project functionality
                std::cout << "open project ..." << std::endl;
            }
            else if (info.isCursorPointInButton())
            {
                InfoMenu infoMenu;
                infoMenu.Show();
                infoMenu.WatchClick();
            }
            else if (exit.isCursorPointInButton())
            {
                ok = 0;
            }
        }
        delay(200);
    }
    closegraph(this->window_code);
}

void MainMenu::Show()
{
    Helper helper;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int wc = initwindow(screenWidth/2, screenHeight/2, "", -3, -3);
    this->window_code = wc;
    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    newProject.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 - BUTTON_HEIGHT * 3));
    newProject.setWidth(210);
    newProject.setHeight(BUTTON_HEIGHT);
    newProject.setTitle("New Project");
    newProject.Show();

    openProject.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 - BUTTON_HEIGHT));
    openProject.setWidth(210);
    openProject.setHeight(BUTTON_HEIGHT);
    openProject.setTitle("Open Project");
    openProject.Show();

    info.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 + BUTTON_HEIGHT));
    info.setWidth(160);
    info.setHeight(BUTTON_HEIGHT);
    info.setTitle("Info");
    info.Show();

    exit.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 + BUTTON_HEIGHT * 3));
    exit.setWidth(160);
    exit.setHeight(BUTTON_HEIGHT);
    exit.setTitle("Exit");
    exit.Show();
}
