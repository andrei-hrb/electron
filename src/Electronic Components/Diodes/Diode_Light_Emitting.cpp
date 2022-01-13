#include "Electronic Components/Diodes/Diode_Light_Emitting.h"

Helper Diode_Light_Emitting_Helper;

Diode_Light_Emitting::Diode_Light_Emitting(): ElectronicComponent(200, 100, "Light Emitting Diode", 2) {}

//Drawing the component:
void Diode_Light_Emitting::Show()
{
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    double up_left_yz = up_left_y + height / 4;
    double center_yz = center_y + height / 8;

    Diode_Light_Emitting_Helper.rotationalCircle(
        up_left_x + thisHeight / 20, center_yz, getPositionCenter(), height / 20,
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        up_left_x + thisHeight / 10, center_yz, center_x - thisHeight / 4, center_yz, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x - thisHeight / 4, up_left_yz + height / 10, center_x - thisHeight / 4, down_right_y - height / 10, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x - thisHeight / 4, up_left_yz + height / 10, center_x + thisHeight / 4, center_yz, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x - thisHeight / 4, down_right_y - height / 10, center_x + thisHeight / 4, center_yz, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x + thisHeight / 4, up_left_yz + height / 10, center_x + thisHeight / 4, down_right_y - height / 10, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x, up_left_yz, center_x + thisHeight / 4, up_left_y, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x + thisHeight / 4, up_left_y, center_x + thisHeight / 6, up_left_y, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x + thisHeight / 4, up_left_y, center_x + thisHeight / 4, up_left_y + height / 12, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x + thisHeight / 10, up_left_yz + height / 10, center_x + 0.35 * thisHeight, up_left_y + height / 10, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x + 0.35 * thisHeight, up_left_y + height / 10, center_x + 4 * thisHeight / 15, up_left_y + height / 10, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x + 0.35 * thisHeight, up_left_y + height / 10, center_x + 0.35 * thisHeight, up_left_y + height / 12 + height / 10, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalLine(
        center_x + thisHeight / 4, center_yz, down_right_x - thisHeight / 10, center_yz, getPositionCenter(),
        rotateState);

    Diode_Light_Emitting_Helper.rotationalCircle(
        down_right_x - thisHeight / 20, center_yz, getPositionCenter(), height / 20,
        rotateState);
    showElements();
}

void Diode_Light_Emitting::updateConnectionPointsPosition()
{
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    double up_left_yz = up_left_y + height / 4;
    double center_yz = center_y + height / 8;

    connectionPoints[0].position = Diode_Light_Emitting_Helper.rotatePointToReference(
                                       Diode_Light_Emitting_Helper.makeVector_2D(up_left_x + thisHeight / 20, center_yz),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Diode_Light_Emitting_Helper.rotatePointToReference(
                                       Diode_Light_Emitting_Helper.makeVector_2D(down_right_x - thisHeight / 20, center_yz),
                                       getPositionCenter(),
                                       rotateState);
}
